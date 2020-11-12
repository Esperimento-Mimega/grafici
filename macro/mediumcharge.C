//Macro per la visualizzione della carica media registrata in tutto il run in esame per ciascuna strip

#include <TFile.h>
#include <TH1F.h>
#include <vector>
#include <TCut.h>
#include <TText.h>

void mediumcharge(TString filename){
  TFile *f = new TFile(filename, "read");
  TTree *tree = (TTree*)f->Get("TBtree");

  Int_t running_index=0;
  Int_t max_index=240;  //inserire numero di indici
  Double_t means[max_index];
  Double_t x[max_index];
  TCut index_selector;


  for(running_index; running_index<max_index; running_index++){
    index_selector=Form("hit_index==%i",running_index);
    TH1F* ch = new TH1F("ch","th",2000,0,2000);
    tree->Draw("hit_q>>ch", index_selector);
    means[running_index]=(ch->GetMean());
    x[running_index]=running_index;
    delete ch;
  }

  TGraph *gr = new TGraph(max_index, x, means);
  gr->SetFillColor(38);
  gr->SetTitle("Mean charge for strip;index number;mean charge");
  gr->Fit("pol0","R","",0,120);
  gr->Fit("pol0","R+","",120,240);
  //gr->Fit("pol0","R+","",240,360);  //terzo fit
  gr->Draw("AB");


}
