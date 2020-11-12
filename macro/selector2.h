//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Apr 25 10:36:44 2020 by ROOT version 6.20/04
// from TTree TBtree/TBtree
// found on file: run534_tbreco.root
//////////////////////////////////////////////////////////

#ifndef selector2_h
#define selector2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class selector2 : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run_number = {fReader, "run_number"};
   TTreeReaderValue<Int_t> event_number = {fReader, "event_number"};
   TTreeReaderArray<vector<double>> clusters_centroid_x = {fReader, "clusters_centroid_x"};
   TTreeReaderArray<vector<double>> clusters_centroid_ex = {fReader, "clusters_centroid_ex"};
   TTreeReaderArray<vector<double>> clusters_centroid_y = {fReader, "clusters_centroid_y"};
   TTreeReaderArray<vector<double>> clusters_centroid_ey = {fReader, "clusters_centroid_ey"};
   TTreeReaderArray<vector<double>> clusters_centroid_z = {fReader, "clusters_centroid_z"};
   TTreeReaderArray<vector<double>> clusters_centroid_ez = {fReader, "clusters_centroid_ez"};
   TTreeReaderArray<vector<double>> clusters_utpc_x = {fReader, "clusters_utpc_x"};
   TTreeReaderArray<vector<double>> clusters_utpc_ex = {fReader, "clusters_utpc_ex"};
   TTreeReaderArray<vector<double>> clusters_utpc_y = {fReader, "clusters_utpc_y"};
   TTreeReaderArray<vector<double>> clusters_utpc_ey = {fReader, "clusters_utpc_ey"};
   TTreeReaderArray<vector<double>> clusters_utpc_z = {fReader, "clusters_utpc_z"};
   TTreeReaderArray<vector<double>> clusters_utpc_ez = {fReader, "clusters_utpc_ez"};
   TTreeReaderArray<vector<double>> clusters_utpc_angle = {fReader, "clusters_utpc_angle"};
   TTreeReaderArray<vector<double>> clusters_utpc_pchi2 = {fReader, "clusters_utpc_pchi2"};
   TTreeReaderArray<vector<int>> clusters_nstrips = {fReader, "clusters_nstrips"};
   TTreeReaderArray<vector<int>> clusters_nholes = {fReader, "clusters_nholes"};
   TTreeReaderArray<vector<double>> clusters_totcharge = {fReader, "clusters_totcharge"};
   TTreeReaderArray<vector<bool>> clusters_issecondcoord = {fReader, "clusters_issecondcoord"};
   TTreeReaderArray<vector<bool>> clusters_ishoughcluster = {fReader, "clusters_ishoughcluster"};
   TTreeReaderArray<vector<bool>> clusters_hasutpcfit = {fReader, "clusters_hasutpcfit"};
   TTreeReaderArray<vector<vector<int> >> clusters_strips_indices = {fReader, "clusters_strips_indices"};
   TTreeReaderArray<vector<int>> hit_index = {fReader, "hit_index"};
   TTreeReaderArray<vector<bool>> hit_issecondcoord = {fReader, "hit_issecondcoord"};
   TTreeReaderArray<vector<double>> hit_q = {fReader, "hit_q"};
   TTreeReaderArray<vector<double>> hit_eq = {fReader, "hit_eq"};
   TTreeReaderArray<vector<double>> hit_x = {fReader, "hit_x"};
   TTreeReaderArray<vector<double>> hit_ex = {fReader, "hit_ex"};
   TTreeReaderArray<vector<double>> hit_y = {fReader, "hit_y"};
   TTreeReaderArray<vector<double>> hit_ey = {fReader, "hit_ey"};
   TTreeReaderArray<vector<double>> hit_z = {fReader, "hit_z"};
   TTreeReaderArray<vector<double>> hit_ez = {fReader, "hit_ez"};
   TTreeReaderArray<vector<double>> hit_t = {fReader, "hit_t"};
   TTreeReaderArray<vector<double>> hit_et = {fReader, "hit_et"};
   TTreeReaderArray<vector<int>> hit_nparent_clusters = {fReader, "hit_nparent_clusters"};
 


   selector2(TTree * /*tree*/ =0) { }
   virtual ~selector2() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(selector2,0);

};

#endif

#ifdef selector2_cxx
void selector2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t selector2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef selector2_cxx
