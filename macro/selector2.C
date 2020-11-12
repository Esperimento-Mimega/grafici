#define selector2_cxx
// The class definition in selector2.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("selector2.C")
// root> T->Process("selector2.C","some options")
// root> T->Process("selector2.C+")
//


#include "selector2.h"
#include <TTreeReaderArray.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

int run=623;                           //INSERIRE NUMERO RUN
vector<double> q, in, t;

double bkgcharge(int index){
  double bkgcharge=0;
  if(index<120){bkgcharge=600;}
  else if (index>=120 && index<240){bkgcharge=600;}    //INSERIRE SOGLIE BKG
  else{bkgcharge=1200;}
  return bkgcharge;
}

int n=0, ns=0;
double totcharge=0;
double wpos=0;
TFile *selfile = new TFile(Form("recoevents_%i.root", run),"RECREATE");
TTree *mytree = new TTree("reco","reconstructed events");



void selector2::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();


}

void selector2::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

	/* if( !selfile->IsOpen() ) {
		 std::cout << "problems creating root file. existing... " << std::endl;
		 exit(-1);
	}*/

	mytree->Branch("charge", &q);
	mytree->Branch("index", &in);
	mytree->Branch("time", &t);
	mytree->Branch("event_number", &n);
	mytree->Branch("n_strips", &ns);
  mytree->Branch("tot_charge", &totcharge);
  mytree->Branch("w_pos", &wpos);

}

Bool_t selector2::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   //definiamo i puntatori alle variabili (charge_, index_, time_)
 
	TTreeReaderArray<std::vector<double, std::allocator<double> > >::iterator charge_1=hit_q.begin();
	std::vector<double>::const_iterator charge_=charge_1->begin();

	TTreeReaderArray<std::vector<int, std::allocator<int> > >::iterator index_1=hit_index.begin();
	std::vector<int>::const_iterator index_=index_1->begin();

	TTreeReaderArray<std::vector<double, std::allocator<double> > >::iterator time_1=hit_t.begin();
	std::vector<double>::const_iterator time_=time_1->begin();

	std::vector<double>::const_iterator q_mu;
	std::vector<int>::const_iterator i_mu;
	std::vector<double>::const_iterator t_mu;

	while(charge_!=charge_1->end()){


		if ((*time_)>0 && (*charge_)>1400 && (*charge_)>(*(charge_+1)) && (*charge_)>(*(charge_-1))){
			q_mu=charge_;
			i_mu=index_;
			t_mu=time_;
			n++;

      double bc=bkgcharge(*i_mu);
	    for(std::vector<double>::const_iterator i=charge_-1; abs(*(t_mu-1)-(*time_))<40 && (*i)>bc; i--){
				q_mu--;
				i_mu--;
				t_mu--;
			}

			while((*q_mu)>bc && q_mu!=(charge_1->end()) && abs((*t_mu)-(*time_))<40 ){

	    			if( (*t_mu)>0){
	    				q.push_back (*q_mu);
	    				in.push_back(*i_mu);
	    				t.push_back(*t_mu);
              wpos+=(*q_mu)*(*i_mu);
              totcharge+=(*q_mu);
	    				ns++;
	    			}

	    			q_mu++;
	   			  i_mu++;
	    			t_mu++;
	    }

      wpos=wpos/totcharge;
      mytree->Fill();
			q.clear();
			in.clear();
			t.clear();
			ns=0;
      totcharge=0;
      wpos=0;

			charge_=q_mu;
	    index_=i_mu;
	   	time_=t_mu;


		}

		if(charge_==(charge_1->end())){break; } 

		charge_++;
		index_++;
		time_++;
	}

return kTRUE;
}

void selector2::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
}

void selector2::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
   mytree->Write();
   selfile->Close();

}
