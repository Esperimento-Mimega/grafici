

#include <TFile.h>
#include <TH1F.h>
#include <iostream>

void historeco(TString filename){

  TFile *f1 = new TFile(filename, "read");
  TTree *tree = (TTree*)f1->Get("TBtree");

  //get run number
  TH1F *runh =new TH1F("runh","runh",1,0,700); //-------700=max run number
  tree->Draw("run_number>>runh");
  int run=(int)runh->GetMean();
  
  tree->Process("selector2.C");

  TFile *f2 = new TFile(Form("recoevents_%i.root", run), "read");
  TTree *cleantree = (TTree*)f2->Get("reco");

  TH1F *histowpos = new TH1F("histowpos","Centroid spacial distribution",100,0,250);//-----max strip
  histowpos->GetXaxis()->SetTitle("index");
  histowpos->GetYaxis()->SetTitle("counts");
  histowpos->SetFillColor(kBlue);
  cleantree->Draw("w_pos>>histowpos");

  TH1F *histocharge = new TH1F("histocharge","Cluster charge spectrum",30,0,40000);
  histocharge->GetXaxis()->SetTitle("charge (ADC counts)");
  histocharge->GetYaxis()->SetTitle("counts");
  histocharge->SetFillColor(kBlue);
  cleantree->Draw("tot_charge>>histocharge");

  TH1F *histonstrip = new TH1F("histonstrip","Number of strips in cluster",36,0,35);
  histonstrip->GetXaxis()->SetTitle("number of strip");
  histonstrip->GetYaxis()->SetTitle("counts");
  histonstrip->SetFillColor(kBlue);
  cleantree->Draw("n_strips>>histonstrip");

 
  TCanvas *ca = new TCanvas("ca",filename,2000,600);
  ca->Divide(3);
  ca->cd(1);
  histowpos->Draw();
  ca->cd(2);
  histocharge->Draw();
  ca->cd(3);
  histonstrip->Draw();

  TFile *file = new TFile(Form("histo_%i.root", run), "RECREATE");
  histowpos->Write();
  histocharge->Write();
  histonstrip->Write();
  ca->Write();
  file->Close();

}
