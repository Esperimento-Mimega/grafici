#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <THistPainter.h>
#include <TAxis.h>



	//APRIAMO I FILE--------------------

	TFile *run617 = new TFile("run617_tbreco.root","read");
	TFile *run619 = new TFile("run619_tbreco.root","read");
	TFile *run623 = new TFile("run623_tbreco.root","read");
	TFile *run630 = new TFile("run630_tbreco.root","read");

	TTree *tree630 = (TTree*)run630->Get("TBtree");
	TTree *tree617 = (TTree*)run617->Get("TBtree");
	TTree *tree619 = (TTree*)run619->Get("TBtree");
	TTree *tree623 = (TTree*)run623->Get("TBtree");


void nclusters(){

	//NCLUSTERS-----------------------------------------------

	//get data

	TH1F* nclusters630 = (TH1F*)run630->Get("Tmm1/nclusters");
	TH1F* nclusters617 = (TH1F*)run617->Get("Tmm1/nclusters");
	TH1F* nclusters619 = (TH1F*)run619->Get("Tmm1/nclusters");
	TH1F* nclusters623 = (TH1F*)run623->Get("Tmm1/nclusters");

	nclusters630->SetNameTitle("540V","540V");
	nclusters617->SetNameTitle("560V","560V");
	nclusters619->SetNameTitle("570V","570V");
	nclusters623->SetNameTitle("580V","580V");


	//Style
	nclusters617->SetLineColor(kBlue);
	nclusters619->SetLineColor(kRed);
	nclusters623->SetLineColor(kGreen);
	nclusters630->SetLineColor(kMagenta);

	nclusters617->SetFillColor(kBlue);
	nclusters619->SetFillColor(kRed);
	nclusters623->SetFillColor(kGreen);
	nclusters630->SetFillColor(kMagenta);

	nclusters617->GetXaxis()->SetTitle("number of clusters");
	nclusters617->GetYaxis()->SetTitle("normalized entries");
	nclusters619->GetXaxis()->SetTitle("number of clusters");
	nclusters619->GetYaxis()->SetTitle("normalized entries");
	nclusters623->GetXaxis()->SetTitle("number of clusters");
	nclusters623->GetYaxis()->SetTitle("normalized entries");
	nclusters630->GetXaxis()->SetTitle("number of clusters");
	nclusters630->GetYaxis()->SetTitle("normalized entries");

	nclusters617->GetXaxis()->SetRangeUser(0, 4);
	nclusters619->GetXaxis()->SetRangeUser(0, 4);
	nclusters623->GetXaxis()->SetRangeUser(0, 4);
	nclusters630->GetXaxis()->SetRangeUser(0, 4);


	//canvas
	TCanvas *nclucan = new TCanvas("nclucan","nclusters canvas",200,10,1280,720);
	nclucan->Divide(2,2,0.01,0.01);

	//Draw
	nclucan->cd(1);
	nclusters630->DrawNormalized("hist");
	nclucan->Update();
	nclucan->cd(2);
	nclusters617->DrawNormalized("hist");
	nclucan->Update();
	nclucan->cd(3);
	nclusters619->DrawNormalized("hist");
	nclucan->Update();
	nclucan->cd(4);
	nclusters623->DrawNormalized("hist");
	nclucan->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	nclucan->SaveAs("nclucan.png");
}

void nstrips(){

  //NSTRIPS------------------------------------------

  //CREA I TH1F

  TH1F *nstrips630 = new TH1F("nstrips630","540V", 20,0,20);
  TH1F *nstrips617 = new TH1F("nstrips617","560V", 20,0,20);
  TH1F *nstrips619 = new TH1F("nstrips619","570V", 20,0,20);
  TH1F *nstrips623 = new TH1F("nstrips623","580V", 20,0,20);

  //riempi i TH1F

  tree630->Draw("clusters_nstrips>>nstrips630");
  tree617->Draw("clusters_nstrips>>nstrips617");
  tree619->Draw("clusters_nstrips>>nstrips619");
  tree623->Draw("clusters_nstrips>>nstrips623");


  //Style
  nstrips617->SetLineColor(kBlue);
  nstrips619->SetLineColor(kRed);
  nstrips623->SetLineColor(kGreen);
  nstrips630->SetLineColor(kMagenta);

  nstrips617->SetFillColor(kBlue);
  nstrips619->SetFillColor(kRed);
  nstrips623->SetFillColor(kGreen);
  nstrips630->SetFillColor(kMagenta);


 	nstrips617->GetXaxis()->SetTitle("number of fired strips");
	nstrips617->GetYaxis()->SetTitle("normalized entries");
	nstrips619->GetXaxis()->SetTitle("number of fired strips");
	nstrips619->GetYaxis()->SetTitle("normalized entries");
	nstrips623->GetXaxis()->SetTitle("number of fired strips");
	nstrips623->GetYaxis()->SetTitle("normalized entries");
	nstrips630->GetXaxis()->SetTitle("number of fired strips");
	nstrips630->GetYaxis()->SetTitle("normalized entries");

  //canvas
  TCanvas *stripcan = new TCanvas("stripcan","nstrips canvas",200,10,1280,720);
  stripcan->Divide(2,2,0.01,0.01);

  //Draw
  stripcan->cd(1);
  nstrips630->DrawNormalized("hist");
  stripcan->Update();
  stripcan->cd(2);
  nstrips617->DrawNormalized("hist");
  stripcan->Update();
  stripcan->cd(3);
  nstrips619->DrawNormalized("hist");
  stripcan->Update();
  stripcan->cd(4);
  nstrips623->DrawNormalized("hist");
  stripcan->Update();

  //SAVE CANVAS AS PNG----------------------------------------
  stripcan->SaveAs("stripcan.png");
}


void nholes(){

	//NHOLES------------------------------------------


	//CREA I TH1F

	TH1F *nholes630 = new TH1F("nholes630","540V", 3,0,3);
	TH1F *nholes617 = new TH1F("nholes617","560V", 3,0,3);
	TH1F *nholes619 = new TH1F("nholes619","570V", 3,0,3);
	TH1F *nholes623 = new TH1F("nholes623","580V", 3,0,3);

	//riempi i TH1F

	tree630->Draw("clusters_nholes>>nholes630");
	tree617->Draw("clusters_nholes>>nholes617");
	tree619->Draw("clusters_nholes>>nholes619");
	tree623->Draw("clusters_nholes>>nholes623");


	//Style
	nholes617->SetLineColor(kBlue);
	nholes619->SetLineColor(kRed);
	nholes623->SetLineColor(kGreen);
	nholes630->SetLineColor(kMagenta);

	nholes617->SetFillColor(kBlue);
	nholes619->SetFillColor(kRed);
	nholes623->SetFillColor(kGreen);
	nholes630->SetFillColor(kMagenta);

	nholes617->GetXaxis()->SetTitle("number of holes");
	nholes617->GetYaxis()->SetTitle("normalized entries");
	nholes619->GetXaxis()->SetTitle("number of holes");
	nholes619->GetYaxis()->SetTitle("normalized entries");
	nholes623->GetXaxis()->SetTitle("number of holes");
	nholes623->GetYaxis()->SetTitle("normalized entries");
	nholes630->GetXaxis()->SetTitle("number of holes");
	nholes630->GetYaxis()->SetTitle("normalized entries");

	//canvas
	TCanvas *holescan = new TCanvas("holescan","holes in a cluster",200,10,1280,720);

	holescan->Divide(2,2,0.01,0.01);

	//Draw
	holescan->cd(1);
	nholes630->DrawNormalized("hist");
	holescan->Update();
	holescan->cd(2);
	nholes617->DrawNormalized("hist");
	holescan->Update();
	holescan->cd(3);
	nholes619->DrawNormalized("hist");
	holescan->Update();
	holescan->cd(4);
	nholes623->DrawNormalized("hist");
	holescan->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	holescan->SaveAs("holescan.png");
 }

 void clucharge(){

 	//CLUSTER CHARGE------------------------------------------

	//crea i TH1F

	TH1F *clucharge630 = new TH1F("clucharge630","540V", 100,0,6000);
	TH1F *clucharge617 = new TH1F("clucharge617","560V", 100,0,20000);
	TH1F *clucharge619 = new TH1F("clucharge619","570V", 100,0,25000);
	TH1F *clucharge623 = new TH1F("clucharge623","580V", 100,0,40000);

	//riempi i TH1F

	tree630->Draw("clusters_totcharge>>clucharge630");
	tree617->Draw("clusters_totcharge>>clucharge617");
	tree619->Draw("clusters_totcharge>>clucharge619");
	tree623->Draw("clusters_totcharge>>clucharge623");

	//Style
	clucharge617->SetLineColor(kBlue);
	clucharge619->SetLineColor(kRed);
	clucharge623->SetLineColor(kGreen);
	clucharge630->SetLineColor(kMagenta);

	clucharge617->SetFillColor(kBlue);
	clucharge619->SetFillColor(kRed);
	clucharge623->SetFillColor(kGreen);
	clucharge630->SetFillColor(kMagenta);

	clucharge617->GetXaxis()->SetTitle("cluster charge");
	clucharge617->GetYaxis()->SetTitle("normalized entries");
	clucharge619->GetXaxis()->SetTitle("cluster charge");
	clucharge619->GetYaxis()->SetTitle("normalized entries");
	clucharge623->GetXaxis()->SetTitle("cluster charge");
	clucharge623->GetYaxis()->SetTitle("normalized entries");
	clucharge630->GetXaxis()->SetTitle("cluster charge");
	clucharge630->GetYaxis()->SetTitle("normalized entries");

	//canvas
	TCanvas *cccanvas = new TCanvas("cccanvas","cluster charge",200,10,1280,720);
	cccanvas->Divide(2,2,0.01,0.01);

	//Draw
	cccanvas->cd(1);
	clucharge630->DrawNormalized("hist");
	cccanvas->Update();
	cccanvas->cd(2);
	clucharge617->DrawNormalized("hist");
	cccanvas->Update();
	cccanvas->cd(3);
	clucharge619->DrawNormalized("hist");
	cccanvas->Update();
	cccanvas->cd(4);
	clucharge623->DrawNormalized("hist");
	cccanvas->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	cccanvas->SaveAs("cccanvas.png");
}


void stripcharge(){

	//STRIP IN CLUSTER CHARGE------------------------------------------

	TH1F* stripcharge617 = (TH1F*)run617->Get("Tmm1/strip_in_cluster_charge");
	TH1F* stripcharge619 = (TH1F*)run619->Get("Tmm1/strip_in_cluster_charge");
	TH1F* stripcharge623 = (TH1F*)run623->Get("Tmm1/strip_in_cluster_charge");
	TH1F* stripcharge630 = (TH1F*)run630->Get("Tmm1/strip_in_cluster_charge");

	stripcharge619->SetNameTitle("570V","570V");
	stripcharge623->SetNameTitle("580V","580V");
	stripcharge630->SetNameTitle("540V","540V");
	stripcharge617->SetNameTitle("560V","560V");

	//Style
	stripcharge617->SetLineColor(kBlue);
	stripcharge619->SetLineColor(kRed);
	stripcharge623->SetLineColor(kGreen);
	stripcharge630->SetLineColor(kMagenta);

	stripcharge617->SetFillColor(kBlue);
	stripcharge619->SetFillColor(kRed);
	stripcharge623->SetFillColor(kGreen);
	stripcharge630->SetFillColor(kMagenta);

	stripcharge617->GetXaxis()->SetTitle("strip charge");
	stripcharge617->GetYaxis()->SetTitle("normalized entries");
	stripcharge619->GetXaxis()->SetTitle("strip charge");
	stripcharge619->GetYaxis()->SetTitle("normalized entries");
	stripcharge623->GetXaxis()->SetTitle("strip charge");
	stripcharge623->GetYaxis()->SetTitle("normalized entries");
	stripcharge630->GetXaxis()->SetTitle("strip charge");
	stripcharge630->GetYaxis()->SetTitle("normalized entries");

	stripcharge617->Rebin(2);
	stripcharge619->Rebin(2);
	stripcharge623->Rebin(2);
	stripcharge630->Rebin(2);

	stripcharge617->GetXaxis()->SetRangeUser(0, 2000);
	stripcharge619->GetXaxis()->SetRangeUser(0, 2000);
	stripcharge623->GetXaxis()->SetRangeUser(0, 2000);
	stripcharge630->GetXaxis()->SetRangeUser(0, 2000);




	//canvas
	TCanvas *stripcharge = new TCanvas("stripcharge","strip charge canvas",200,10,1280,720);
	stripcharge->Divide(2,2,0.01,0.01);

	//Draw
	stripcharge->cd(1);
	stripcharge630->DrawNormalized("hist");
	stripcharge->Update();
	stripcharge->cd(2);
	stripcharge617->DrawNormalized("hist");
	stripcharge->Update();
	stripcharge->cd(3);
	stripcharge619->DrawNormalized("hist");
	stripcharge->Update();
	stripcharge->cd(4);
	stripcharge623->DrawNormalized("hist");
	stripcharge->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	stripcharge->SaveAs("stripcharge.png");
}


void index(){

	//STRIP INDEX------------------------------------------


	//crea i TH1F

	TH1F *index630 = new TH1F("index630","540V", 100,0,60);
	TH1F *index617 = new TH1F("index617","560V", 100,0,60);
	TH1F *index619 = new TH1F("index619","570V", 100,0,60);
	TH1F *index623 = new TH1F("index623","580V", 100,0,60);

	//riempi i TH1F

	tree630->Draw("clusters_centroid_x>>index630");
	tree617->Draw("clusters_centroid_x>>index617");
	tree619->Draw("clusters_centroid_x>>index619");
	tree623->Draw("clusters_centroid_x>>index623");

	//Style
	index617->SetLineColor(kBlue);
	index619->SetLineColor(kRed);
	index623->SetLineColor(kGreen);
	index630->SetLineColor(kMagenta);

	index617->SetFillColor(kBlue);
	index619->SetFillColor(kRed);
	index623->SetFillColor(kGreen);
	index630->SetFillColor(kMagenta);

	index617->GetXaxis()->SetTitle("strip position");
	index617->GetYaxis()->SetTitle("entries");
	index619->GetXaxis()->SetTitle("strip position");
	index619->GetYaxis()->SetTitle("entries");
	index623->GetXaxis()->SetTitle("strip position");
	index623->GetYaxis()->SetTitle("entries");
	index630->GetXaxis()->SetTitle("strip position");
	index630->GetYaxis()->SetTitle("entries");


	//canvas
	TCanvas *index = new TCanvas("index","index distribution",200,10,1280,720);
	index->Divide(2,2,0.01,0.01);


	//Draw
	index->cd(1);
	index630->Draw("hist");
	index->Update();
	index->cd(2);
	index617->Draw("hist");
	index->Update();
	index->cd(3);
	index619->Draw("hist");
	index->Update();
	index->cd(4);
	index623->Draw("hist");
	index->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	index->SaveAs("index.png");
}

void graph(){

	std::cout<<"\nPossibili comandi: \n\n-nclusters() \n-nstrips()\n-nholes\n-clucharge()\n-stripcharge()\n-index()\n\n";

	}

void all(){

	nclusters();
	nstrips();
	nholes();
	clucharge();
	stripcharge();
	index();
}

void angles(){

	//ANGLES------------------------------------------

	TH1F* angle617 = (TH1F*)run630->Get("Tmm1/utpc_angle");

	angle617->SetNameTitle("horizontal","horizontal");

	//Style
	angle617->SetLineColor(kBlue);


	angle617->SetFillColor(kBlue);

	angle617->GetXaxis()->SetTitle("reconstructed angle (degree)");
	angle617->GetYaxis()->SetTitle("entries");
	angle617->Rebin(4);

	angle617->GetXaxis()->SetRangeUser(0, 100);

	//canvas
	TCanvas *angle = new TCanvas("angle","angles canvas",200,10,1280,720);
	//angle->Divide(2,1,0.01,0.01);

	//Draw
	angle617->Draw("hist");
	angle->Update();

	//SAVE CANVAS AS PNG----------------------------------------

 	angle->SaveAs("angle.png");

}
