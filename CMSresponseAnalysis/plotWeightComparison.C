#include <iostream>
 
using namespace std;

//This script plots the the difference in MPF response and pT-balance in normal sample
//and in the sample where additional weights are applied to events with B-hadrons  
void plotWeightComparison() {

  //flags for different plotting options
  bool plot_mpf = 1;
  bool plot_pTbal = 0;

  bool zoom_y_axis = 1;
  bool smaller_markers = 1;

  string n_events = "100000";
  string OpenName = "output_ROOT_files/CMSJES_P8_Zjet_" + n_events + ".root";
  string OpenName_w = "output_ROOT_files/CMSJES_P8_Zjet_" + n_events + "_BhadWeight.root";

  if (plot_mpf) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_w = TFile::Open(OpenName_w.c_str());

		TProfile *przj_MPF;                TProfile *przj_MPF_B0;              TProfile *przj_MPF_Bp;                         
		TProfile *przj_MPFc;               TProfile *przj_MPFc_B0;             TProfile *przj_MPFc_Bp;     
		TProfile *przj_MPFs;               TProfile *przj_MPFs_B0;             TProfile *przj_MPFs_Bp;
		TProfile *przj_MPFud;              TProfile *przj_MPFud_B0;            TProfile *przj_MPFud_Bp;
		TProfile *przj_MPFg;               TProfile *przj_MPFg_B0;             TProfile *przj_MPFg_Bp;  
		TProfile *przj_MPFb_non_slep;      TProfile *przj_MPFb_non_slep_B0;    TProfile *przj_MPFb_non_slep_Bp;
		TProfile *przj_MPFb_slep;          TProfile *przj_MPFb_slep_B0;        TProfile *przj_MPFb_slep_Bp;

		TProfile *przj_MPF_B0s;            TProfile *przj_MPF_Bb;              TProfile *przj_MPF_nonB;                         
		TProfile *przj_MPFc_B0s;           TProfile *przj_MPFc_Bb;             TProfile *przj_MPFc_nonB;     
		TProfile *przj_MPFs_B0s;           TProfile *przj_MPFs_Bb;             TProfile *przj_MPFs_nonB;
		TProfile *przj_MPFud_B0s;          TProfile *przj_MPFud_Bb;            TProfile *przj_MPFud_nonB;
		TProfile *przj_MPFg_B0s;           TProfile *przj_MPFg_Bb;             TProfile *przj_MPFg_nonB;  
		TProfile *przj_MPFb_non_slep_B0s;  TProfile *przj_MPFb_non_slep_Bb;    TProfile *przj_MPFb_non_slep_nonB;
		TProfile *przj_MPFb_slep_B0s;      TProfile *przj_MPFb_slep_Bb;        TProfile *przj_MPFb_slep_nonB;

	  //The sample with the additional weighting (*_w)
		TProfile *przj_MPF_w;                TProfile *przj_MPF_B0_w;              TProfile *przj_MPF_Bp_w;                         
		TProfile *przj_MPFc_w;               TProfile *przj_MPFc_B0_w;             TProfile *przj_MPFc_Bp_w;     
		TProfile *przj_MPFs_w;               TProfile *przj_MPFs_B0_w;             TProfile *przj_MPFs_Bp_w;
		TProfile *przj_MPFud_w;              TProfile *przj_MPFud_B0_w;            TProfile *przj_MPFud_Bp_w;
		TProfile *przj_MPFg_w;               TProfile *przj_MPFg_B0_w;             TProfile *przj_MPFg_Bp_w;  
		TProfile *przj_MPFb_non_slep_w;      TProfile *przj_MPFb_non_slep_B0_w;    TProfile *przj_MPFb_non_slep_Bp_w;
		TProfile *przj_MPFb_slep_w;          TProfile *przj_MPFb_slep_B0_w;        TProfile *przj_MPFb_slep_Bp_w;

		TProfile *przj_MPF_B0s_w;            TProfile *przj_MPF_Bb_w;              TProfile *przj_MPF_nonB_w;                         
		TProfile *przj_MPFc_B0s_w;           TProfile *przj_MPFc_Bb_w;             TProfile *przj_MPFc_nonB_w;     
		TProfile *przj_MPFs_B0s_w;           TProfile *przj_MPFs_Bb_w;             TProfile *przj_MPFs_nonB_w;
		TProfile *przj_MPFud_B0s_w;          TProfile *przj_MPFud_Bb_w;            TProfile *przj_MPFud_nonB_w;
		TProfile *przj_MPFg_B0s_w;           TProfile *przj_MPFg_Bb_w;             TProfile *przj_MPFg_nonB_w;  
		TProfile *przj_MPFb_non_slep_B0s_w;  TProfile *przj_MPFb_non_slep_Bb_w;    TProfile *przj_MPFb_non_slep_nonB_w;
		TProfile *przj_MPFb_slep_B0s_w;      TProfile *przj_MPFb_slep_Bb_w;        TProfile *przj_MPFb_slep_nonB_w;

	  // Read the normal sample
	  fzj->GetObject("prMPF",   przj_MPF);
	  fzj->GetObject("prMPFb_non_slep",  przj_MPFb_non_slep);
	  fzj->GetObject("prMPFb_slep",  przj_MPFb_slep);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Get the event weights		
	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  fzj->GetObject("prMPFb_non_slep_B0",  przj_MPFb_non_slep_B0);
	  fzj->GetObject("prMPFb_slep_B0",  przj_MPFb_slep_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  fzj->GetObject("prMPFb_non_slep_Bp",  przj_MPFb_non_slep_Bp);
	  fzj->GetObject("prMPFb_slep_Bp",  przj_MPFb_slep_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  fzj->GetObject("prMPFb_non_slep_B0s",  przj_MPFb_non_slep_B0s);
	  fzj->GetObject("prMPFb_slep_B0s",  przj_MPFb_slep_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  fzj->GetObject("prMPFb_non_slep_Bb",  przj_MPFb_non_slep_Bb);
	  fzj->GetObject("prMPFb_slep_Bb",  przj_MPFb_slep_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  fzj->GetObject("prMPFb_non_slep_nonB",  przj_MPFb_non_slep_nonB);
	  fzj->GetObject("prMPFb_slep_nonB",  przj_MPFb_slep_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);

    //Read the weighted sample
	  fzj_w->GetObject("prMPF",   przj_MPF_w);
	  fzj_w->GetObject("prMPFb_non_slep",  przj_MPFb_non_slep_w);
	  fzj_w->GetObject("prMPFb_slep",  przj_MPFb_slep_w);
	  fzj_w->GetObject("prMPFc",  przj_MPFc_w);
	  fzj_w->GetObject("prMPFs",  przj_MPFs_w);
	  fzj_w->GetObject("prMPFud", przj_MPFud_w);
	  fzj_w->GetObject("prMPFg",  przj_MPFg_w);

	  //Get the event weights		
	  fzj_w->GetObject("prMPF_B0",   przj_MPF_B0_w);
	  fzj_w->GetObject("prMPFb_non_slep_B0",  przj_MPFb_non_slep_B0_w);
	  fzj_w->GetObject("prMPFb_slep_B0",  przj_MPFb_slep_B0_w);
	  fzj_w->GetObject("prMPFc_B0",  przj_MPFc_B0_w);
	  fzj_w->GetObject("prMPFs_B0",  przj_MPFs_B0_w);
	  fzj_w->GetObject("prMPFud_B0", przj_MPFud_B0_w);
	  fzj_w->GetObject("prMPFg_B0",  przj_MPFg_B0_w);

	  fzj_w->GetObject("prMPF_Bp",   przj_MPF_Bp_w);
	  fzj_w->GetObject("prMPFb_non_slep_Bp",  przj_MPFb_non_slep_Bp_w);
	  fzj_w->GetObject("prMPFb_slep_Bp",  przj_MPFb_slep_Bp_w);
	  fzj_w->GetObject("prMPFc_Bp",  przj_MPFc_Bp_w);
	  fzj_w->GetObject("prMPFs_Bp",  przj_MPFs_Bp_w);
	  fzj_w->GetObject("prMPFud_Bp", przj_MPFud_Bp_w);
	  fzj_w->GetObject("prMPFg_Bp",  przj_MPFg_Bp_w);

	  fzj_w->GetObject("prMPF_B0s",   przj_MPF_B0s_w);
	  fzj_w->GetObject("prMPFb_non_slep_B0s",  przj_MPFb_non_slep_B0s_w);
	  fzj_w->GetObject("prMPFb_slep_B0s",  przj_MPFb_slep_B0s_w);
	  fzj_w->GetObject("prMPFc_B0s",  przj_MPFc_B0s_w);
	  fzj_w->GetObject("prMPFs_B0s",  przj_MPFs_B0s_w);
	  fzj_w->GetObject("prMPFud_B0s", przj_MPFud_B0s_w);
	  fzj_w->GetObject("prMPFg_B0s",  przj_MPFg_B0s_w);

	  fzj_w->GetObject("prMPF_Bb",   przj_MPF_Bb_w);
	  fzj_w->GetObject("prMPFb_non_slep_Bb",  przj_MPFb_non_slep_Bb_w);
	  fzj_w->GetObject("prMPFb_slep_Bb",  przj_MPFb_slep_Bb_w);
	  fzj_w->GetObject("prMPFc_Bb",  przj_MPFc_Bb_w);
	  fzj_w->GetObject("prMPFs_Bb",  przj_MPFs_Bb_w);
	  fzj_w->GetObject("prMPFud_Bb", przj_MPFud_Bb_w);
	  fzj_w->GetObject("prMPFg_Bb",  przj_MPFg_Bb_w);

	  fzj_w->GetObject("prMPF_nonB",   przj_MPF_nonB_w);
	  fzj_w->GetObject("prMPFb_non_slep_nonB",  przj_MPFb_non_slep_nonB_w);
	  fzj_w->GetObject("prMPFb_slep_nonB",  przj_MPFb_slep_nonB_w);
	  fzj_w->GetObject("prMPFc_nonB",  przj_MPFc_nonB_w);
	  fzj_w->GetObject("prMPFs_nonB",  przj_MPFs_nonB_w);
	  fzj_w->GetObject("prMPFud_nonB", przj_MPFud_nonB_w);
	  fzj_w->GetObject("prMPFg_nonB",  przj_MPFg_nonB_w);

	  TH1D* hzj_MPF   = przj_MPF  ->ProjectionX();
	  TH1D* hzj_MPFb_non_slep  = przj_MPFb_non_slep ->ProjectionX();
	  TH1D* hzj_MPFb_slep  = przj_MPFb_slep ->ProjectionX();
	  TH1D* hzj_MPFc  = przj_MPFc ->ProjectionX();
	  TH1D* hzj_MPFs  = przj_MPFs ->ProjectionX();
	  TH1D* hzj_MPFud = przj_MPFud->ProjectionX();
	  TH1D* hzj_MPFg  = przj_MPFg ->ProjectionX();

	  TH1D* hzj_MPF_w   = przj_MPF_w  ->ProjectionX();
	  TH1D* hzj_MPFb_non_slep_w  = przj_MPFb_non_slep_w ->ProjectionX();
	  TH1D* hzj_MPFb_slep_w  = przj_MPFb_slep_w ->ProjectionX();
	  TH1D* hzj_MPFc_w  = przj_MPFc_w ->ProjectionX();
	  TH1D* hzj_MPFs_w  = przj_MPFs_w ->ProjectionX();
	  TH1D* hzj_MPFud_w = przj_MPFud_w->ProjectionX();
	  TH1D* hzj_MPFg_w  = przj_MPFg_w ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_MPF->Clone();
	  TH1D* diffb_non_slep = (TH1D*) hzj_MPFb_non_slep->Clone();
	  TH1D* diffb_slep = (TH1D*) hzj_MPFb_slep->Clone();
	  TH1D* diffc = (TH1D*) hzj_MPFc->Clone();
	  TH1D* diffs = (TH1D*) hzj_MPFs->Clone();
	  TH1D* diffud = (TH1D*) hzj_MPFud->Clone();
	  TH1D* diffg = (TH1D*) hzj_MPFg->Clone();

	  //Calculate the difference between the weighted and the normal sample
	  diff->Add(hzj_MPF_w,-1);
	  diffb_non_slep->Add(hzj_MPFb_non_slep_w,-1);
	  diffb_slep->Add(hzj_MPFb_slep_w,-1);
	  diffc->Add(hzj_MPFc_w,-1);
	  diffs->Add(hzj_MPFs_w,-1);
	  diffud->Add(hzj_MPFud_w,-1);
	  diffg->Add(hzj_MPFg_w,-1);

		//evtW_* = event weight, sem_* = standard error of the mean,   
  	double error;  		double errorb; 			double errorb_slep; double errorb_non_slep; 
	  double errorg; 		double errorud;   	double errors; 			double errorc;

	  double sem_B0; 		double sem_Bp; 			double sem_B0s; 		double sem_Bb;  				double sem_nonB;

	  double evtW_B0; 	double evtW_Bp; 		double evtW_B0s; 		double evtW_Bb; 				double evtW_nonB;
	  double evtW_B0_w; double evtW_Bp_w; 	double evtW_B0s_w; 	double evtW_Bb_w;       double evtW_nonB_w;
	  double evtW_tot;  double evtW_tot_w;

	  //Loop over the TProfile bins
	  for (int i = 1; i < (przj_MPF_B0->GetNbinsX() + 1); i++){
			//All jets
			//Get the event weights		
			evtW_B0 = przj_MPF_B0->GetBinEntries(i);
			evtW_Bp = przj_MPF_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPF_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPF_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPF_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPF_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPF_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPF_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPF_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPF_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPF_B0->GetBinError(i);
			sem_Bp = przj_MPF_Bp->GetBinError(i);
			sem_B0s = przj_MPF_B0s->GetBinError(i);
			sem_Bb = przj_MPF_Bb->GetBinError(i);
			sem_nonB = przj_MPF_nonB->GetBinError(i);
	 
			//The error given by the error propagation
	    error = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
							pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
							pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
							pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
							pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//b-jet semileptonic
			//Get the event weights
			evtW_B0 = przj_MPFb_slep_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFb_slep_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFb_slep_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFb_slep_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFb_slep_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFb_slep_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFb_slep_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFb_slep_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFb_slep_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFb_slep_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFb_slep_B0->GetBinError(i);
			sem_Bp = przj_MPFb_slep_Bp->GetBinError(i);
			sem_B0s = przj_MPFb_slep_B0s->GetBinError(i);
			sem_Bb = przj_MPFb_slep_Bb->GetBinError(i);
			sem_nonB = przj_MPFb_slep_nonB->GetBinError(i);

			//The error given by the error propagation
	    errorb_slep = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
										pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
										pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
										pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
										pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//b-jet non-semileptonic
			//Get the event weights
			evtW_B0 = przj_MPFb_non_slep_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFb_non_slep_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFb_non_slep_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFb_non_slep_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFb_non_slep_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFb_non_slep_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFb_non_slep_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFb_non_slep_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFb_non_slep_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFb_non_slep_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFb_non_slep_B0->GetBinError(i);
			sem_Bp = przj_MPFb_non_slep_Bp->GetBinError(i);
			sem_B0s = przj_MPFb_non_slep_B0s->GetBinError(i);
			sem_Bb = przj_MPFb_non_slep_Bb->GetBinError(i);
			sem_nonB = przj_MPFb_non_slep_nonB->GetBinError(i);
 
			//The error given by the error propagation
	    errorb_non_slep = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
												pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
												pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
												pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
												pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//g-jet
			//Get the event weights
			evtW_B0 = przj_MPFg_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFg_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFg_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFg_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFg_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFg_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFg_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFg_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFg_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFg_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFg_B0->GetBinError(i);
			sem_Bp = przj_MPFg_Bp->GetBinError(i);
			sem_B0s = przj_MPFg_B0s->GetBinError(i);
			sem_Bb = przj_MPFg_Bb->GetBinError(i);
			sem_nonB = przj_MPFg_nonB->GetBinError(i);
 
			//The error given by the error propagation
	    errorg = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//ud-jet
			//Get the event weights
			evtW_B0 = przj_MPFud_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFud_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFud_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFud_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFud_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFud_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFud_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFud_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFud_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFud_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFud_B0->GetBinError(i);
			sem_Bp = przj_MPFud_Bp->GetBinError(i);
			sem_B0s = przj_MPFud_B0s->GetBinError(i);
			sem_Bb = przj_MPFud_Bb->GetBinError(i);
			sem_nonB = przj_MPFud_nonB->GetBinError(i);
 
			//The error given by the error propagation
	    errorud = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//s-jet
			evtW_B0 = przj_MPFs_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFs_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFs_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFs_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFs_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFs_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFs_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFs_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFs_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFs_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFs_B0->GetBinError(i);
			sem_Bp = przj_MPFs_Bp->GetBinError(i);
			sem_B0s = przj_MPFs_B0s->GetBinError(i);
			sem_Bb = przj_MPFs_Bb->GetBinError(i);
			sem_nonB = przj_MPFs_nonB->GetBinError(i);
 
			//The error given by the error propagation
	    errors = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//c-jet
			//Get the event weights
			evtW_B0 = przj_MPFc_B0->GetBinEntries(i);
			evtW_Bp = przj_MPFc_Bp->GetBinEntries(i);
			evtW_B0s = przj_MPFc_B0s->GetBinEntries(i);
			evtW_Bb = przj_MPFc_Bb->GetBinEntries(i);
			evtW_nonB = przj_MPFc_nonB->GetBinEntries(i);

			evtW_B0_w = przj_MPFc_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_MPFc_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_MPFc_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_MPFc_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_MPFc_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_MPFc_B0->GetBinError(i);
			sem_Bp = przj_MPFc_Bp->GetBinError(i);
			sem_B0s = przj_MPFc_B0s->GetBinError(i);
			sem_Bb = przj_MPFc_Bb->GetBinError(i);
			sem_nonB = przj_MPFc_nonB->GetBinError(i);

			//The error given by the error propagation 
	    errorc = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//Root won't plot empty bins so replace empty bins with very small number
			if (diff->GetBinContent(i) == 0) 					  diff->SetBinContent(i,1e-6);
			if (diffb_slep->GetBinContent(i) == 0) 		  diffb_slep->SetBinContent(i,1e-6);
			if (diffb_non_slep->GetBinContent(i) == 0)  diffb_non_slep->SetBinContent(i,1e-6);
			if (diffg->GetBinContent(i) == 0) 				  diffg->SetBinContent(i,1e-6);
			if (diffud->GetBinContent(i) == 0) 				  diffud->SetBinContent(i,1e-6);
			if (diffs->GetBinContent(i) == 0) 				  diffs->SetBinContent(i,1e-6);
			if (diffc->GetBinContent(i) == 0) 				  diffc->SetBinContent(i,1e-6);

			//Set the new bin errors
			diff->SetBinError(i,error);
			diffb_slep->SetBinError(i,errorb_slep);
			diffb_non_slep->SetBinError(i,errorb_non_slep);
			diffg->SetBinError(i,errorg);
			diffud->SetBinError(i,errorud);
			diffs->SetBinError(i,errors);
			diffc->SetBinError(i,errorc);
		
	  }

		//Scale to the percentages
	  diff->Scale(100.0);
	  diffb_non_slep->Scale(100.0);
	  diffb_slep->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_MPF = new TCanvas("MPF","",500,400);
	  canv_MPF->SetLeftMargin(0.13);
	  canv_MPF->SetBottomMargin(0.13);
	  canv_MPF->SetLogx();

	  diff  ->SetMarkerStyle(kOpenCircle);      		diff  ->SetMarkerColor(kBlack);
	  diffb_non_slep ->SetMarkerStyle(kFullCircle); diffb_non_slep ->SetMarkerColor(kRed+1);
	  diffb_slep ->SetMarkerStyle(kOpenCircle);     diffb_slep ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      		diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     			diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   		diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); 		diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  diffb_non_slep ->SetLineColor(kRed+1);
	  diffb_slep ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  if (smaller_markers) {
	  	diff  ->SetMarkerSize(0.3);              
	  	diffb_non_slep ->SetMarkerSize(0.3);
	  	diffb_slep ->SetMarkerSize(0.3);
	  	diffc ->SetMarkerSize(0.3);             
	  	diffs->SetMarkerSize(0.3);
	  	diffud ->SetMarkerSize(0.3);            
	  	diffg ->SetMarkerSize(0.3);
	  }

	  //Legend
	  TLegend* lz_MPF = new TLegend(0.37,0.17,0.64,0.39);
	  if (zoom_y_axis) lz_MPF = new TLegend(0.37,0.65,0.64,0.89);		

	  lz_MPF->SetBorderSize(0);
	  lz_MPF->AddEntry(diff,   "All",   "p");
	  lz_MPF->AddEntry(diffb_non_slep,  "b (non-semileptonic)",     "p");
	  lz_MPF->AddEntry(diffb_slep,  "b (semileptonic)",     "p");
	  lz_MPF->AddEntry(diffc,  "c",     "p");
	  lz_MPF->AddEntry(diffs,  "s",     "p");
	  lz_MPF->AddEntry(diffud, "ud",    "p");
	  lz_MPF->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  diff->GetXaxis()->SetMoreLogLabels();
	  diff->GetXaxis()->SetNoExponent();
	  diff->GetYaxis()->SetTitleOffset(1.1);
	  diff->GetXaxis()->SetTitleOffset(1.1);
	  diff->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
	  diff->GetYaxis()->SetTitle("R_{MPF} - R_{MPF,scaled} (%)");
	  diff->GetYaxis()->SetTitleSize(0.05);
	  diff->GetXaxis()->SetTitleSize(0.05);

	  gPad->SetTickx();   gPad->SetTicky();

	  //Plot
	  diff->Draw("p");
	  diffb_non_slep->Draw("PSAME");
	  diffb_slep->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_MPF->Draw();

    diff->SetMaximum(0.9);
    diff->SetMinimum(-0.9);

	  if (zoom_y_axis) {
			diff->SetMaximum(0.4);
	  	diff->SetMinimum(-0.15);
	  }

	  string amount;

	  if (n_events == "3000") amount = "3k";
	  if (n_events == "30000") amount = "30k";
	  if (n_events == "100000") amount = "100k";
	  if (n_events == "1000000") amount = "1M";
	  if (n_events == "5000000") amount = "5M";
	  
    string plotName;
		
	  if (zoom_y_axis) plotName = "plots/weightedPlots/diff_plots/zoom_" + amount; 
		else plotName = "plots/weightedPlots/diff_plots/" + amount;

    plotName += "_diff_MPF.pdf";	//Filetype suffix

	  //Save plot
	  canv_MPF->Print(plotName.c_str()); delete canv_MPF;
  } 

  if (plot_pTbal) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_w = TFile::Open(OpenName_w.c_str());

		TProfile *przj_pTb;                TProfile *przj_pTb_B0;              TProfile *przj_pTb_Bp;                         
		TProfile *przj_pTbc;               TProfile *przj_pTbc_B0;             TProfile *przj_pTbc_Bp;     
		TProfile *przj_pTbs;               TProfile *przj_pTbs_B0;             TProfile *przj_pTbs_Bp;
		TProfile *przj_pTbud;              TProfile *przj_pTbud_B0;            TProfile *przj_pTbud_Bp;
		TProfile *przj_pTbg;               TProfile *przj_pTbg_B0;             TProfile *przj_pTbg_Bp;  
		TProfile *przj_pTbb_non_slep;      TProfile *przj_pTbb_non_slep_B0;    TProfile *przj_pTbb_non_slep_Bp;
		TProfile *przj_pTbb_slep;          TProfile *przj_pTbb_slep_B0;        TProfile *przj_pTbb_slep_Bp;

		TProfile *przj_pTb_B0s;            TProfile *przj_pTb_Bb;              TProfile *przj_pTb_nonB;                         
		TProfile *przj_pTbc_B0s;           TProfile *przj_pTbc_Bb;             TProfile *przj_pTbc_nonB;     
		TProfile *przj_pTbs_B0s;           TProfile *przj_pTbs_Bb;             TProfile *przj_pTbs_nonB;
		TProfile *przj_pTbud_B0s;          TProfile *przj_pTbud_Bb;            TProfile *przj_pTbud_nonB;
		TProfile *przj_pTbg_B0s;           TProfile *przj_pTbg_Bb;             TProfile *przj_pTbg_nonB;  
		TProfile *przj_pTbb_non_slep_B0s;  TProfile *przj_pTbb_non_slep_Bb;    TProfile *przj_pTbb_non_slep_nonB;
		TProfile *przj_pTbb_slep_B0s;      TProfile *przj_pTbb_slep_Bb;        TProfile *przj_pTbb_slep_nonB;

	  //The sample with the additional weighting (*_w)
		TProfile *przj_pTb_w;                TProfile *przj_pTb_B0_w;              TProfile *przj_pTb_Bp_w;                         
		TProfile *przj_pTbc_w;               TProfile *przj_pTbc_B0_w;             TProfile *przj_pTbc_Bp_w;     
		TProfile *przj_pTbs_w;               TProfile *przj_pTbs_B0_w;             TProfile *przj_pTbs_Bp_w;
		TProfile *przj_pTbud_w;              TProfile *przj_pTbud_B0_w;            TProfile *przj_pTbud_Bp_w;
		TProfile *przj_pTbg_w;               TProfile *przj_pTbg_B0_w;             TProfile *przj_pTbg_Bp_w;  
		TProfile *przj_pTbb_non_slep_w;      TProfile *przj_pTbb_non_slep_B0_w;    TProfile *przj_pTbb_non_slep_Bp_w;
		TProfile *przj_pTbb_slep_w;          TProfile *przj_pTbb_slep_B0_w;        TProfile *przj_pTbb_slep_Bp_w;

		TProfile *przj_pTb_B0s_w;            TProfile *przj_pTb_Bb_w;              TProfile *przj_pTb_nonB_w;                         
		TProfile *przj_pTbc_B0s_w;           TProfile *przj_pTbc_Bb_w;             TProfile *przj_pTbc_nonB_w;     
		TProfile *przj_pTbs_B0s_w;           TProfile *przj_pTbs_Bb_w;             TProfile *przj_pTbs_nonB_w;
		TProfile *przj_pTbud_B0s_w;          TProfile *przj_pTbud_Bb_w;            TProfile *przj_pTbud_nonB_w;
		TProfile *przj_pTbg_B0s_w;           TProfile *przj_pTbg_Bb_w;             TProfile *przj_pTbg_nonB_w;  
		TProfile *przj_pTbb_non_slep_B0s_w;  TProfile *przj_pTbb_non_slep_Bb_w;    TProfile *przj_pTbb_non_slep_nonB_w;
		TProfile *przj_pTbb_slep_B0s_w;      TProfile *przj_pTbb_slep_Bb_w;        TProfile *przj_pTbb_slep_nonB_w;

	  // Read the normal sample
	  fzj->GetObject("prpTbal",   przj_pTb);
	  fzj->GetObject("prpTbalb_non_slep",  przj_pTbb_non_slep);
	  fzj->GetObject("prpTbalb_slep",  przj_pTbb_slep);
	  fzj->GetObject("prpTbalc",  przj_pTbc);
	  fzj->GetObject("prpTbals",  przj_pTbs);
	  fzj->GetObject("prpTbalud", przj_pTbud);
	  fzj->GetObject("prpTbalg",  przj_pTbg);

	  //Get the event weights		
	  fzj->GetObject("prpTbal_B0",   przj_pTb_B0);
	  fzj->GetObject("prpTbalb_non_slep_B0",  przj_pTbb_non_slep_B0);
	  fzj->GetObject("prpTbalb_slep_B0",  przj_pTbb_slep_B0);
	  fzj->GetObject("prpTbalc_B0",  przj_pTbc_B0);
	  fzj->GetObject("prpTbals_B0",  przj_pTbs_B0);
	  fzj->GetObject("prpTbalud_B0", przj_pTbud_B0);
	  fzj->GetObject("prpTbalg_B0",  przj_pTbg_B0);

	  fzj->GetObject("prpTbal_Bp",   przj_pTb_Bp);
	  fzj->GetObject("prpTbalb_non_slep_Bp",  przj_pTbb_non_slep_Bp);
	  fzj->GetObject("prpTbalb_slep_Bp",  przj_pTbb_slep_Bp);
	  fzj->GetObject("prpTbalc_Bp",  przj_pTbc_Bp);
	  fzj->GetObject("prpTbals_Bp",  przj_pTbs_Bp);
	  fzj->GetObject("prpTbalud_Bp", przj_pTbud_Bp);
	  fzj->GetObject("prpTbalg_Bp",  przj_pTbg_Bp);

	  fzj->GetObject("prpTbal_B0s",   przj_pTb_B0s);
	  fzj->GetObject("prpTbalb_non_slep_B0s",  przj_pTbb_non_slep_B0s);
	  fzj->GetObject("prpTbalb_slep_B0s",  przj_pTbb_slep_B0s);
	  fzj->GetObject("prpTbalc_B0s",  przj_pTbc_B0s);
	  fzj->GetObject("prpTbals_B0s",  przj_pTbs_B0s);
	  fzj->GetObject("prpTbalud_B0s", przj_pTbud_B0s);
	  fzj->GetObject("prpTbalg_B0s",  przj_pTbg_B0s);

	  fzj->GetObject("prpTbal_Bb",   przj_pTb_Bb);
	  fzj->GetObject("prpTbalb_non_slep_Bb",  przj_pTbb_non_slep_Bb);
	  fzj->GetObject("prpTbalb_slep_Bb",  przj_pTbb_slep_Bb);
	  fzj->GetObject("prpTbalc_Bb",  przj_pTbc_Bb);
	  fzj->GetObject("prpTbals_Bb",  przj_pTbs_Bb);
	  fzj->GetObject("prpTbalud_Bb", przj_pTbud_Bb);
	  fzj->GetObject("prpTbalg_Bb",  przj_pTbg_Bb);

	  fzj->GetObject("prpTbal_nonB",   przj_pTb_nonB);
	  fzj->GetObject("prpTbalb_non_slep_nonB",  przj_pTbb_non_slep_nonB);
	  fzj->GetObject("prpTbalb_slep_nonB",  przj_pTbb_slep_nonB);
	  fzj->GetObject("prpTbalc_nonB",  przj_pTbc_nonB);
	  fzj->GetObject("prpTbals_nonB",  przj_pTbs_nonB);
	  fzj->GetObject("prpTbalud_nonB", przj_pTbud_nonB);
	  fzj->GetObject("prpTbalg_nonB",  przj_pTbg_nonB);

    //Read the weighted sample
	  fzj_w->GetObject("prpTbal",   przj_pTb_w);
	  fzj_w->GetObject("prpTbalb_non_slep",  przj_pTbb_non_slep_w);
	  fzj_w->GetObject("prpTbalb_slep",  przj_pTbb_slep_w);
	  fzj_w->GetObject("prpTbalc",  przj_pTbc_w);
	  fzj_w->GetObject("prpTbals",  przj_pTbs_w);
	  fzj_w->GetObject("prpTbalud", przj_pTbud_w);
	  fzj_w->GetObject("prpTbalg",  przj_pTbg_w);

	  //Get the event weights		
	  fzj_w->GetObject("prpTbal_B0",   przj_pTb_B0_w);
	  fzj_w->GetObject("prpTbalb_non_slep_B0",  przj_pTbb_non_slep_B0_w);
	  fzj_w->GetObject("prpTbalb_slep_B0",  przj_pTbb_slep_B0_w);
	  fzj_w->GetObject("prpTbalc_B0",  przj_pTbc_B0_w);
	  fzj_w->GetObject("prpTbals_B0",  przj_pTbs_B0_w);
	  fzj_w->GetObject("prpTbalud_B0", przj_pTbud_B0_w);
	  fzj_w->GetObject("prpTbalg_B0",  przj_pTbg_B0_w);

	  fzj_w->GetObject("prpTbal_Bp",   przj_pTb_Bp_w);
	  fzj_w->GetObject("prpTbalb_non_slep_Bp",  przj_pTbb_non_slep_Bp_w);
	  fzj_w->GetObject("prpTbalb_slep_Bp",  przj_pTbb_slep_Bp_w);
	  fzj_w->GetObject("prpTbalc_Bp",  przj_pTbc_Bp_w);
	  fzj_w->GetObject("prpTbals_Bp",  przj_pTbs_Bp_w);
	  fzj_w->GetObject("prpTbalud_Bp", przj_pTbud_Bp_w);
	  fzj_w->GetObject("prpTbalg_Bp",  przj_pTbg_Bp_w);

	  fzj_w->GetObject("prpTbal_B0s",   przj_pTb_B0s_w);
	  fzj_w->GetObject("prpTbalb_non_slep_B0s",  przj_pTbb_non_slep_B0s_w);
	  fzj_w->GetObject("prpTbalb_slep_B0s",  przj_pTbb_slep_B0s_w);
	  fzj_w->GetObject("prpTbalc_B0s",  przj_pTbc_B0s_w);
	  fzj_w->GetObject("prpTbals_B0s",  przj_pTbs_B0s_w);
	  fzj_w->GetObject("prpTbalud_B0s", przj_pTbud_B0s_w);
	  fzj_w->GetObject("prpTbalg_B0s",  przj_pTbg_B0s_w);

	  fzj_w->GetObject("prpTbal_Bb",   przj_pTb_Bb_w);
	  fzj_w->GetObject("prpTbalb_non_slep_Bb",  przj_pTbb_non_slep_Bb_w);
	  fzj_w->GetObject("prpTbalb_slep_Bb",  przj_pTbb_slep_Bb_w);
	  fzj_w->GetObject("prpTbalc_Bb",  przj_pTbc_Bb_w);
	  fzj_w->GetObject("prpTbals_Bb",  przj_pTbs_Bb_w);
	  fzj_w->GetObject("prpTbalud_Bb", przj_pTbud_Bb_w);
	  fzj_w->GetObject("prpTbalg_Bb",  przj_pTbg_Bb_w);

	  fzj_w->GetObject("prpTbal_nonB",   przj_pTb_nonB_w);
	  fzj_w->GetObject("prpTbalb_non_slep_nonB",  przj_pTbb_non_slep_nonB_w);
	  fzj_w->GetObject("prpTbalb_slep_nonB",  przj_pTbb_slep_nonB_w);
	  fzj_w->GetObject("prpTbalc_nonB",  przj_pTbc_nonB_w);
	  fzj_w->GetObject("prpTbals_nonB",  przj_pTbs_nonB_w);
	  fzj_w->GetObject("prpTbalud_nonB", przj_pTbud_nonB_w);
	  fzj_w->GetObject("prpTbalg_nonB",  przj_pTbg_nonB_w);

	  TH1D* hzj_pTb   = przj_pTb  ->ProjectionX();
	  TH1D* hzj_pTbb_non_slep  = przj_pTbb_non_slep ->ProjectionX();
	  TH1D* hzj_pTbb_slep  = przj_pTbb_slep ->ProjectionX();
	  TH1D* hzj_pTbc  = przj_pTbc ->ProjectionX();
	  TH1D* hzj_pTbs  = przj_pTbs ->ProjectionX();
	  TH1D* hzj_pTbud = przj_pTbud->ProjectionX();
	  TH1D* hzj_pTbg  = przj_pTbg ->ProjectionX();

	  TH1D* hzj_pTb_w   = przj_pTb_w  ->ProjectionX();
	  TH1D* hzj_pTbb_non_slep_w  = przj_pTbb_non_slep_w ->ProjectionX();
	  TH1D* hzj_pTbb_slep_w  = przj_pTbb_slep_w ->ProjectionX();
	  TH1D* hzj_pTbc_w  = przj_pTbc_w ->ProjectionX();
	  TH1D* hzj_pTbs_w  = przj_pTbs_w ->ProjectionX();
	  TH1D* hzj_pTbud_w = przj_pTbud_w->ProjectionX();
	  TH1D* hzj_pTbg_w  = przj_pTbg_w ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_pTb->Clone();
	  TH1D* diffb_non_slep = (TH1D*) hzj_pTbb_non_slep->Clone();
	  TH1D* diffb_slep = (TH1D*) hzj_pTbb_slep->Clone();
	  TH1D* diffc = (TH1D*) hzj_pTbc->Clone();
	  TH1D* diffs = (TH1D*) hzj_pTbs->Clone();
	  TH1D* diffud = (TH1D*) hzj_pTbud->Clone();
	  TH1D* diffg = (TH1D*) hzj_pTbg->Clone();

	  //Calculate the difference between the weighted and the normal sample
	  diff->Add(hzj_pTb_w,-1);
	  diffb_non_slep->Add(hzj_pTbb_non_slep_w,-1);
	  diffb_slep->Add(hzj_pTbb_slep_w,-1);
	  diffc->Add(hzj_pTbc_w,-1);
	  diffs->Add(hzj_pTbs_w,-1);
	  diffud->Add(hzj_pTbud_w,-1);
	  diffg->Add(hzj_pTbg_w,-1);

		//evtW_* = event weight, sem_* = standard error of the mean,   
  	double error;  		double errorb; 			double errorb_slep; double errorb_non_slep; 
	  double errorg; 		double errorud;   	double errors; 			double errorc;

	  double sem_B0; 		double sem_Bp; 			double sem_B0s; 		double sem_Bb;  				double sem_nonB;

	  double evtW_B0; 	double evtW_Bp; 		double evtW_B0s; 		double evtW_Bb; 				double evtW_nonB;
	  double evtW_B0_w; double evtW_Bp_w; 	double evtW_B0s_w; 	double evtW_Bb_w;       double evtW_nonB_w;
	  double evtW_tot;  double evtW_tot_w;

	  //Loop over the TProfile bins
	  for (int i = 1; i < (przj_pTb_B0->GetNbinsX() + 1); i++){
			//All jets
			//Get the event weights		
			evtW_B0 = przj_pTb_B0->GetBinEntries(i);
			evtW_Bp = przj_pTb_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTb_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTb_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTb_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTb_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTb_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTb_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTb_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTb_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTb_B0->GetBinError(i);
			sem_Bp = przj_pTb_Bp->GetBinError(i);
			sem_B0s = przj_pTb_B0s->GetBinError(i);
			sem_Bb = przj_pTb_Bb->GetBinError(i);
			sem_nonB = przj_pTb_nonB->GetBinError(i);
	 
		  error = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
							pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
							pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
							pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
							pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//b-jet semileptonic
			//Get the event weights		
			evtW_B0 = przj_pTbb_slep_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbb_slep_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbb_slep_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbb_slep_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbb_slep_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbb_slep_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbb_slep_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbb_slep_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbb_slep_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbb_slep_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbb_slep_B0->GetBinError(i);
			sem_Bp = przj_pTbb_slep_Bp->GetBinError(i);
			sem_B0s = przj_pTbb_slep_B0s->GetBinError(i);
			sem_Bb = przj_pTbb_slep_Bb->GetBinError(i);
			sem_nonB = przj_pTbb_slep_nonB->GetBinError(i);
	 
		  errorb_slep = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
										pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
										pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
										pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
										pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//b-jet non-semileptonic
			//Get the event weights		
			evtW_B0 = przj_pTbb_non_slep_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbb_non_slep_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbb_non_slep_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbb_non_slep_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbb_non_slep_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbb_non_slep_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbb_non_slep_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbb_non_slep_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbb_non_slep_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbb_non_slep_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbb_non_slep_B0->GetBinError(i);
			sem_Bp = przj_pTbb_non_slep_Bp->GetBinError(i);
			sem_B0s = przj_pTbb_non_slep_B0s->GetBinError(i);
			sem_Bb = przj_pTbb_non_slep_Bb->GetBinError(i);
			sem_nonB = przj_pTbb_non_slep_nonB->GetBinError(i);
	 
		  errorb_non_slep = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
												pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
												pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
												pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
												pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//g-jet
			//Get the event weights		
			evtW_B0 = przj_pTbg_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbg_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbg_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbg_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbg_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbg_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbg_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbg_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbg_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbg_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbg_B0->GetBinError(i);
			sem_Bp = przj_pTbg_Bp->GetBinError(i);
			sem_B0s = przj_pTbg_B0s->GetBinError(i);
			sem_Bb = przj_pTbg_Bb->GetBinError(i);
			sem_nonB = przj_pTbg_nonB->GetBinError(i);
	 
		  errorg = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//ud-jet
			//Get the event weights		
			evtW_B0 = przj_pTbud_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbud_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbud_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbud_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbud_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbud_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbud_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbud_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbud_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbud_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbud_B0->GetBinError(i);
			sem_Bp = przj_pTbud_Bp->GetBinError(i);
			sem_B0s = przj_pTbud_B0s->GetBinError(i);
			sem_Bb = przj_pTbud_Bb->GetBinError(i);
			sem_nonB = przj_pTbud_nonB->GetBinError(i);
	 
		  errorud = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

	//		//s-jet
	//		//Get the event weights		
			evtW_B0 = przj_pTbs_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbs_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbs_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbs_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbs_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbs_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbs_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbs_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbs_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbs_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbs_B0->GetBinError(i);
			sem_Bp = przj_pTbs_Bp->GetBinError(i);
			sem_B0s = przj_pTbs_B0s->GetBinError(i);
			sem_Bb = przj_pTbs_Bb->GetBinError(i);
			sem_nonB = przj_pTbs_nonB->GetBinError(i);
	 
		  errors = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
							  pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2)); 

			//c-jet
			//Get the event weights		
			evtW_B0 = przj_pTbc_B0->GetBinEntries(i);
			evtW_Bp = przj_pTbc_Bp->GetBinEntries(i);
			evtW_B0s = przj_pTbc_B0s->GetBinEntries(i);
			evtW_Bb = przj_pTbc_Bb->GetBinEntries(i);
			evtW_nonB = przj_pTbc_nonB->GetBinEntries(i);

			evtW_B0_w = przj_pTbc_B0_w->GetBinEntries(i);
			evtW_Bp_w = przj_pTbc_Bp_w->GetBinEntries(i);
			evtW_B0s_w = przj_pTbc_B0s_w->GetBinEntries(i);
			evtW_Bb_w = przj_pTbc_Bb_w->GetBinEntries(i);
			evtW_nonB_w = przj_pTbc_nonB_w->GetBinEntries(i);

			//Calculate the total weights over all categories
			evtW_tot = evtW_B0 + evtW_Bp + evtW_B0s + evtW_Bb + evtW_nonB;
			evtW_tot_w = evtW_B0_w + evtW_Bp_w + evtW_B0s_w + evtW_Bb_w + evtW_nonB_w;

			//The error given by the error propagation
			sem_B0 = przj_pTbc_B0->GetBinError(i);
			sem_Bp = przj_pTbc_Bp->GetBinError(i);
			sem_B0s = przj_pTbc_B0s->GetBinError(i);
			sem_Bb = przj_pTbc_Bb->GetBinError(i);
			sem_nonB = przj_pTbc_nonB->GetBinError(i);
	 
		  errorc = sqrt(pow((evtW_B0_w/evtW_tot_w - evtW_B0/evtW_tot)*sem_B0,2) +
								pow((evtW_Bp_w/evtW_tot_w - evtW_Bp/evtW_tot)*sem_Bp,2) + 
								pow((evtW_B0s_w/evtW_tot_w - evtW_B0s/evtW_tot)*sem_B0s,2) + 
								pow((evtW_Bb_w/evtW_tot_w - evtW_Bb/evtW_tot)*sem_Bb,2) + 
								pow((evtW_nonB_w/evtW_tot_w - evtW_nonB/evtW_tot)*sem_nonB,2));

			//Root won't plot empty bins so replace empty bins with very small number
			if (diff->GetBinContent(i) == 0) 					  diff->SetBinContent(i,1e-6);
			if (diffb_slep->GetBinContent(i) == 0) 		  diffb_slep->SetBinContent(i,1e-6);
			if (diffb_non_slep->GetBinContent(i) == 0)  diffb_non_slep->SetBinContent(i,1e-6);
			if (diffg->GetBinContent(i) == 0) 				  diffg->SetBinContent(i,1e-6);
			if (diffud->GetBinContent(i) == 0) 				  diffud->SetBinContent(i,1e-6);
			if (diffs->GetBinContent(i) == 0) 				  diffs->SetBinContent(i,1e-6);
			if (diffc->GetBinContent(i) == 0) 				  diffc->SetBinContent(i,1e-6);

			//Set the new bin errors
			diff->SetBinError(i,error);
			diffb_slep->SetBinError(i,errorb_slep);
			diffb_non_slep->SetBinError(i,errorb_non_slep);
			diffg->SetBinError(i,errorg);
			diffud->SetBinError(i,errorud);
			diffs->SetBinError(i,errors);
			diffc->SetBinError(i,errorc);
	  }

		//Scale to the percentages
	  diff->Scale(100.0);
	  diffb_non_slep->Scale(100.0);
	  diffb_slep->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_pTb = new TCanvas("pTb","",500,400);
	  canv_pTb->SetLeftMargin(0.13);
	  canv_pTb->SetBottomMargin(0.13);
	  canv_pTb->SetLogx();

	  diff  ->SetMarkerStyle(kOpenCircle);     	 		diff  ->SetMarkerColor(kBlack);
	  diffb_non_slep ->SetMarkerStyle(kFullCircle); diffb_non_slep ->SetMarkerColor(kRed+1);
	  diffb_slep ->SetMarkerStyle(kOpenCircle);     diffb_slep ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      		diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     			diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   		diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); 		diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  diffb_non_slep ->SetLineColor(kRed+1);
	  diffb_slep ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  if (smaller_markers) {
	  	diff  ->SetMarkerSize(0.3);              
	  	diffb_non_slep ->SetMarkerSize(0.3);
	  	diffb_slep ->SetMarkerSize(0.3);
	  	diffc ->SetMarkerSize(0.3);             
	  	diffs->SetMarkerSize(0.3);
	  	diffud ->SetMarkerSize(0.3);            
	  	diffg ->SetMarkerSize(0.3);
	  }

	  //Legend
	  TLegend* lz_pTb = new TLegend(0.37,0.17,0.64,0.39);
	  lz_pTb->SetBorderSize(0);

	  lz_pTb->AddEntry(diff,   "All",   "p");
	  lz_pTb->AddEntry(diffb_non_slep,  "b (non-semileptonic)",     "p");
	  lz_pTb->AddEntry(diffb_slep,  "b (semileptonic)",     "p");
	  lz_pTb->AddEntry(diffc,  "c",     "p");
	  lz_pTb->AddEntry(diffs,  "s",     "p");
	  lz_pTb->AddEntry(diffud, "ud",    "p");
	  lz_pTb->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  diff->GetXaxis()->SetMoreLogLabels();
	  diff->GetXaxis()->SetNoExponent();
	  diff->GetYaxis()->SetTitleOffset(1.5);
	  diff->GetXaxis()->SetTitleOffset(1.1);
	  diff->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
	  diff->GetYaxis()->SetTitle("p_{T}^{probe}/p_{T}^{tag} - p_{T,scaled}^{probe}/p_{T,scaled}^{tag} (%)");
	  diff->GetYaxis()->SetTitleSize(0.04);
	  diff->GetXaxis()->SetTitleSize(0.05);
	  gPad->SetTickx();   gPad->SetTicky();

	  //Plot
	  diff->Draw("p");
	  diffb_non_slep->Draw("PSAME");
	  diffb_slep->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_pTb->Draw();

    diff->SetMaximum(0.9);
    diff->SetMinimum(-0.9);

	  if (zoom_y_axis) {
	    diff->SetMaximum(0.25);
	    diff->SetMinimum(-0.4);
	  }

	  string amount;

	  if (n_events == "3000") amount = "3k";
	  if (n_events == "30000") amount = "30k";
	  if (n_events == "100000") amount = "100k";
	  if (n_events == "1000000") amount = "1M";
	  if (n_events == "5000000") amount = "5M";

	  string plotName;
	  if (zoom_y_axis) plotName = "plots/weightedPlots/diff_plots/zoom_" + amount; 
		else plotName = "plots/weightedPlots/diff_plots/" + amount;

    plotName += "_diff_pTbal.pdf";	//Filetype suffix

	  //Save plot
	  canv_pTb->Print(plotName.c_str()); delete canv_pTb;
  } 
}


