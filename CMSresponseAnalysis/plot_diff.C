#include "tdrstyle_mod15.C"
#include <iostream>
 
using namespace std;

void plot_diff(){

  bool mpf_plot = 0;
  bool pT_plot = 0;
  bool F_plot = 0;

  bool mpf_plot_ver1 = 0;
  bool pT_plot_ver1 = 0;

  bool mpf_plot_ver2 = 1;
  bool pT_plot_ver2 = 1;

  bool test_fit = 0;
  bool plot_rms_mpf = 0;
  bool plot_errors_mpf = 0;
  bool plot_bin_w_mpf = 0;
  bool test = 0;

  bool y_fixed = 0;
  bool no_nan = 0;
  bool zoom_y = 1;
  bool smaller_markers = 1;

  string n_events = "5000000";
  string OpenName = "output_ROOT_files/CMSJES_P8_Zjet_" + n_events + ".root";
  string var_OpenName = "output_ROOT_files/var_CMSJES_P8_Zjet_" + n_events + ".root";

  //B-hadron weights common to all the cases

  const double wB0 = 0.9318761619619224;
  const double wBp = 0.9571803929651981;
  const double wB0s = 1.0623430336597717;
  const double wBb = 1.8550607321587425;

  if (test_fit) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  //The weighted sample

	  TProfile *przj_MPF_var=0;   TProfile *przj_MPFc_var=0;
	  TProfile *przj_MPFs_var=0; TProfile *przj_MPFud_var=0; TProfile *przj_MPFg_var=0;
	  //TProfile *przj_MPFb_var=0;
	  TProfile *przj_MPFb_nl_var=0;
	  TProfile *przj_MPFb_le_var=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0_var=0; TProfile *przj_MPFc_B0_var=0;
	  TProfile *przj_MPFs_B0_var=0; TProfile *przj_MPFud_B0_var=0; TProfile *przj_MPFg_B0_var=0;
	  //TProfile *przj_MPFb_B0_var=0;
	  TProfile *przj_MPFb_nl_B0_var=0;
	  TProfile *przj_MPFb_le_B0_var=0;

	  TProfile *przj_MPF_Bp_var=0; TProfile *przj_MPFc_Bp_var=0;
	  TProfile *przj_MPFs_Bp_var=0; TProfile *przj_MPFud_Bp_var=0; TProfile *przj_MPFg_Bp_var=0;
	  //TProfile *przj_MPFb_Bp_var=0;
	  TProfile *przj_MPFb_nl_Bp_var=0;
	  TProfile *przj_MPFb_le_Bp_var=0;

	  TProfile *przj_MPF_B0s_var=0; TProfile *przj_MPFc_B0s_var=0;
	  TProfile *przj_MPFs_B0s_var=0; TProfile *przj_MPFud_B0s_var=0; TProfile *przj_MPFg_B0s_var=0;
	  //TProfile *przj_MPFb_B0s_var=0;
	  TProfile *przj_MPFb_nl_B0s_var=0;
	  TProfile *przj_MPFb_le_B0s_var=0;

	  TProfile *przj_MPF_Bb_var=0; TProfile *przj_MPFc_Bb_var=0;
	  TProfile *przj_MPFs_Bb_var=0; TProfile *przj_MPFud_Bb_var=0; TProfile *przj_MPFg_Bb_var=0;
	  //TProfile *przj_MPFb_Bb_var=0;
	  TProfile *przj_MPFb_nl_Bb_var=0;
	  TProfile *przj_MPFb_le_Bb_var=0;

	  TProfile *przj_MPF_nonB_var=0; TProfile *przj_MPFc_nonB_var=0;
	  TProfile *przj_MPFs_nonB_var=0; TProfile *przj_MPFud_nonB_var=0; TProfile *przj_MPFg_nonB_var=0;
	  //TProfile *przj_MPFb_nonB_var=0;
	  TProfile *przj_MPFb_nl_nonB_var=0;
	  TProfile *przj_MPFb_le_nonB_var=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);

      //Read the weighted sample
	
	  fzj_var->GetObject("prMPF",   przj_MPF_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_var);
	  fzj_var->GetObject("prMPFb_nl",  przj_MPFb_nl_var);
	  fzj_var->GetObject("prMPFb_le",  przj_MPFb_le_var);
	  fzj_var->GetObject("prMPFc",  przj_MPFc_var);
	  fzj_var->GetObject("prMPFs",  przj_MPFs_var);
	  fzj_var->GetObject("prMPFud", przj_MPFud_var);
	  fzj_var->GetObject("prMPFg",  przj_MPFg_var);

	  //Different B-hadron categories

	  fzj_var->GetObject("prMPF_B0",   przj_MPF_B0_var);
	  //fzj_var->GetObject("prMPFb_B0",  przj_MPFb_B0_var);
	  fzj_var->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0_var);
	  fzj_var->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0_var);
	  fzj_var->GetObject("prMPFc_B0",  przj_MPFc_B0_var);
	  fzj_var->GetObject("prMPFs_B0",  przj_MPFs_B0_var);
	  fzj_var->GetObject("prMPFud_B0", przj_MPFud_B0_var);
	  fzj_var->GetObject("prMPFg_B0",  przj_MPFg_B0_var);

	  fzj_var->GetObject("prMPF_Bp",   przj_MPF_Bp_var);
	  //fzj_var->GetObject("prMPFb_Bp",  przj_MPFb_Bp_var);
	  fzj_var->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp_var);
	  fzj_var->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp_var);
	  fzj_var->GetObject("prMPFc_Bp",  przj_MPFc_Bp_var);
	  fzj_var->GetObject("prMPFs_Bp",  przj_MPFs_Bp_var);
	  fzj_var->GetObject("prMPFud_Bp", przj_MPFud_Bp_var);
	  fzj_var->GetObject("prMPFg_Bp",  przj_MPFg_Bp_var);

	  fzj_var->GetObject("prMPF_B0s",   przj_MPF_B0s_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_B0s_var);
	  fzj_var->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s_var);
	  fzj_var->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s_var);
	  fzj_var->GetObject("prMPFc_B0s",  przj_MPFc_B0s_var);
	  fzj_var->GetObject("prMPFs_B0s",  przj_MPFs_B0s_var);
	  fzj_var->GetObject("prMPFud_B0s", przj_MPFud_B0s_var);
	  fzj_var->GetObject("prMPFg_B0s",  przj_MPFg_B0s_var);

	  fzj_var->GetObject("prMPF_Bb",   przj_MPF_Bb_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_Bb_var);
	  fzj_var->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb_var);
	  fzj_var->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb_var);
	  fzj_var->GetObject("prMPFc_Bb",  przj_MPFc_Bb_var);
	  fzj_var->GetObject("prMPFs_Bb",  przj_MPFs_Bb_var);
	  fzj_var->GetObject("prMPFud_Bb", przj_MPFud_Bb_var);
	  fzj_var->GetObject("prMPFg_Bb",  przj_MPFg_Bb_var);

	  fzj_var->GetObject("prMPF_nonB",   przj_MPF_nonB_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_nonB_var);
	  fzj_var->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB_var);
	  fzj_var->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB_var);
	  fzj_var->GetObject("prMPFc_nonB",  przj_MPFc_nonB_var);
	  fzj_var->GetObject("prMPFs_nonB",  przj_MPFs_nonB_var);
	  fzj_var->GetObject("prMPFud_nonB", przj_MPFud_nonB_var);
	  fzj_var->GetObject("prMPFg_nonB",  przj_MPFg_nonB_var);

	  TH1D* hzj_MPF   = przj_MPF  ->ProjectionX();
	  //TH1D* hzj_MPFb  = przj_MPFb ->ProjectionX();
	  TH1D* hzj_MPFb_nl  = przj_MPFb_nl ->ProjectionX();
	  TH1D* hzj_MPFb_le  = przj_MPFb_le ->ProjectionX();
	  TH1D* hzj_MPFc  = przj_MPFc ->ProjectionX();
	  TH1D* hzj_MPFs  = przj_MPFs ->ProjectionX();
	  TH1D* hzj_MPFud = przj_MPFud->ProjectionX();
	  TH1D* hzj_MPFg  = przj_MPFg ->ProjectionX();

	  TH1D* hzj_MPF_var   = przj_MPF_var  ->ProjectionX();
	  //TH1D* hzj_MPFb_var  = przj_MPFb_var ->ProjectionX();
	  TH1D* hzj_MPFb_nl_var  = przj_MPFb_nl_var ->ProjectionX();
	  TH1D* hzj_MPFb_le_var  = przj_MPFb_le_var ->ProjectionX();
	  TH1D* hzj_MPFc_var  = przj_MPFc_var ->ProjectionX();
	  TH1D* hzj_MPFs_var  = przj_MPFs_var ->ProjectionX();
	  TH1D* hzj_MPFud_var = przj_MPFud_var->ProjectionX();
	  TH1D* hzj_MPFg_var  = przj_MPFg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_MPF->Clone();
	  //TH1D* diffb = (TH1D*) hzj_MPFb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_MPFb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_MPFb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_MPFc->Clone();
	  TH1D* diffs = (TH1D*) hzj_MPFs->Clone();
	  TH1D* diffud = (TH1D*) hzj_MPFud->Clone();
	  TH1D* diffg = (TH1D*) hzj_MPFg->Clone();

	  diff->Add(hzj_MPF_var,-1);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Add(hzj_MPFb_nl_var,-1);
	  diffb_le->Add(hzj_MPFb_le_var,-1);
	  diffc->Add(hzj_MPFc_var,-1);
	  diffs->Add(hzj_MPFs_var,-1);
	  diffud->Add(hzj_MPFud_var,-1);
	  diffg->Add(hzj_MPFg_var,-1);

	  diff->Divide(hzj_MPF);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Divide(hzj_MPFb_nl);
	  diffb_le->Divide(hzj_MPFb_le);
	  diffc->Divide(hzj_MPFc);
	  diffs->Divide(hzj_MPFs);
	  diffud->Divide(hzj_MPFud);
	  diffg->Divide(hzj_MPFg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	  double val_std_B0; double val_std_Bp; double val_std_B0s; double val_std_Bb; double val_std_nonB;
	  double w_B0; double w_Bp; double w_B0s; double w_Bb; double w_nonB;
	  double w_B0_var; double w_Bp_var; double w_B0s_var; double w_Bb_var; double w_nonB_var;
	  double norm_tot_w; double var_tot_w;

   	  Int_t n = 14;
   	  Double_t B0[n], Bp[n], B0s[n], Bb[n], nonB[n];
   	  Double_t B0_e[n], Bp_e[n], B0s_e[n], Bb_e[n], nonB_e[n];
   	  Double_t b_nl_B0[n], b_nl_Bp[n], b_nl_B0s[n], b_nl_Bb[n], b_nl_nonB[n];
   	  Double_t b_nl_B0_e[n], b_nl_Bp_e[n], b_nl_B0s_e[n], b_nl_Bb_e[n], b_nl_nonB_e[n];
   	  Double_t b_le_B0[n], b_le_Bp[n], b_le_B0s[n], b_le_Bb[n], b_le_nonB[n];
   	  Double_t b_le_B0_e[n], b_le_Bp_e[n], b_le_B0s_e[n], b_le_Bb_e[n], b_le_nonB_e[n];
	  double e_B0; double e_Bp; double e_B0s; double e_Bb; double e_nonB;

	  //Note that the logic must be "inversed" is "s" option is used with the TProfiles

	  for (int i = 1; i < 15; i++){
		e_B0 = przj_MPF_B0->GetBinError(i);
		e_Bp = przj_MPF_Bp->GetBinError(i);
		e_B0s = przj_MPF_B0s->GetBinError(i);
		e_Bb = przj_MPF_Bb->GetBinError(i);
		e_nonB = przj_MPF_nonB->GetBinError(i);

		w_B0 = przj_MPF_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPF_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPF_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPF_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPF_nonB->GetBinEffectiveEntries(i);

		B0[i] = e_B0*sqrt(w_B0);
		Bp[i] = e_Bp*sqrt(w_Bp);
		B0s[i] = e_B0s*sqrt(w_B0s);
		Bb[i] = e_Bb*sqrt(w_Bb);
		nonB[i] = e_nonB*sqrt(w_nonB);

		B0_e[i] = e_B0;
		Bp_e[i] = e_Bp;
		B0s_e[i] = e_B0s;
		Bb_e[i] = e_Bb;
		nonB_e[i] = e_nonB;
		
		//b-jet semileptonic

	    //Different B-hadron categories
		e_B0 = przj_MPFb_le_B0->GetBinError(i);
		e_Bp = przj_MPFb_le_Bp->GetBinError(i);
		e_B0s = przj_MPFb_le_B0s->GetBinError(i);
		e_Bb = przj_MPFb_le_Bb->GetBinError(i);
		e_nonB = przj_MPFb_le_nonB->GetBinError(i);

		w_B0 = przj_MPFb_le_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPFb_le_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPFb_le_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPFb_le_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPFb_le_nonB->GetBinEffectiveEntries(i);

		b_nl_B0[i] = e_B0*sqrt(w_B0);
		b_nl_Bp[i] = e_Bp*sqrt(w_Bp);
		b_nl_B0s[i] = e_B0s*sqrt(w_B0s);
		b_nl_Bb[i] = e_Bb*sqrt(w_Bb);
		b_nl_nonB[i] = e_nonB*sqrt(w_nonB);

		b_nl_B0_e[i] = e_B0;
		b_nl_Bp_e[i] = e_Bp;
		b_nl_B0s_e[i] = e_B0s;
		b_nl_Bb_e[i] = e_Bb;
		b_nl_nonB_e[i] = e_nonB;

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		e_B0 = przj_MPFb_nl_B0->GetBinError(i);
		e_Bp = przj_MPFb_nl_Bp->GetBinError(i);
		e_B0s = przj_MPFb_nl_B0s->GetBinError(i);
		e_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		e_nonB = przj_MPFb_nl_nonB->GetBinError(i);

		w_B0 = przj_MPFb_nl_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPFb_nl_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPFb_nl_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPFb_nl_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPFb_nl_nonB->GetBinEffectiveEntries(i);

		b_le_B0[i] = e_B0*sqrt(w_B0);
		b_le_Bp[i] = e_Bp*sqrt(w_Bp);
		b_le_B0s[i] = e_B0s*sqrt(w_B0s);
		b_le_Bb[i] = e_Bb*sqrt(w_Bb);
		b_le_nonB[i] = e_nonB*sqrt(w_nonB);

		b_le_B0_e[i] = e_B0;
		b_le_Bp_e[i] = e_Bp;
		b_le_B0s_e[i] = e_B0s;
		b_le_Bb_e[i] = e_Bb;
		b_le_nonB_e[i] = e_nonB;
	  }

      Int_t nn = 14;
	  string amount;
	  string commonName;
	  string plotName;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

	  commonName = "diff_plots/test_fit/RMS_MPF_" + amount;


   const double x[14] = {36.375, 45.75, 57.0, 73.25, 94.125, 118.875, 152.875
					, 200.75, 264.125, 345.625, 447.5, 592.75, 816.625, 1104.875};


   TGraph *grB0  = new TGraphErrors(nn,x,B0,0,B0_e);
   TGraph *grBp  = new TGraphErrors(nn,x,Bp,0,Bp_e);
   TGraph *grB0s  = new TGraphErrors(nn,x,B0s,0,B0s_e);
   TGraph *grBb  = new TGraphErrors(nn,x,Bb,0,Bb_e);
   TGraph *grnonB  = new TGraphErrors(nn,x,nonB,0,nonB_e);
   TCanvas *c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetLogx();

   grB0 ->SetMarkerStyle(kOpenCircle);      grB0 ->SetMarkerColor(kRed+1);
   grBp ->SetMarkerStyle(kFullSquare);      grBp ->SetMarkerColor(kBlue+1);
   grB0s->SetMarkerStyle(kFullDiamond);     grB0s->SetMarkerColor(kMagenta+2);
   grBb->SetMarkerStyle(kFullTriangleUp);   grBb->SetMarkerColor(kOrange+1);
   grnonB->SetMarkerStyle(kFullTriangleDown); grnonB->SetMarkerColor(kGreen+2);

   TLegend* lz = new TLegend(0.67,0.57,0.84,0.79);

   lz->SetBorderSize(0);
   lz->AddEntry(grB0,   "B0",   "p");
   lz->AddEntry(grBp,  "Bp",     "p");
   lz->AddEntry(grB0s,  "B0s",     "p");
   lz->AddEntry(grBb,  "Bb",     "p");
   lz->AddEntry(grnonB,  "nonB",     "p");

   grnonB->GetYaxis()->SetTitleOffset(1.2);
   grnonB->GetXaxis()->SetTitleOffset(1.1);
   grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   grnonB->GetYaxis()->SetTitle("RMS");
   grnonB->GetYaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetMoreLogLabels();
   grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   grnonB->Draw("AP");
   grB0->Draw("PSAME");
   grBp->Draw("PSAME");
   grB0s->Draw("PSAME");
   grBb->Draw("PSAME");
   grnonB->Draw("PSAME");

   grnonB->SetMaximum(0.21);
   grnonB->SetMinimum(0.0);

   lz->Draw();
   plotName = commonName + "_all.pdf";
   c1->Print(plotName.c_str()); delete c1;
//   c1->Print("B0.pdf"); delete c1;

  //b-jet non-semileptonic
   TGraph *b_le_grB0  = new TGraphErrors(nn,x,b_le_B0,0,b_le_B0_e);
   TGraph *b_le_grBp  = new TGraphErrors(nn,x,b_le_Bp,0,b_le_Bp_e);
   TGraph *b_le_grB0s  = new TGraphErrors(nn,x,b_le_B0s,0,b_le_B0s_e);
   TGraph *b_le_grBb  = new TGraphErrors(nn,x,b_le_Bb,0,b_le_Bb_e);
   TGraph *b_le_grnonB  = new TGraphErrors(nn,x,b_le_nonB,0,b_le_nonB_e);
   TCanvas *b_le_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_le_c1->SetLeftMargin(0.13);
   b_le_c1->SetBottomMargin(0.13);

   b_le_c1->SetLogx();

   b_le_grB0 ->SetMarkerStyle(kOpenCircle);      b_le_grB0 ->SetMarkerColor(kRed+1);
   b_le_grBp ->SetMarkerStyle(kFullSquare);      b_le_grBp ->SetMarkerColor(kBlue+1);
   b_le_grB0s->SetMarkerStyle(kFullDiamond);     b_le_grB0s->SetMarkerColor(kMagenta+2);
   b_le_grBb->SetMarkerStyle(kFullTriangleUp);   b_le_grBb->SetMarkerColor(kOrange+1);
   b_le_grnonB->SetMarkerStyle(kFullTriangleDown); b_le_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_le_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_le_lz->SetBorderSize(0);
   b_le_lz->AddEntry(b_le_grB0,   "B0",   "p");
   b_le_lz->AddEntry(b_le_grBp,  "Bp",     "p");
   b_le_lz->AddEntry(b_le_grB0s,  "B0s",     "p");
   b_le_lz->AddEntry(b_le_grBb,  "Bb",     "p");
   b_le_lz->AddEntry(b_le_grnonB,  "nonB",     "p");

   b_le_grB0s->GetYaxis()->SetTitleOffset(1.2);
   b_le_grB0s->GetXaxis()->SetTitleOffset(1.1);
   b_le_grB0s->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_le_grB0s->GetYaxis()->SetTitle("RMS");
   b_le_grB0s->GetYaxis()->SetTitleSize(0.05);
   b_le_grB0s->GetXaxis()->SetTitleSize(0.05);
   b_le_grB0s->GetXaxis()->SetMoreLogLabels();
   b_le_grB0s ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_le_grB0s->Draw("AP");
   b_le_grBb->Draw("PSAME");
   b_le_grBp->Draw("PSAME");
   b_le_grB0->Draw("PSAME");
   //b_le_grBb->Draw("PSAME");
   b_le_grnonB->Draw("PSAME");
   b_le_lz->Draw();

   b_le_grB0s->SetMaximum(0.21);
   b_le_grB0s->SetMinimum(0.0);

   plotName = commonName + "_b_semilep.pdf";
   b_le_c1->Print(plotName.c_str()); delete b_le_c1;

  //b-jet non-semileptonic
   TGraph *b_nl_grB0  = new TGraphErrors(nn,x,b_nl_B0,0,b_nl_B0_e);
   TGraph *b_nl_grBp  = new TGraphErrors(nn,x,b_nl_Bp,0,b_nl_Bp_e);
   TGraph *b_nl_grB0s  = new TGraphErrors(nn,x,b_nl_B0s,0,b_nl_B0s_e);
   TGraph *b_nl_grBb  = new TGraphErrors(nn,x,b_nl_Bb,0,b_nl_Bb_e);
   TGraph *b_nl_grnonB  = new TGraphErrors(nn,x,b_nl_nonB,0,b_nl_nonB_e);
   TCanvas *b_nl_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_nl_c1->SetLeftMargin(0.13);
   b_nl_c1->SetBottomMargin(0.13);

   b_nl_c1->SetLogx();

   b_nl_grB0 ->SetMarkerStyle(kOpenCircle);      b_nl_grB0 ->SetMarkerColor(kRed+1);
   b_nl_grBp ->SetMarkerStyle(kFullSquare);      b_nl_grBp ->SetMarkerColor(kBlue+1);
   b_nl_grB0s->SetMarkerStyle(kFullDiamond);     b_nl_grB0s->SetMarkerColor(kMagenta+2);
   b_nl_grBb->SetMarkerStyle(kFullTriangleUp);   b_nl_grBb->SetMarkerColor(kOrange+1);
   b_nl_grnonB->SetMarkerStyle(kFullTriangleDown); b_nl_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_nl_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_nl_lz->SetBorderSize(0);
   b_nl_lz->AddEntry(b_nl_grB0,   "B0",   "p");
   b_nl_lz->AddEntry(b_nl_grBp,  "Bp",     "p");
   b_nl_lz->AddEntry(b_nl_grB0s,  "B0s",     "p");
   b_nl_lz->AddEntry(b_nl_grBb,  "Bb",     "p");
   b_nl_lz->AddEntry(b_nl_grnonB,  "nonB",     "p");

   b_nl_grBp->GetYaxis()->SetTitleOffset(1.2);
   b_nl_grBp->GetXaxis()->SetTitleOffset(1.1);
   b_nl_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_nl_grBp->GetYaxis()->SetTitle("RMS");
   b_nl_grBp->GetYaxis()->SetTitleSize(0.05);
   b_nl_grBp->GetXaxis()->SetTitleSize(0.05);
   b_nl_grBp->GetXaxis()->SetMoreLogLabels();
   b_nl_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_nl_grBp->Draw("AP");
   b_nl_grB0s->Draw("PSAME");
   b_nl_grnonB->Draw("PSAME");
   b_nl_grB0->Draw("PSAME");
   b_nl_grBb->Draw("PSAME");
   //b_nl_grnonB->Draw("PSAME");
   b_nl_lz->Draw();

   b_nl_grBp->SetMaximum(0.21);
   b_nl_grBp->SetMinimum(0.0);

   plotName = commonName + "_b_non_semilep.pdf";
   b_nl_c1->Print(plotName.c_str()); delete b_nl_c1;
    
  }

  if (plot_rms_mpf) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);	

   	  Int_t n = 14;
   	  Double_t B0[n], Bp[n], B0s[n], Bb[n], nonB[n];
   	  Double_t b_nl_B0[n], b_nl_Bp[n], b_nl_B0s[n], b_nl_Bb[n], b_nl_nonB[n];
   	  Double_t b_le_B0[n], b_le_Bp[n], b_le_B0s[n], b_le_Bb[n], b_le_nonB[n];
   	  Double_t c_B0[n], c_Bp[n], c_B0s[n], c_Bb[n], c_nonB[n];
   	  Double_t s_B0[n], s_Bp[n], s_B0s[n], s_Bb[n], s_nonB[n];
   	  Double_t ud_B0[n], ud_Bp[n], ud_B0s[n], ud_Bb[n], ud_nonB[n];
   	  Double_t g_B0[n], g_Bp[n], g_B0s[n], g_Bb[n], g_nonB[n];
	  double e_B0; double e_Bp; double e_B0s; double e_Bb; double e_nonB;
	  double w_B0; double w_Bp; double w_B0s; double w_Bb; double w_nonB;

	for (int i = 1; i < 15; i++) {
		e_B0 = przj_MPF_B0->GetBinError(i);
		e_Bp = przj_MPF_Bp->GetBinError(i);
		e_B0s = przj_MPF_B0s->GetBinError(i);
		e_Bb = przj_MPF_Bb->GetBinError(i);
		e_nonB = przj_MPF_nonB->GetBinError(i);

		w_B0 = przj_MPF_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPF_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPF_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPF_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPF_nonB->GetBinEffectiveEntries(i);

		B0[i] = e_B0*sqrt(w_B0);
		Bp[i] = e_Bp*sqrt(w_Bp);
		B0s[i] = e_B0s*sqrt(w_B0s);
		Bb[i] = e_Bb*sqrt(w_Bb);
		nonB[i] = e_nonB*sqrt(w_nonB);
		
		//b-jet semileptonic

	    //Different B-hadron categories
		e_B0 = przj_MPFb_le_B0->GetBinError(i);
		e_Bp = przj_MPFb_le_Bp->GetBinError(i);
		e_B0s = przj_MPFb_le_B0s->GetBinError(i);
		e_Bb = przj_MPFb_le_Bb->GetBinError(i);
		e_nonB = przj_MPFb_le_nonB->GetBinError(i);

		w_B0 = przj_MPFb_le_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPFb_le_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPFb_le_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPFb_le_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPFb_le_nonB->GetBinEffectiveEntries(i);

		b_nl_B0[i] = e_B0*sqrt(w_B0);
		b_nl_Bp[i] = e_Bp*sqrt(w_Bp);
		b_nl_B0s[i] = e_B0s*sqrt(w_B0s);
		b_nl_Bb[i] = e_Bb*sqrt(w_Bb);
		b_nl_nonB[i] = e_nonB*sqrt(w_nonB);

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		e_B0 = przj_MPFb_nl_B0->GetBinError(i);
		e_Bp = przj_MPFb_nl_Bp->GetBinError(i);
		e_B0s = przj_MPFb_nl_B0s->GetBinError(i);
		e_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		e_nonB = przj_MPFb_nl_nonB->GetBinError(i);

		w_B0 = przj_MPFb_nl_B0->GetBinEffectiveEntries(i);
		w_Bp = przj_MPFb_nl_Bp->GetBinEffectiveEntries(i);
		w_B0s = przj_MPFb_nl_B0s->GetBinEffectiveEntries(i);
		w_Bb = przj_MPFb_nl_Bb->GetBinEffectiveEntries(i);
		w_nonB = przj_MPFb_nl_nonB->GetBinEffectiveEntries(i);

		b_le_B0[i] = e_B0*sqrt(w_B0);
		b_le_Bp[i] = e_Bp*sqrt(w_Bp);
		b_le_B0s[i] = e_B0s*sqrt(w_B0s);
		b_le_Bb[i] = e_Bb*sqrt(w_Bb);
		b_le_nonB[i] = e_nonB*sqrt(w_nonB);

//		//g-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFg_B0->GetBinError(i);
		e_Bp = przj_MPFg_Bp->GetBinError(i);
		e_B0s = przj_MPFg_B0s->GetBinError(i);
		e_Bb = przj_MPFg_Bb->GetBinError(i);
		e_nonB = przj_MPFg_nonB->GetBinError(i);

		g_B0[i] = e_B0;
		g_Bp[i] = e_Bp;
		g_B0s[i] = e_B0s;
		g_Bb[i] = e_Bb;
		g_nonB[i] = e_nonB;

//		//ud-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFud_B0->GetBinError(i);
		e_Bp = przj_MPFud_Bp->GetBinError(i);
		e_B0s = przj_MPFud_B0s->GetBinError(i);
		e_Bb = przj_MPFud_Bb->GetBinError(i);
		e_nonB = przj_MPFud_nonB->GetBinError(i);

		ud_B0[i] = e_B0;
		ud_Bp[i] = e_Bp;
		ud_B0s[i] = e_B0s;
		ud_Bb[i] = e_Bb;
		ud_nonB[i] = e_nonB;

//		//s-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFs_B0->GetBinError(i);
		e_Bp = przj_MPFs_Bp->GetBinError(i);
		e_B0s = przj_MPFs_B0s->GetBinError(i);
		e_Bb = przj_MPFs_Bb->GetBinError(i);
		e_nonB = przj_MPFs_nonB->GetBinError(i);

		s_B0[i] = e_B0;
		s_Bp[i] = e_Bp;
		s_B0s[i] = e_B0s;
		s_Bb[i] = e_Bb;
		s_nonB[i] = e_nonB;

//		//c-jet

//		//Different B-hadron categories

		e_B0 = przj_MPFc_B0->GetBinError(i);
		e_Bp = przj_MPFc_Bp->GetBinError(i);
		e_B0s = przj_MPFc_B0s->GetBinError(i);
		e_Bb = przj_MPFc_Bb->GetBinError(i);
		e_nonB = przj_MPFc_nonB->GetBinError(i);

		c_B0[i] = e_B0;
		c_Bp[i] = e_Bp;
		c_B0s[i] = e_B0s;
		c_Bb[i] = e_Bb;
		c_nonB[i] = e_nonB;
	}
//   Double_t x[14];
   Int_t nn = 14;
//   for (Int_t i=1;i<=nn;i++) {
//     x[i] = i;
//   }

	  string amount;
	  string commonName;
	  string plotName;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

	  commonName = "diff_plots/error_RMS/RMS_MPF_" + amount;


   const double x[14] = {36.375, 45.75, 57.0, 73.25, 94.125, 118.875, 152.875
					, 200.75, 264.125, 345.625, 447.5, 592.75, 816.625, 1104.875};


   TGraph *grB0  = new TGraph(nn,x,B0);
   TGraph *grBp  = new TGraph(nn,x,Bp);
   TGraph *grB0s  = new TGraph(nn,x,B0s);
   TGraph *grBb  = new TGraph(nn,x,Bb);
   TGraph *grnonB  = new TGraph(nn,x,nonB);
   TCanvas *c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetLogx();

   grB0 ->SetMarkerStyle(kOpenCircle);      grB0 ->SetMarkerColor(kRed+1);
   grBp ->SetMarkerStyle(kFullSquare);      grBp ->SetMarkerColor(kBlue+1);
   grB0s->SetMarkerStyle(kFullDiamond);     grB0s->SetMarkerColor(kMagenta+2);
   grBb->SetMarkerStyle(kFullTriangleUp);   grBb->SetMarkerColor(kOrange+1);
   grnonB->SetMarkerStyle(kFullTriangleDown); grnonB->SetMarkerColor(kGreen+2);

   TLegend* lz = new TLegend(0.67,0.57,0.84,0.79);

   lz->SetBorderSize(0);
   lz->AddEntry(grB0,   "B0",   "p");
   lz->AddEntry(grBp,  "Bp",     "p");
   lz->AddEntry(grB0s,  "B0s",     "p");
   lz->AddEntry(grBb,  "Bb",     "p");
   lz->AddEntry(grnonB,  "nonB",     "p");

   grnonB->GetYaxis()->SetTitleOffset(1.2);
   grnonB->GetXaxis()->SetTitleOffset(1.1);
   grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   grnonB->GetYaxis()->SetTitle("RMS");
   grnonB->GetYaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetMoreLogLabels();
   grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   grnonB->Draw("AP");
   grB0->Draw("PSAME");
   grBp->Draw("PSAME");
   grB0s->Draw("PSAME");
   grBb->Draw("PSAME");
   grnonB->Draw("PSAME");

   lz->Draw();
   plotName = commonName + "_all.pdf";
   c1->Print(plotName.c_str()); delete c1;
//   c1->Print("B0.pdf"); delete c1;

  //b-jet non-semileptonic
   TGraph *b_le_grB0  = new TGraph(nn,x,b_le_B0);
   TGraph *b_le_grBp  = new TGraph(nn,x,b_le_Bp);
   TGraph *b_le_grB0s  = new TGraph(nn,x,b_le_B0s);
   TGraph *b_le_grBb  = new TGraph(nn,x,b_le_Bb);
   TGraph *b_le_grnonB  = new TGraph(nn,x,b_le_nonB);
   TCanvas *b_le_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_le_c1->SetLeftMargin(0.13);
   b_le_c1->SetBottomMargin(0.13);

   b_le_c1->SetLogx();

   b_le_grB0 ->SetMarkerStyle(kOpenCircle);      b_le_grB0 ->SetMarkerColor(kRed+1);
   b_le_grBp ->SetMarkerStyle(kFullSquare);      b_le_grBp ->SetMarkerColor(kBlue+1);
   b_le_grB0s->SetMarkerStyle(kFullDiamond);     b_le_grB0s->SetMarkerColor(kMagenta+2);
   b_le_grBb->SetMarkerStyle(kFullTriangleUp);   b_le_grBb->SetMarkerColor(kOrange+1);
   b_le_grnonB->SetMarkerStyle(kFullTriangleDown); b_le_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_le_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_le_lz->SetBorderSize(0);
   b_le_lz->AddEntry(b_le_grB0,   "B0",   "p");
   b_le_lz->AddEntry(b_le_grBp,  "Bp",     "p");
   b_le_lz->AddEntry(b_le_grB0s,  "B0s",     "p");
   b_le_lz->AddEntry(b_le_grBb,  "Bb",     "p");
   b_le_lz->AddEntry(b_le_grnonB,  "nonB",     "p");

   b_le_grB0s->GetYaxis()->SetTitleOffset(1.2);
   b_le_grB0s->GetXaxis()->SetTitleOffset(1.1);
   b_le_grB0s->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_le_grB0s->GetYaxis()->SetTitle("RMS");
   b_le_grB0s->GetYaxis()->SetTitleSize(0.05);
   b_le_grB0s->GetXaxis()->SetTitleSize(0.05);
   b_le_grB0s->GetXaxis()->SetMoreLogLabels();
   b_le_grB0s ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_le_grB0s->Draw("AP");
   b_le_grBb->Draw("PSAME");
   b_le_grBp->Draw("PSAME");
   b_le_grB0->Draw("PSAME");
   //b_le_grBb->Draw("PSAME");
   b_le_grnonB->Draw("PSAME");
   b_le_lz->Draw();

   plotName = commonName + "_b_semilep.pdf";
   b_le_c1->Print(plotName.c_str()); delete b_le_c1;

  //b-jet non-semileptonic
   TGraph *b_nl_grB0  = new TGraph(nn,x,b_nl_B0);
   TGraph *b_nl_grBp  = new TGraph(nn,x,b_nl_Bp);
   TGraph *b_nl_grB0s  = new TGraph(nn,x,b_nl_B0s);
   TGraph *b_nl_grBb  = new TGraph(nn,x,b_nl_Bb);
   TGraph *b_nl_grnonB  = new TGraph(nn,x,b_nl_nonB);
   TCanvas *b_nl_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_nl_c1->SetLeftMargin(0.13);
   b_nl_c1->SetBottomMargin(0.13);

   b_nl_c1->SetLogx();

   b_nl_grB0 ->SetMarkerStyle(kOpenCircle);      b_nl_grB0 ->SetMarkerColor(kRed+1);
   b_nl_grBp ->SetMarkerStyle(kFullSquare);      b_nl_grBp ->SetMarkerColor(kBlue+1);
   b_nl_grB0s->SetMarkerStyle(kFullDiamond);     b_nl_grB0s->SetMarkerColor(kMagenta+2);
   b_nl_grBb->SetMarkerStyle(kFullTriangleUp);   b_nl_grBb->SetMarkerColor(kOrange+1);
   b_nl_grnonB->SetMarkerStyle(kFullTriangleDown); b_nl_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_nl_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_nl_lz->SetBorderSize(0);
   b_nl_lz->AddEntry(b_nl_grB0,   "B0",   "p");
   b_nl_lz->AddEntry(b_nl_grBp,  "Bp",     "p");
   b_nl_lz->AddEntry(b_nl_grB0s,  "B0s",     "p");
   b_nl_lz->AddEntry(b_nl_grBb,  "Bb",     "p");
   b_nl_lz->AddEntry(b_nl_grnonB,  "nonB",     "p");

   b_nl_grBp->GetYaxis()->SetTitleOffset(1.2);
   b_nl_grBp->GetXaxis()->SetTitleOffset(1.1);
   b_nl_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_nl_grBp->GetYaxis()->SetTitle("RMS");
   b_nl_grBp->GetYaxis()->SetTitleSize(0.05);
   b_nl_grBp->GetXaxis()->SetTitleSize(0.05);
   b_nl_grBp->GetXaxis()->SetMoreLogLabels();
   b_nl_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_nl_grBp->Draw("AP");
   b_nl_grB0s->Draw("PSAME");
   b_nl_grnonB->Draw("PSAME");
   b_nl_grB0->Draw("PSAME");
   b_nl_grBb->Draw("PSAME");
   //b_nl_grnonB->Draw("PSAME");
   b_nl_lz->Draw();

   plotName = commonName + "_b_non_semilep.pdf";
   b_nl_c1->Print(plotName.c_str()); delete b_nl_c1;

   //g-jets
   TGraph *g_grB0  = new TGraph(nn,x,g_B0);
   TGraph *g_grBp  = new TGraph(nn,x,g_Bp);
   TGraph *g_grB0s  = new TGraph(nn,x,g_B0s);
   TGraph *g_grBb  = new TGraph(nn,x,g_Bb);
   TGraph *g_grnonB  = new TGraph(nn,x,g_nonB);
   TCanvas *g_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   g_c1->SetLeftMargin(0.13);
   g_c1->SetBottomMargin(0.13);

   g_c1->SetLogx();

   g_grB0 ->SetMarkerStyle(kOpenCircle);      g_grB0 ->SetMarkerColor(kRed+1);
   g_grBp ->SetMarkerStyle(kFullSquare);      g_grBp ->SetMarkerColor(kBlue+1);
   g_grB0s->SetMarkerStyle(kFullDiamond);     g_grB0s->SetMarkerColor(kMagenta+2);
   g_grBb->SetMarkerStyle(kFullTriangleUp);   g_grBb->SetMarkerColor(kOrange+1);
   g_grnonB->SetMarkerStyle(kFullTriangleDown); g_grnonB->SetMarkerColor(kGreen+2);

   TLegend* g_lz = new TLegend(0.67,0.57,0.84,0.79);

   g_lz->SetBorderSize(0);
   g_lz->AddEntry(g_grB0,   "B0",   "p");
   g_lz->AddEntry(g_grBp,  "Bp",     "p");
   g_lz->AddEntry(g_grB0s,  "B0s",     "p");
   g_lz->AddEntry(g_grBb,  "Bb",     "p");
   g_lz->AddEntry(g_grnonB,  "nonB",     "p");

   g_grBp->GetYaxis()->SetTitleOffset(1.2);
   g_grBp->GetXaxis()->SetTitleOffset(1.1);
   g_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   g_grBp->GetYaxis()->SetTitle("Error of the mean");
   g_grBp->GetYaxis()->SetTitleSize(0.05);
   g_grBp->GetXaxis()->SetTitleSize(0.05);
   g_grBp->GetXaxis()->SetMoreLogLabels();
   g_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   g_grBp->Draw("AP");
   g_grnonB->Draw("PSAME");
   g_grB0->Draw("PSAME");
//   g_grBp->Draw("PSAME");
   g_grB0s->Draw("PSAME");
   g_grBb->Draw("PSAME");
   g_lz->Draw();

   plotName = commonName + "_g.pdf";
   g_c1->Print(plotName.c_str()); delete g_c1;

	
   //c-jets
   TGraph *c_grB0  = new TGraph(nn,x,c_B0);
   TGraph *c_grBp  = new TGraph(nn,x,c_Bp);
   TGraph *c_grB0s  = new TGraph(nn,x,c_B0s);
   TGraph *c_grBb  = new TGraph(nn,x,c_Bb);
   TGraph *c_grnonB  = new TGraph(nn,x,c_nonB);
   TCanvas *c_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c_c1->SetLeftMargin(0.13);
   c_c1->SetBottomMargin(0.13);

   c_c1->SetLogx();

   c_grB0 ->SetMarkerStyle(kOpenCircle);      c_grB0 ->SetMarkerColor(kRed+1);
   c_grBp ->SetMarkerStyle(kFullSquare);      c_grBp ->SetMarkerColor(kBlue+1);
   c_grB0s->SetMarkerStyle(kFullDiamond);     c_grB0s->SetMarkerColor(kMagenta+2);
   c_grBb->SetMarkerStyle(kFullTriangleUp);   c_grBb->SetMarkerColor(kOrange+1);
   c_grnonB->SetMarkerStyle(kFullTriangleDown); c_grnonB->SetMarkerColor(kGreen+2);

   TLegend* c_lz = new TLegend(0.67,0.57,0.84,0.79);

   c_lz->SetBorderSize(0);
   c_lz->AddEntry(c_grB0,   "B0",   "p");
   c_lz->AddEntry(c_grBp,  "Bp",     "p");
   c_lz->AddEntry(c_grB0s,  "B0s",     "p");
   c_lz->AddEntry(c_grBb,  "Bb",     "p");
   c_lz->AddEntry(c_grnonB,  "nonB",     "p");

   c_grBp->GetYaxis()->SetTitleOffset(1.2);
   c_grBp->GetXaxis()->SetTitleOffset(1.1);
   c_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   c_grBp->GetYaxis()->SetTitle("Error of the mean");
   c_grBp->GetYaxis()->SetTitleSize(0.05);
   c_grBp->GetXaxis()->SetTitleSize(0.05);
   c_grBp->GetXaxis()->SetMoreLogLabels();
   c_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   c_grBp->Draw("AP");
   c_grnonB->Draw("PSAME");
   c_grB0->Draw("PSAME");
//   c_grBp->Draw("PSAME");
   c_grB0s->Draw("PSAME");
   c_grBb->Draw("PSAME");
   c_lz->Draw();

   plotName = commonName + "_c.pdf";
   c_c1->Print(plotName.c_str()); delete c_c1;

   //s-jets
   TGraph *s_grB0  = new TGraph(nn,x,s_B0);
   TGraph *s_grBp  = new TGraph(nn,x,s_Bp);
   TGraph *s_grB0s  = new TGraph(nn,x,s_B0s);
   TGraph *s_grBb  = new TGraph(nn,x,s_Bb);
   TGraph *s_grnonB  = new TGraph(nn,x,s_nonB);
   TCanvas *s_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   s_c1->SetLeftMargin(0.13);
   s_c1->SetBottomMargin(0.13);

   s_c1->SetLogx();

   s_grB0 ->SetMarkerStyle(kOpenCircle);      s_grB0 ->SetMarkerColor(kRed+1);
   s_grBp ->SetMarkerStyle(kFullSquare);      s_grBp ->SetMarkerColor(kBlue+1);
   s_grB0s->SetMarkerStyle(kFullDiamond);     s_grB0s->SetMarkerColor(kMagenta+2);
   s_grBb->SetMarkerStyle(kFullTriangleUp);   s_grBb->SetMarkerColor(kOrange+1);
   s_grnonB->SetMarkerStyle(kFullTriangleDown); s_grnonB->SetMarkerColor(kGreen+2);

   TLegend* s_lz = new TLegend(0.67,0.57,0.84,0.79);

   s_lz->SetBorderSize(0);
   s_lz->AddEntry(s_grB0,   "B0",   "p");
   s_lz->AddEntry(s_grBp,  "Bp",     "p");
   s_lz->AddEntry(s_grB0s,  "B0s",     "p");
   s_lz->AddEntry(s_grBb,  "Bb",     "p");
   s_lz->AddEntry(s_grnonB,  "nonB",     "p");

   s_grBp->GetYaxis()->SetTitleOffset(1.2);
   s_grBp->GetXaxis()->SetTitleOffset(1.1);
   s_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   s_grBp->GetYaxis()->SetTitle("Error of the mean");
   s_grBp->GetYaxis()->SetTitleSize(0.05);
   s_grBp->GetXaxis()->SetTitleSize(0.05);
   s_grBp->GetXaxis()->SetMoreLogLabels();
   s_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   s_grBp->Draw("AP");
   s_grnonB->Draw("PSAME");
   s_grB0->Draw("PSAME");
//   s_grBp->Draw("PSAME");
   s_grB0s->Draw("PSAME");
   s_grBb->Draw("PSAME");
   s_lz->Draw();

   plotName = commonName + "_s.pdf";
   s_c1->Print(plotName.c_str()); delete s_c1;

   //ud-jets
   TGraph *ud_grB0  = new TGraph(nn,x,ud_B0);
   TGraph *ud_grBp  = new TGraph(nn,x,ud_Bp);
   TGraph *ud_grB0s  = new TGraph(nn,x,ud_B0s);
   TGraph *ud_grBb  = new TGraph(nn,x,ud_Bb);
   TGraph *ud_grnonB  = new TGraph(nn,x,ud_nonB);
   TCanvas *ud_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   ud_c1->SetLeftMargin(0.13);
   ud_c1->SetBottomMargin(0.13);

   ud_c1->SetLogx();

   ud_grB0 ->SetMarkerStyle(kOpenCircle);      ud_grB0 ->SetMarkerColor(kRed+1);
   ud_grBp ->SetMarkerStyle(kFullSquare);      ud_grBp ->SetMarkerColor(kBlue+1);
   ud_grB0s->SetMarkerStyle(kFullDiamond);     ud_grB0s->SetMarkerColor(kMagenta+2);
   ud_grBb->SetMarkerStyle(kFullTriangleUp);   ud_grBb->SetMarkerColor(kOrange+1);
   ud_grnonB->SetMarkerStyle(kFullTriangleDown); ud_grnonB->SetMarkerColor(kGreen+2);

   TLegend* ud_lz = new TLegend(0.67,0.57,0.84,0.79);

   ud_lz->SetBorderSize(0);
   ud_lz->AddEntry(ud_grB0,   "B0",   "p");
   ud_lz->AddEntry(ud_grBp,  "Bp",     "p");
   ud_lz->AddEntry(ud_grB0s,  "B0s",     "p");
   ud_lz->AddEntry(ud_grBb,  "Bb",     "p");
   ud_lz->AddEntry(ud_grnonB,  "nonB",     "p");

   ud_grBp->GetYaxis()->SetTitleOffset(1.2);
   ud_grBp->GetXaxis()->SetTitleOffset(1.1);
   ud_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   ud_grBp->GetYaxis()->SetTitle("Error of the mean");
   ud_grBp->GetYaxis()->SetTitleSize(0.05);
   ud_grBp->GetXaxis()->SetTitleSize(0.05);
   ud_grBp->GetXaxis()->SetMoreLogLabels();
   ud_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   ud_grBp->Draw("AP");
   ud_grnonB->Draw("PSAME");
   ud_grB0->Draw("PSAME");
//   ud_grBp->Draw("PSAME");
   ud_grB0s->Draw("PSAME");
   ud_grBb->Draw("PSAME");
   ud_lz->Draw();

   plotName = commonName + "_ud.pdf";
   ud_c1->Print(plotName.c_str()); delete ud_c1;
  }


  if (plot_errors_mpf) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);	

   	  Int_t n = 14;
   	  Double_t B0[n], Bp[n], B0s[n], Bb[n], nonB[n];
   	  Double_t b_nl_B0[n], b_nl_Bp[n], b_nl_B0s[n], b_nl_Bb[n], b_nl_nonB[n];
   	  Double_t b_le_B0[n], b_le_Bp[n], b_le_B0s[n], b_le_Bb[n], b_le_nonB[n];
   	  Double_t c_B0[n], c_Bp[n], c_B0s[n], c_Bb[n], c_nonB[n];
   	  Double_t s_B0[n], s_Bp[n], s_B0s[n], s_Bb[n], s_nonB[n];
   	  Double_t ud_B0[n], ud_Bp[n], ud_B0s[n], ud_Bb[n], ud_nonB[n];
   	  Double_t g_B0[n], g_Bp[n], g_B0s[n], g_Bb[n], g_nonB[n];
	  double e_B0; double e_Bp; double e_B0s; double e_Bb; double e_nonB;

	for (int i = 1; i < 15; i++) {
		e_B0 = przj_MPF_B0->GetBinError(i);
		e_Bp = przj_MPF_Bp->GetBinError(i);
		e_B0s = przj_MPF_B0s->GetBinError(i);
		e_Bb = przj_MPF_Bb->GetBinError(i);
		e_nonB = przj_MPF_nonB->GetBinError(i);

		B0[i] = e_B0;
		Bp[i] = e_Bp;
		B0s[i] = e_B0s;
		Bb[i] = e_Bb;
		nonB[i] = e_nonB;
		
		//b-jet semileptonic

	    //Different B-hadron categories
		e_B0 = przj_MPFb_le_B0->GetBinError(i);
		e_Bp = przj_MPFb_le_Bp->GetBinError(i);
		e_B0s = przj_MPFb_le_B0s->GetBinError(i);
		e_Bb = przj_MPFb_le_Bb->GetBinError(i);
		e_nonB = przj_MPFb_le_nonB->GetBinError(i);

		b_nl_B0[i] = e_B0;
		b_nl_Bp[i] = e_Bp;
		b_nl_B0s[i] = e_B0s;
		b_nl_Bb[i] = e_Bb;
		b_nl_nonB[i] = e_nonB;

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		e_B0 = przj_MPFb_nl_B0->GetBinError(i);
		e_Bp = przj_MPFb_nl_Bp->GetBinError(i);
		e_B0s = przj_MPFb_nl_B0s->GetBinError(i);
		e_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		e_nonB = przj_MPFb_nl_nonB->GetBinError(i);

		b_le_B0[i] = e_B0;
		b_le_Bp[i] = e_Bp;
		b_le_B0s[i] = e_B0s;
		b_le_Bb[i] = e_Bb;
		b_le_nonB[i] = e_nonB;

//		//g-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFg_B0->GetBinError(i);
		e_Bp = przj_MPFg_Bp->GetBinError(i);
		e_B0s = przj_MPFg_B0s->GetBinError(i);
		e_Bb = przj_MPFg_Bb->GetBinError(i);
		e_nonB = przj_MPFg_nonB->GetBinError(i);

		g_B0[i] = e_B0;
		g_Bp[i] = e_Bp;
		g_B0s[i] = e_B0s;
		g_Bb[i] = e_Bb;
		g_nonB[i] = e_nonB;

//		//ud-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFud_B0->GetBinError(i);
		e_Bp = przj_MPFud_Bp->GetBinError(i);
		e_B0s = przj_MPFud_B0s->GetBinError(i);
		e_Bb = przj_MPFud_Bb->GetBinError(i);
		e_nonB = przj_MPFud_nonB->GetBinError(i);

		ud_B0[i] = e_B0;
		ud_Bp[i] = e_Bp;
		ud_B0s[i] = e_B0s;
		ud_Bb[i] = e_Bb;
		ud_nonB[i] = e_nonB;

//		//s-jet

//		//Different B-hadron categories
		e_B0 = przj_MPFs_B0->GetBinError(i);
		e_Bp = przj_MPFs_Bp->GetBinError(i);
		e_B0s = przj_MPFs_B0s->GetBinError(i);
		e_Bb = przj_MPFs_Bb->GetBinError(i);
		e_nonB = przj_MPFs_nonB->GetBinError(i);

		s_B0[i] = e_B0;
		s_Bp[i] = e_Bp;
		s_B0s[i] = e_B0s;
		s_Bb[i] = e_Bb;
		s_nonB[i] = e_nonB;

//		//c-jet

//		//Different B-hadron categories

		e_B0 = przj_MPFc_B0->GetBinError(i);
		e_Bp = przj_MPFc_Bp->GetBinError(i);
		e_B0s = przj_MPFc_B0s->GetBinError(i);
		e_Bb = przj_MPFc_Bb->GetBinError(i);
		e_nonB = przj_MPFc_nonB->GetBinError(i);

		c_B0[i] = e_B0;
		c_Bp[i] = e_Bp;
		c_B0s[i] = e_B0s;
		c_Bb[i] = e_Bb;
		c_nonB[i] = e_nonB;
	}
//   Double_t x[14];
   Int_t nn = 14;
//   for (Int_t i=1;i<=nn;i++) {
//     x[i] = i;
//   }

	  string amount;
	  string commonName;
	  string plotName;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

	  commonName = "diff_plots/error_MPF/error_MPF_" + amount;


   const double x[14] = {36.375, 45.75, 57.0, 73.25, 94.125, 118.875, 152.875
					, 200.75, 264.125, 345.625, 447.5, 592.75, 816.625, 1104.875};


   TGraph *grB0  = new TGraph(nn,x,B0);
   TGraph *grBp  = new TGraph(nn,x,Bp);
   TGraph *grB0s  = new TGraph(nn,x,B0s);
   TGraph *grBb  = new TGraph(nn,x,Bb);
   TGraph *grnonB  = new TGraph(nn,x,nonB);
   TCanvas *c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetLogx();

   grB0 ->SetMarkerStyle(kOpenCircle);      grB0 ->SetMarkerColor(kRed+1);
   grBp ->SetMarkerStyle(kFullSquare);      grBp ->SetMarkerColor(kBlue+1);
   grB0s->SetMarkerStyle(kFullDiamond);     grB0s->SetMarkerColor(kMagenta+2);
   grBb->SetMarkerStyle(kFullTriangleUp);   grBb->SetMarkerColor(kOrange+1);
   grnonB->SetMarkerStyle(kFullTriangleDown); grnonB->SetMarkerColor(kGreen+2);

   TLegend* lz = new TLegend(0.67,0.57,0.84,0.79);

   lz->SetBorderSize(0);
   lz->AddEntry(grB0,   "B0",   "p");
   lz->AddEntry(grBp,  "Bp",     "p");
   lz->AddEntry(grB0s,  "B0s",     "p");
   lz->AddEntry(grBb,  "Bb",     "p");
   lz->AddEntry(grnonB,  "nonB",     "p");

   grnonB->GetYaxis()->SetTitleOffset(1.2);
   grnonB->GetXaxis()->SetTitleOffset(1.1);
   grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   grnonB->GetYaxis()->SetTitle("Error of the mean");
   grnonB->GetYaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetMoreLogLabels();
   grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   grnonB->Draw("AP");
   grB0->Draw("PSAME");
   grBp->Draw("PSAME");
   grB0s->Draw("PSAME");
   grBb->Draw("PSAME");
   grnonB->Draw("PSAME");

   lz->Draw();
   plotName = commonName + "_all.pdf";
   c1->Print(plotName.c_str()); delete c1;
//   c1->Print("B0.pdf"); delete c1;

  //b-jet non-semileptonic
   TGraph *b_le_grB0  = new TGraph(nn,x,b_le_B0);
   TGraph *b_le_grBp  = new TGraph(nn,x,b_le_Bp);
   TGraph *b_le_grB0s  = new TGraph(nn,x,b_le_B0s);
   TGraph *b_le_grBb  = new TGraph(nn,x,b_le_Bb);
   TGraph *b_le_grnonB  = new TGraph(nn,x,b_le_nonB);
   TCanvas *b_le_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_le_c1->SetLeftMargin(0.13);
   b_le_c1->SetBottomMargin(0.13);

   b_le_c1->SetLogx();

   b_le_grB0 ->SetMarkerStyle(kOpenCircle);      b_le_grB0 ->SetMarkerColor(kRed+1);
   b_le_grBp ->SetMarkerStyle(kFullSquare);      b_le_grBp ->SetMarkerColor(kBlue+1);
   b_le_grB0s->SetMarkerStyle(kFullDiamond);     b_le_grB0s->SetMarkerColor(kMagenta+2);
   b_le_grBb->SetMarkerStyle(kFullTriangleUp);   b_le_grBb->SetMarkerColor(kOrange+1);
   b_le_grnonB->SetMarkerStyle(kFullTriangleDown); b_le_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_le_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_le_lz->SetBorderSize(0);
   b_le_lz->AddEntry(b_le_grB0,   "B0",   "p");
   b_le_lz->AddEntry(b_le_grBp,  "Bp",     "p");
   b_le_lz->AddEntry(b_le_grB0s,  "B0s",     "p");
   b_le_lz->AddEntry(b_le_grBb,  "Bb",     "p");
   b_le_lz->AddEntry(b_le_grnonB,  "nonB",     "p");

   b_le_grBb->GetYaxis()->SetTitleOffset(1.2);
   b_le_grBb->GetXaxis()->SetTitleOffset(1.1);
   b_le_grBb->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_le_grBb->GetYaxis()->SetTitle("Error of the mean");
   b_le_grBb->GetYaxis()->SetTitleSize(0.05);
   b_le_grBb->GetXaxis()->SetTitleSize(0.05);
   b_le_grBb->GetXaxis()->SetMoreLogLabels();
   b_le_grBb ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_le_grBb->Draw("AP");
   b_le_grBp->Draw("PSAME");
   b_le_grB0->Draw("PSAME");
   b_le_grB0s->Draw("PSAME");
   //b_le_grBb->Draw("PSAME");
   b_le_grnonB->Draw("PSAME");
   b_le_lz->Draw();

   plotName = commonName + "_b_semilep.pdf";
   b_le_c1->Print(plotName.c_str()); delete b_le_c1;

  //b-jet non-semileptonic
   TGraph *b_nl_grB0  = new TGraph(nn,x,b_nl_B0);
   TGraph *b_nl_grBp  = new TGraph(nn,x,b_nl_Bp);
   TGraph *b_nl_grB0s  = new TGraph(nn,x,b_nl_B0s);
   TGraph *b_nl_grBb  = new TGraph(nn,x,b_nl_Bb);
   TGraph *b_nl_grnonB  = new TGraph(nn,x,b_nl_nonB);
   TCanvas *b_nl_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_nl_c1->SetLeftMargin(0.13);
   b_nl_c1->SetBottomMargin(0.13);

   b_nl_c1->SetLogx();

   b_nl_grB0 ->SetMarkerStyle(kOpenCircle);      b_nl_grB0 ->SetMarkerColor(kRed+1);
   b_nl_grBp ->SetMarkerStyle(kFullSquare);      b_nl_grBp ->SetMarkerColor(kBlue+1);
   b_nl_grB0s->SetMarkerStyle(kFullDiamond);     b_nl_grB0s->SetMarkerColor(kMagenta+2);
   b_nl_grBb->SetMarkerStyle(kFullTriangleUp);   b_nl_grBb->SetMarkerColor(kOrange+1);
   b_nl_grnonB->SetMarkerStyle(kFullTriangleDown); b_nl_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_nl_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_nl_lz->SetBorderSize(0);
   b_nl_lz->AddEntry(b_nl_grB0,   "B0",   "p");
   b_nl_lz->AddEntry(b_nl_grBp,  "Bp",     "p");
   b_nl_lz->AddEntry(b_nl_grB0s,  "B0s",     "p");
   b_nl_lz->AddEntry(b_nl_grBb,  "Bb",     "p");
   b_nl_lz->AddEntry(b_nl_grnonB,  "nonB",     "p");

   b_nl_grnonB->GetYaxis()->SetTitleOffset(1.2);
   b_nl_grnonB->GetXaxis()->SetTitleOffset(1.1);
   b_nl_grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_nl_grnonB->GetYaxis()->SetTitle("Error of the mean");
   b_nl_grnonB->GetYaxis()->SetTitleSize(0.05);
   b_nl_grnonB->GetXaxis()->SetTitleSize(0.05);
   b_nl_grnonB->GetXaxis()->SetMoreLogLabels();
   b_nl_grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_nl_grnonB->Draw("AP");
   b_nl_grBp->Draw("PSAME");
   b_nl_grB0->Draw("PSAME");
   b_nl_grB0s->Draw("PSAME");
   b_nl_grBb->Draw("PSAME");
   //b_nl_grnonB->Draw("PSAME");
   b_nl_lz->Draw();

   plotName = commonName + "_b_non_semilep.pdf";
   b_nl_c1->Print(plotName.c_str()); delete b_nl_c1;

   //g-jets
   TGraph *g_grB0  = new TGraph(nn,x,g_B0);
   TGraph *g_grBp  = new TGraph(nn,x,g_Bp);
   TGraph *g_grB0s  = new TGraph(nn,x,g_B0s);
   TGraph *g_grBb  = new TGraph(nn,x,g_Bb);
   TGraph *g_grnonB  = new TGraph(nn,x,g_nonB);
   TCanvas *g_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   g_c1->SetLeftMargin(0.13);
   g_c1->SetBottomMargin(0.13);

   g_c1->SetLogx();

   g_grB0 ->SetMarkerStyle(kOpenCircle);      g_grB0 ->SetMarkerColor(kRed+1);
   g_grBp ->SetMarkerStyle(kFullSquare);      g_grBp ->SetMarkerColor(kBlue+1);
   g_grB0s->SetMarkerStyle(kFullDiamond);     g_grB0s->SetMarkerColor(kMagenta+2);
   g_grBb->SetMarkerStyle(kFullTriangleUp);   g_grBb->SetMarkerColor(kOrange+1);
   g_grnonB->SetMarkerStyle(kFullTriangleDown); g_grnonB->SetMarkerColor(kGreen+2);

   TLegend* g_lz = new TLegend(0.67,0.57,0.84,0.79);

   g_lz->SetBorderSize(0);
   g_lz->AddEntry(g_grB0,   "B0",   "p");
   g_lz->AddEntry(g_grBp,  "Bp",     "p");
   g_lz->AddEntry(g_grB0s,  "B0s",     "p");
   g_lz->AddEntry(g_grBb,  "Bb",     "p");
   g_lz->AddEntry(g_grnonB,  "nonB",     "p");

   g_grBp->GetYaxis()->SetTitleOffset(1.2);
   g_grBp->GetXaxis()->SetTitleOffset(1.1);
   g_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   g_grBp->GetYaxis()->SetTitle("Error of the mean");
   g_grBp->GetYaxis()->SetTitleSize(0.05);
   g_grBp->GetXaxis()->SetTitleSize(0.05);
   g_grBp->GetXaxis()->SetMoreLogLabels();
   g_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   g_grBp->Draw("AP");
   g_grnonB->Draw("PSAME");
   g_grB0->Draw("PSAME");
//   g_grBp->Draw("PSAME");
   g_grB0s->Draw("PSAME");
   g_grBb->Draw("PSAME");
   g_lz->Draw();

   plotName = commonName + "_g.pdf";
   g_c1->Print(plotName.c_str()); delete g_c1;

	
   //c-jets
   TGraph *c_grB0  = new TGraph(nn,x,c_B0);
   TGraph *c_grBp  = new TGraph(nn,x,c_Bp);
   TGraph *c_grB0s  = new TGraph(nn,x,c_B0s);
   TGraph *c_grBb  = new TGraph(nn,x,c_Bb);
   TGraph *c_grnonB  = new TGraph(nn,x,c_nonB);
   TCanvas *c_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c_c1->SetLeftMargin(0.13);
   c_c1->SetBottomMargin(0.13);

   c_c1->SetLogx();

   c_grB0 ->SetMarkerStyle(kOpenCircle);      c_grB0 ->SetMarkerColor(kRed+1);
   c_grBp ->SetMarkerStyle(kFullSquare);      c_grBp ->SetMarkerColor(kBlue+1);
   c_grB0s->SetMarkerStyle(kFullDiamond);     c_grB0s->SetMarkerColor(kMagenta+2);
   c_grBb->SetMarkerStyle(kFullTriangleUp);   c_grBb->SetMarkerColor(kOrange+1);
   c_grnonB->SetMarkerStyle(kFullTriangleDown); c_grnonB->SetMarkerColor(kGreen+2);

   TLegend* c_lz = new TLegend(0.67,0.57,0.84,0.79);

   c_lz->SetBorderSize(0);
   c_lz->AddEntry(c_grB0,   "B0",   "p");
   c_lz->AddEntry(c_grBp,  "Bp",     "p");
   c_lz->AddEntry(c_grB0s,  "B0s",     "p");
   c_lz->AddEntry(c_grBb,  "Bb",     "p");
   c_lz->AddEntry(c_grnonB,  "nonB",     "p");

   c_grBp->GetYaxis()->SetTitleOffset(1.2);
   c_grBp->GetXaxis()->SetTitleOffset(1.1);
   c_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   c_grBp->GetYaxis()->SetTitle("Error of the mean");
   c_grBp->GetYaxis()->SetTitleSize(0.05);
   c_grBp->GetXaxis()->SetTitleSize(0.05);
   c_grBp->GetXaxis()->SetMoreLogLabels();
   c_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   c_grBp->Draw("AP");
   c_grnonB->Draw("PSAME");
   c_grB0->Draw("PSAME");
//   c_grBp->Draw("PSAME");
   c_grB0s->Draw("PSAME");
   c_grBb->Draw("PSAME");
   c_lz->Draw();

   plotName = commonName + "_c.pdf";
   c_c1->Print(plotName.c_str()); delete c_c1;

   //s-jets
   TGraph *s_grB0  = new TGraph(nn,x,s_B0);
   TGraph *s_grBp  = new TGraph(nn,x,s_Bp);
   TGraph *s_grB0s  = new TGraph(nn,x,s_B0s);
   TGraph *s_grBb  = new TGraph(nn,x,s_Bb);
   TGraph *s_grnonB  = new TGraph(nn,x,s_nonB);
   TCanvas *s_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   s_c1->SetLeftMargin(0.13);
   s_c1->SetBottomMargin(0.13);

   s_c1->SetLogx();

   s_grB0 ->SetMarkerStyle(kOpenCircle);      s_grB0 ->SetMarkerColor(kRed+1);
   s_grBp ->SetMarkerStyle(kFullSquare);      s_grBp ->SetMarkerColor(kBlue+1);
   s_grB0s->SetMarkerStyle(kFullDiamond);     s_grB0s->SetMarkerColor(kMagenta+2);
   s_grBb->SetMarkerStyle(kFullTriangleUp);   s_grBb->SetMarkerColor(kOrange+1);
   s_grnonB->SetMarkerStyle(kFullTriangleDown); s_grnonB->SetMarkerColor(kGreen+2);

   TLegend* s_lz = new TLegend(0.67,0.57,0.84,0.79);

   s_lz->SetBorderSize(0);
   s_lz->AddEntry(s_grB0,   "B0",   "p");
   s_lz->AddEntry(s_grBp,  "Bp",     "p");
   s_lz->AddEntry(s_grB0s,  "B0s",     "p");
   s_lz->AddEntry(s_grBb,  "Bb",     "p");
   s_lz->AddEntry(s_grnonB,  "nonB",     "p");

   s_grBp->GetYaxis()->SetTitleOffset(1.2);
   s_grBp->GetXaxis()->SetTitleOffset(1.1);
   s_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   s_grBp->GetYaxis()->SetTitle("Error of the mean");
   s_grBp->GetYaxis()->SetTitleSize(0.05);
   s_grBp->GetXaxis()->SetTitleSize(0.05);
   s_grBp->GetXaxis()->SetMoreLogLabels();
   s_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   s_grBp->Draw("AP");
   s_grnonB->Draw("PSAME");
   s_grB0->Draw("PSAME");
//   s_grBp->Draw("PSAME");
   s_grB0s->Draw("PSAME");
   s_grBb->Draw("PSAME");
   s_lz->Draw();

   plotName = commonName + "_s.pdf";
   s_c1->Print(plotName.c_str()); delete s_c1;

   //ud-jets
   TGraph *ud_grB0  = new TGraph(nn,x,ud_B0);
   TGraph *ud_grBp  = new TGraph(nn,x,ud_Bp);
   TGraph *ud_grB0s  = new TGraph(nn,x,ud_B0s);
   TGraph *ud_grBb  = new TGraph(nn,x,ud_Bb);
   TGraph *ud_grnonB  = new TGraph(nn,x,ud_nonB);
   TCanvas *ud_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   ud_c1->SetLeftMargin(0.13);
   ud_c1->SetBottomMargin(0.13);

   ud_c1->SetLogx();

   ud_grB0 ->SetMarkerStyle(kOpenCircle);      ud_grB0 ->SetMarkerColor(kRed+1);
   ud_grBp ->SetMarkerStyle(kFullSquare);      ud_grBp ->SetMarkerColor(kBlue+1);
   ud_grB0s->SetMarkerStyle(kFullDiamond);     ud_grB0s->SetMarkerColor(kMagenta+2);
   ud_grBb->SetMarkerStyle(kFullTriangleUp);   ud_grBb->SetMarkerColor(kOrange+1);
   ud_grnonB->SetMarkerStyle(kFullTriangleDown); ud_grnonB->SetMarkerColor(kGreen+2);

   TLegend* ud_lz = new TLegend(0.67,0.57,0.84,0.79);

   ud_lz->SetBorderSize(0);
   ud_lz->AddEntry(ud_grB0,   "B0",   "p");
   ud_lz->AddEntry(ud_grBp,  "Bp",     "p");
   ud_lz->AddEntry(ud_grB0s,  "B0s",     "p");
   ud_lz->AddEntry(ud_grBb,  "Bb",     "p");
   ud_lz->AddEntry(ud_grnonB,  "nonB",     "p");

   ud_grBp->GetYaxis()->SetTitleOffset(1.2);
   ud_grBp->GetXaxis()->SetTitleOffset(1.1);
   ud_grBp->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   ud_grBp->GetYaxis()->SetTitle("Error of the mean");
   ud_grBp->GetYaxis()->SetTitleSize(0.05);
   ud_grBp->GetXaxis()->SetTitleSize(0.05);
   ud_grBp->GetXaxis()->SetMoreLogLabels();
   ud_grBp ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   ud_grBp->Draw("AP");
   ud_grnonB->Draw("PSAME");
   ud_grB0->Draw("PSAME");
//   ud_grBp->Draw("PSAME");
   ud_grB0s->Draw("PSAME");
   ud_grBb->Draw("PSAME");
   ud_lz->Draw();

   plotName = commonName + "_ud.pdf";
   ud_c1->Print(plotName.c_str()); delete ud_c1;
  }

  if (plot_bin_w_mpf) {

	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);

	  // 
   	  Int_t n = 14;
   	  Double_t B0[n], Bp[n], B0s[n], Bb[n], nonB[n];
   	  Double_t b_nl_B0[n], b_nl_Bp[n], b_nl_B0s[n], b_nl_Bb[n], b_nl_nonB[n];
   	  Double_t b_le_B0[n], b_le_Bp[n], b_le_B0s[n], b_le_Bb[n], b_le_nonB[n];
   	  Double_t c_B0[n], c_Bp[n], c_B0s[n], c_Bb[n], c_nonB[n];
   	  Double_t s_B0[n], s_Bp[n], s_B0s[n], s_Bb[n], s_nonB[n];
   	  Double_t ud_B0[n], ud_Bp[n], ud_B0s[n], ud_Bb[n], ud_nonB[n];
   	  Double_t g_B0[n], g_Bp[n], g_B0s[n], g_Bb[n], g_nonB[n];
	  double w_B0; double w_Bp; double w_B0s; double w_Bb; double w_nonB;

	  Double_t xx[n];
	
	for (int i = 1; i < 15; i++) {
		w_B0 = przj_MPF_B0->GetBinEntries(i);
		w_Bp = przj_MPF_Bp->GetBinEntries(i);
		w_B0s = przj_MPF_B0s->GetBinEntries(i);
		w_Bb = przj_MPF_Bb->GetBinEntries(i);
		w_nonB = przj_MPF_nonB->GetBinEntries(i);

		B0[i] = w_B0;
		Bp[i] = w_Bp;
		B0s[i] = w_B0s;
		Bb[i] = w_Bb;
		nonB[i] = w_nonB;
		
		//b-jet semileptonic

	    //Different B-hadron categories
		w_B0 = przj_MPFb_le_B0->GetBinEntries(i);
		w_Bp = przj_MPFb_le_Bp->GetBinEntries(i);
		w_B0s = przj_MPFb_le_B0s->GetBinEntries(i);
		w_Bb = przj_MPFb_le_Bb->GetBinEntries(i);
		w_nonB = przj_MPFb_le_nonB->GetBinEntries(i);

		b_nl_B0[i] = w_B0;
		b_nl_Bp[i] = w_Bp;
		b_nl_B0s[i] = w_B0s;
		b_nl_Bb[i] = w_Bb;
		b_nl_nonB[i] = w_nonB;

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		w_B0 = przj_MPFb_nl_B0->GetBinEntries(i);
		w_Bp = przj_MPFb_nl_Bp->GetBinEntries(i);
		w_B0s = przj_MPFb_nl_B0s->GetBinEntries(i);
		w_Bb = przj_MPFb_nl_Bb->GetBinEntries(i);
		w_nonB = przj_MPFb_nl_nonB->GetBinEntries(i);

		b_le_B0[i] = w_B0;
		b_le_Bp[i] = w_Bp;
		b_le_B0s[i] = w_B0s;
		b_le_Bb[i] = w_Bb;
		b_le_nonB[i] = w_nonB;

//		//g-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFg_B0->GetBinEntries(i);
		w_Bp = przj_MPFg_Bp->GetBinEntries(i);
		w_B0s = przj_MPFg_B0s->GetBinEntries(i);
		w_Bb = przj_MPFg_Bb->GetBinEntries(i);
		w_nonB = przj_MPFg_nonB->GetBinEntries(i);

		g_B0[i] = w_B0;
		g_Bp[i] = w_Bp;
		g_B0s[i] = w_B0s;
		g_Bb[i] = w_Bb;
		g_nonB[i] = w_nonB;

//		//ud-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFud_B0->GetBinEntries(i);
		w_Bp = przj_MPFud_Bp->GetBinEntries(i);
		w_B0s = przj_MPFud_B0s->GetBinEntries(i);
		w_Bb = przj_MPFud_Bb->GetBinEntries(i);
		w_nonB = przj_MPFud_nonB->GetBinEntries(i);

		ud_B0[i] = w_B0;
		ud_Bp[i] = w_Bp;
		ud_B0s[i] = w_B0s;
		ud_Bb[i] = w_Bb;
		ud_nonB[i] = w_nonB;

//		//s-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFs_B0->GetBinEntries(i);
		w_Bp = przj_MPFs_Bp->GetBinEntries(i);
		w_B0s = przj_MPFs_B0s->GetBinEntries(i);
		w_Bb = przj_MPFs_Bb->GetBinEntries(i);
		w_nonB = przj_MPFs_nonB->GetBinEntries(i);

		s_B0[i] = w_B0;
		s_Bp[i] = w_Bp;
		s_B0s[i] = w_B0s;
		s_Bb[i] = w_Bb;
		s_nonB[i] = w_nonB;

//		//c-jet

//		//Different B-hadron categories

		w_B0 = przj_MPFc_B0->GetBinEntries(i);
		w_Bp = przj_MPFc_Bp->GetBinEntries(i);
		w_B0s = przj_MPFc_B0s->GetBinEntries(i);
		w_Bb = przj_MPFc_Bb->GetBinEntries(i);
		w_nonB = przj_MPFc_nonB->GetBinEntries(i);

		c_B0[i] = w_B0;
		c_Bp[i] = w_Bp;
		c_B0s[i] = w_B0s;
		c_Bb[i] = w_Bb;
		c_nonB[i] = w_nonB;
	}

	  string amount;
	  string commonName;
	  string plotName;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

	  commonName = "diff_plots/w_sums/w_sum_MPF_" + amount;

//   Double_t x[14];
   Int_t nn = 14;
//   for (Int_t i=1;i<=nn;i++) {
//     x[i] = i;
//   }

   const double x[14] = {36.375, 45.75, 57.0, 73.25, 94.125, 118.875, 152.875
					, 200.75, 264.125, 345.625, 447.5, 592.75, 816.625, 1104.875};


   TGraph *grB0  = new TGraph(nn,x,B0);
   TGraph *grBp  = new TGraph(nn,x,Bp);
   TGraph *grB0s  = new TGraph(nn,x,B0s);
   TGraph *grBb  = new TGraph(nn,x,Bb);
   TGraph *grnonB  = new TGraph(nn,x,nonB);
   TCanvas *c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c1->SetLeftMargin(0.13);
   c1->SetBottomMargin(0.13);
   c1->SetLogx();

   grB0 ->SetMarkerStyle(kOpenCircle);      grB0 ->SetMarkerColor(kRed+1);
   grBp ->SetMarkerStyle(kFullSquare);      grBp ->SetMarkerColor(kBlue+1);
   grB0s->SetMarkerStyle(kFullDiamond);     grB0s->SetMarkerColor(kMagenta+2);
   grBb->SetMarkerStyle(kFullTriangleUp);   grBb->SetMarkerColor(kOrange+1);
   grnonB->SetMarkerStyle(kFullTriangleDown); grnonB->SetMarkerColor(kGreen+2);

   TLegend* lz = new TLegend(0.67,0.57,0.84,0.79);

   lz->SetBorderSize(0);
   lz->AddEntry(grB0,   "B0",   "p");
   lz->AddEntry(grBp,  "Bp",     "p");
   lz->AddEntry(grB0s,  "B0s",     "p");
   lz->AddEntry(grBb,  "Bb",     "p");
   lz->AddEntry(grnonB,  "nonB",     "p");

   grnonB->GetYaxis()->SetTitleOffset(1.1);
   grnonB->GetXaxis()->SetTitleOffset(1.1);
   grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   grnonB->GetYaxis()->SetTitle("Sum of weights");
   grnonB->GetYaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetTitleSize(0.05);
   grnonB->GetXaxis()->SetMoreLogLabels();
   grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   grnonB->Draw("AP");
   grB0->Draw("PSAME");
   grBp->Draw("PSAME");
   grB0s->Draw("PSAME");
   grBb->Draw("PSAME");
   grnonB->Draw("PSAME");

   lz->Draw();

   plotName = commonName + "_all.pdf";
   c1->Print(plotName.c_str()); delete c1;
//   c1->Print("B0.pdf"); delete c1;

  //b-jet non-semileptonic
   TGraph *b_le_grB0  = new TGraph(nn,x,b_le_B0);
   TGraph *b_le_grBp  = new TGraph(nn,x,b_le_Bp);
   TGraph *b_le_grB0s  = new TGraph(nn,x,b_le_B0s);
   TGraph *b_le_grBb  = new TGraph(nn,x,b_le_Bb);
   TGraph *b_le_grnonB  = new TGraph(nn,x,b_le_nonB);
   TCanvas *b_le_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_le_c1->SetLeftMargin(0.13);
   b_le_c1->SetBottomMargin(0.13);

   b_le_c1->SetLogx();

   b_le_grB0 ->SetMarkerStyle(kOpenCircle);      b_le_grB0 ->SetMarkerColor(kRed+1);
   b_le_grBp ->SetMarkerStyle(kFullSquare);      b_le_grBp ->SetMarkerColor(kBlue+1);
   b_le_grB0s->SetMarkerStyle(kFullDiamond);     b_le_grB0s->SetMarkerColor(kMagenta+2);
   b_le_grBb->SetMarkerStyle(kFullTriangleUp);   b_le_grBb->SetMarkerColor(kOrange+1);
   b_le_grnonB->SetMarkerStyle(kFullTriangleDown); b_le_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_le_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_le_lz->SetBorderSize(0);
   b_le_lz->AddEntry(b_le_grB0,   "B0",   "p");
   b_le_lz->AddEntry(b_le_grBp,  "Bp",     "p");
   b_le_lz->AddEntry(b_le_grB0s,  "B0s",     "p");
   b_le_lz->AddEntry(b_le_grBb,  "Bb",     "p");
   b_le_lz->AddEntry(b_le_grnonB,  "nonB",     "p");

   b_le_grB0->GetYaxis()->SetTitleOffset(1.1);
   b_le_grB0->GetXaxis()->SetTitleOffset(1.1);
   b_le_grB0->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_le_grB0->GetYaxis()->SetTitle("Sum of weights");
   b_le_grB0->GetYaxis()->SetTitleSize(0.05);
   b_le_grB0->GetXaxis()->SetTitleSize(0.05);
   b_le_grB0->GetXaxis()->SetMoreLogLabels();
   b_le_grB0 ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_le_grB0->Draw("AP");
   b_le_grBp->Draw("PSAME");
   b_le_grB0s->Draw("PSAME");
   b_le_grBb->Draw("PSAME");
   b_le_grnonB->Draw("PSAME");
   b_le_lz->Draw();

   plotName = commonName + "_b_semilep.pdf";
   b_le_c1->Print(plotName.c_str()); delete b_le_c1;

  //b-jet non-semileptonic
   TGraph *b_nl_grB0  = new TGraph(nn,x,b_nl_B0);
   TGraph *b_nl_grBp  = new TGraph(nn,x,b_nl_Bp);
   TGraph *b_nl_grB0s  = new TGraph(nn,x,b_nl_B0s);
   TGraph *b_nl_grBb  = new TGraph(nn,x,b_nl_Bb);
   TGraph *b_nl_grnonB  = new TGraph(nn,x,b_nl_nonB);
   TCanvas *b_nl_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   b_nl_c1->SetLeftMargin(0.13);
   b_nl_c1->SetBottomMargin(0.13);


   b_nl_c1->SetLogx();

   b_nl_grB0 ->SetMarkerStyle(kOpenCircle);      b_nl_grB0 ->SetMarkerColor(kRed+1);
   b_nl_grBp ->SetMarkerStyle(kFullSquare);      b_nl_grBp ->SetMarkerColor(kBlue+1);
   b_nl_grB0s->SetMarkerStyle(kFullDiamond);     b_nl_grB0s->SetMarkerColor(kMagenta+2);
   b_nl_grBb->SetMarkerStyle(kFullTriangleUp);   b_nl_grBb->SetMarkerColor(kOrange+1);
   b_nl_grnonB->SetMarkerStyle(kFullTriangleDown); b_nl_grnonB->SetMarkerColor(kGreen+2);

   TLegend* b_nl_lz = new TLegend(0.67,0.57,0.84,0.79);

   b_nl_lz->SetBorderSize(0);
   b_nl_lz->AddEntry(b_nl_grB0,   "B0",   "p");
   b_nl_lz->AddEntry(b_nl_grBp,  "Bp",     "p");
   b_nl_lz->AddEntry(b_nl_grB0s,  "B0s",     "p");
   b_nl_lz->AddEntry(b_nl_grBb,  "Bb",     "p");
   b_nl_lz->AddEntry(b_nl_grnonB,  "nonB",     "p");

   b_nl_grB0->GetYaxis()->SetTitleOffset(1.1);
   b_nl_grB0->GetXaxis()->SetTitleOffset(1.1);
   b_nl_grB0->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   b_nl_grB0->GetYaxis()->SetTitle("Sum of weights");
   b_nl_grB0->GetYaxis()->SetTitleSize(0.05);
   b_nl_grB0->GetXaxis()->SetTitleSize(0.05);
   b_nl_grB0->GetXaxis()->SetMoreLogLabels();
   b_nl_grB0 ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   b_nl_grB0->Draw("AP");
   b_nl_grBp->Draw("PSAME");
   b_nl_grB0s->Draw("PSAME");
   b_nl_grBb->Draw("PSAME");
   b_nl_grnonB->Draw("PSAME");
   b_nl_lz->Draw();

   plotName = commonName + "_b_non_semilep.pdf";
   b_nl_c1->Print(plotName.c_str()); delete b_nl_c1;

   //g-jets
   TGraph *g_grB0  = new TGraph(nn,x,g_B0);
   TGraph *g_grBp  = new TGraph(nn,x,g_Bp);
   TGraph *g_grB0s  = new TGraph(nn,x,g_B0s);
   TGraph *g_grBb  = new TGraph(nn,x,g_Bb);
   TGraph *g_grnonB  = new TGraph(nn,x,g_nonB);
   TCanvas *g_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   g_c1->SetLeftMargin(0.13);
   g_c1->SetBottomMargin(0.13);


   g_c1->SetLogx();

   g_grB0 ->SetMarkerStyle(kOpenCircle);      g_grB0 ->SetMarkerColor(kRed+1);
   g_grBp ->SetMarkerStyle(kFullSquare);      g_grBp ->SetMarkerColor(kBlue+1);
   g_grB0s->SetMarkerStyle(kFullDiamond);     g_grB0s->SetMarkerColor(kMagenta+2);
   g_grBb->SetMarkerStyle(kFullTriangleUp);   g_grBb->SetMarkerColor(kOrange+1);
   g_grnonB->SetMarkerStyle(kFullTriangleDown); g_grnonB->SetMarkerColor(kGreen+2);

   TLegend* g_lz = new TLegend(0.67,0.57,0.84,0.79);

   g_lz->SetBorderSize(0);
   g_lz->AddEntry(g_grB0,   "B0",   "p");
   g_lz->AddEntry(g_grBp,  "Bp",     "p");
   g_lz->AddEntry(g_grB0s,  "B0s",     "p");
   g_lz->AddEntry(g_grBb,  "Bb",     "p");
   g_lz->AddEntry(g_grnonB,  "nonB",     "p");

   g_grnonB->GetYaxis()->SetTitleOffset(1.1);
   g_grnonB->GetXaxis()->SetTitleOffset(1.1);
   g_grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   g_grnonB->GetYaxis()->SetTitle("Sum of weights");
   g_grnonB->GetYaxis()->SetTitleSize(0.05);
   g_grnonB->GetXaxis()->SetTitleSize(0.05);
   g_grnonB->GetXaxis()->SetMoreLogLabels();
   g_grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   g_grnonB->Draw("AP");
   g_grB0->Draw("PSAME");
   g_grBp->Draw("PSAME");
   g_grB0s->Draw("PSAME");
   g_grBb->Draw("PSAME");
   g_lz->Draw();

   plotName = commonName + "_g.pdf";
   g_c1->Print(plotName.c_str()); delete g_c1;

	
   //c-jets
   TGraph *c_grB0  = new TGraph(nn,x,c_B0);
   TGraph *c_grBp  = new TGraph(nn,x,c_Bp);
   TGraph *c_grB0s  = new TGraph(nn,x,c_B0s);
   TGraph *c_grBb  = new TGraph(nn,x,c_Bb);
   TGraph *c_grnonB  = new TGraph(nn,x,c_nonB);
   TCanvas *c_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   c_c1->SetLeftMargin(0.13);
   c_c1->SetBottomMargin(0.13);

   c_c1->SetLogx();

   c_grB0 ->SetMarkerStyle(kOpenCircle);      c_grB0 ->SetMarkerColor(kRed+1);
   c_grBp ->SetMarkerStyle(kFullSquare);      c_grBp ->SetMarkerColor(kBlue+1);
   c_grB0s->SetMarkerStyle(kFullDiamond);     c_grB0s->SetMarkerColor(kMagenta+2);
   c_grBb->SetMarkerStyle(kFullTriangleUp);   c_grBb->SetMarkerColor(kOrange+1);
   c_grnonB->SetMarkerStyle(kFullTriangleDown); c_grnonB->SetMarkerColor(kGreen+2);

   TLegend* c_lz = new TLegend(0.67,0.57,0.84,0.79);

   c_lz->SetBorderSize(0);
   c_lz->AddEntry(c_grB0,   "B0",   "p");
   c_lz->AddEntry(c_grBp,  "Bp",     "p");
   c_lz->AddEntry(c_grB0s,  "B0s",     "p");
   c_lz->AddEntry(c_grBb,  "Bb",     "p");
   c_lz->AddEntry(c_grnonB,  "nonB",     "p");

   c_grnonB->GetYaxis()->SetTitleOffset(1.1);
   c_grnonB->GetXaxis()->SetTitleOffset(1.1);
   c_grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   c_grnonB->GetYaxis()->SetTitle("Sum of weights");
   c_grnonB->GetYaxis()->SetTitleSize(0.05);
   c_grnonB->GetXaxis()->SetTitleSize(0.05);
   c_grnonB->GetXaxis()->SetMoreLogLabels();
   c_grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   c_grnonB->Draw("AP");
   c_grB0->Draw("PSAME");
   c_grBp->Draw("PSAME");
   c_grB0s->Draw("PSAME");
   c_grBb->Draw("PSAME");
   c_lz->Draw();

   plotName = commonName + "_c.pdf";
   c_c1->Print(plotName.c_str()); delete c_c1;

   //s-jets
   TGraph *s_grB0  = new TGraph(nn,x,s_B0);
   TGraph *s_grBp  = new TGraph(nn,x,s_Bp);
   TGraph *s_grB0s  = new TGraph(nn,x,s_B0s);
   TGraph *s_grBb  = new TGraph(nn,x,s_Bb);
   TGraph *s_grnonB  = new TGraph(nn,x,s_nonB);
   TCanvas *s_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   s_c1->SetLeftMargin(0.13);
   s_c1->SetBottomMargin(0.13);


   s_c1->SetLogx();

   s_grB0 ->SetMarkerStyle(kOpenCircle);      s_grB0 ->SetMarkerColor(kRed+1);
   s_grBp ->SetMarkerStyle(kFullSquare);      s_grBp ->SetMarkerColor(kBlue+1);
   s_grB0s->SetMarkerStyle(kFullDiamond);     s_grB0s->SetMarkerColor(kMagenta+2);
   s_grBb->SetMarkerStyle(kFullTriangleUp);   s_grBb->SetMarkerColor(kOrange+1);
   s_grnonB->SetMarkerStyle(kFullTriangleDown); s_grnonB->SetMarkerColor(kGreen+2);

   TLegend* s_lz = new TLegend(0.67,0.57,0.84,0.79);

   s_lz->SetBorderSize(0);
   s_lz->AddEntry(s_grB0,   "B0",   "p");
   s_lz->AddEntry(s_grBp,  "Bp",     "p");
   s_lz->AddEntry(s_grB0s,  "B0s",     "p");
   s_lz->AddEntry(s_grBb,  "Bb",     "p");
   s_lz->AddEntry(s_grnonB,  "nonB",     "p");

   s_grnonB->GetYaxis()->SetTitleOffset(1.1);
   s_grnonB->GetXaxis()->SetTitleOffset(1.1);
   s_grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   s_grnonB->GetYaxis()->SetTitle("Sum of weights");
   s_grnonB->GetYaxis()->SetTitleSize(0.05);
   s_grnonB->GetXaxis()->SetTitleSize(0.05);
   s_grnonB->GetXaxis()->SetMoreLogLabels();
   s_grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   s_grnonB->Draw("AP");
   s_grB0->Draw("PSAME");
   s_grBp->Draw("PSAME");
   s_grB0s->Draw("PSAME");
   s_grBb->Draw("PSAME");
   s_lz->Draw();

   plotName = commonName + "_s.pdf";
   s_c1->Print(plotName.c_str()); delete s_c1;

   //ud-jets
   TGraph *ud_grB0  = new TGraph(nn,x,ud_B0);
   TGraph *ud_grBp  = new TGraph(nn,x,ud_Bp);
   TGraph *ud_grB0s  = new TGraph(nn,x,ud_B0s);
   TGraph *ud_grBb  = new TGraph(nn,x,ud_Bb);
   TGraph *ud_grnonB  = new TGraph(nn,x,ud_nonB);
   TCanvas *ud_c1 = new TCanvas("c1","Graph Draw Options",500,400);
   ud_c1->SetLeftMargin(0.13);
   ud_c1->SetBottomMargin(0.13);

   ud_c1->SetLogx();

   ud_grB0 ->SetMarkerStyle(kOpenCircle);      ud_grB0 ->SetMarkerColor(kRed+1);
   ud_grBp ->SetMarkerStyle(kFullSquare);      ud_grBp ->SetMarkerColor(kBlue+1);
   ud_grB0s->SetMarkerStyle(kFullDiamond);     ud_grB0s->SetMarkerColor(kMagenta+2);
   ud_grBb->SetMarkerStyle(kFullTriangleUp);   ud_grBb->SetMarkerColor(kOrange+1);
   ud_grnonB->SetMarkerStyle(kFullTriangleDown); ud_grnonB->SetMarkerColor(kGreen+2);

   TLegend* ud_lz = new TLegend(0.67,0.57,0.84,0.79);

   ud_lz->SetBorderSize(0);
   ud_lz->AddEntry(ud_grB0,   "B0",   "p");
   ud_lz->AddEntry(ud_grBp,  "Bp",     "p");
   ud_lz->AddEntry(ud_grB0s,  "B0s",     "p");
   ud_lz->AddEntry(ud_grBb,  "Bb",     "p");
   ud_lz->AddEntry(ud_grnonB,  "nonB",     "p");

   ud_grnonB->GetYaxis()->SetTitleOffset(1.1);
   ud_grnonB->GetXaxis()->SetTitleOffset(1.1);
   ud_grnonB->GetXaxis()->SetTitle("p_{T,tag}^{reco} (GeV)");
   ud_grnonB->GetYaxis()->SetTitle("Sum of weights");
   ud_grnonB->GetYaxis()->SetTitleSize(0.05);
   ud_grnonB->GetXaxis()->SetTitleSize(0.05);
   ud_grnonB->GetXaxis()->SetMoreLogLabels();
   ud_grnonB ->GetXaxis()->SetNoExponent();
   gPad->SetTickx();   gPad->SetTicky();

   ud_grnonB->Draw("AP");
   ud_grB0->Draw("PSAME");
   ud_grBp->Draw("PSAME");
   ud_grB0s->Draw("PSAME");
   ud_grBb->Draw("PSAME");
   ud_lz->Draw();

   plotName = commonName + "_ud.pdf";
   ud_c1->Print(plotName.c_str()); delete ud_c1;
 
  }

  if (test) { 

	TFile* fzj = TFile::Open(OpenName.c_str());
	TFile* fzj_var = TFile::Open(var_OpenName.c_str());
  	TProfile *przj_MPFud=0;
 	fzj->GetObject("prMPFud", przj_MPFud);

	vector<Double_t>* MPFud_vector = new vector<Double_t>();
	fzj_var->GetObject("MPFud_vector", MPFud_vector);

	for (int i = 1; i < 15; i++) {
		cout << "Tprofile: " << przj_MPFud->GetBinEntries(i) << endl;
		//cout << "test_vec: " << (*MPFud_vector)[i-1] << endl;
	    przj_MPFud->GetXaxis()->SetRange(i,i);
	    double stats1[TH1::kNstat];
	    przj_MPFud->GetStats(stats1);
	    cout << stats1[0] << endl;
	}
  }

  if (mpf_plot_ver2) {

	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  //The weighted sample

	  TProfile *przj_MPF_var=0;   TProfile *przj_MPFc_var=0;
	  TProfile *przj_MPFs_var=0; TProfile *przj_MPFud_var=0; TProfile *przj_MPFg_var=0;
	  //TProfile *przj_MPFb_var=0;
	  TProfile *przj_MPFb_nl_var=0;
	  TProfile *przj_MPFb_le_var=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0_var=0; TProfile *przj_MPFc_B0_var=0;
	  TProfile *przj_MPFs_B0_var=0; TProfile *przj_MPFud_B0_var=0; TProfile *przj_MPFg_B0_var=0;
	  //TProfile *przj_MPFb_B0_var=0;
	  TProfile *przj_MPFb_nl_B0_var=0;
	  TProfile *przj_MPFb_le_B0_var=0;

	  TProfile *przj_MPF_Bp_var=0; TProfile *przj_MPFc_Bp_var=0;
	  TProfile *przj_MPFs_Bp_var=0; TProfile *przj_MPFud_Bp_var=0; TProfile *przj_MPFg_Bp_var=0;
	  //TProfile *przj_MPFb_Bp_var=0;
	  TProfile *przj_MPFb_nl_Bp_var=0;
	  TProfile *przj_MPFb_le_Bp_var=0;

	  TProfile *przj_MPF_B0s_var=0; TProfile *przj_MPFc_B0s_var=0;
	  TProfile *przj_MPFs_B0s_var=0; TProfile *przj_MPFud_B0s_var=0; TProfile *przj_MPFg_B0s_var=0;
	  //TProfile *przj_MPFb_B0s_var=0;
	  TProfile *przj_MPFb_nl_B0s_var=0;
	  TProfile *przj_MPFb_le_B0s_var=0;

	  TProfile *przj_MPF_Bb_var=0; TProfile *przj_MPFc_Bb_var=0;
	  TProfile *przj_MPFs_Bb_var=0; TProfile *przj_MPFud_Bb_var=0; TProfile *przj_MPFg_Bb_var=0;
	  //TProfile *przj_MPFb_Bb_var=0;
	  TProfile *przj_MPFb_nl_Bb_var=0;
	  TProfile *przj_MPFb_le_Bb_var=0;

	  TProfile *przj_MPF_nonB_var=0; TProfile *przj_MPFc_nonB_var=0;
	  TProfile *przj_MPFs_nonB_var=0; TProfile *przj_MPFud_nonB_var=0; TProfile *przj_MPFg_nonB_var=0;
	  //TProfile *przj_MPFb_nonB_var=0;
	  TProfile *przj_MPFb_nl_nonB_var=0;
	  TProfile *przj_MPFb_le_nonB_var=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);

      //Read the weighted sample
	
	  fzj_var->GetObject("prMPF",   przj_MPF_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_var);
	  fzj_var->GetObject("prMPFb_nl",  przj_MPFb_nl_var);
	  fzj_var->GetObject("prMPFb_le",  przj_MPFb_le_var);
	  fzj_var->GetObject("prMPFc",  przj_MPFc_var);
	  fzj_var->GetObject("prMPFs",  przj_MPFs_var);
	  fzj_var->GetObject("prMPFud", przj_MPFud_var);
	  fzj_var->GetObject("prMPFg",  przj_MPFg_var);

	  //Different B-hadron categories

	  fzj_var->GetObject("prMPF_B0",   przj_MPF_B0_var);
	  //fzj_var->GetObject("prMPFb_B0",  przj_MPFb_B0_var);
	  fzj_var->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0_var);
	  fzj_var->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0_var);
	  fzj_var->GetObject("prMPFc_B0",  przj_MPFc_B0_var);
	  fzj_var->GetObject("prMPFs_B0",  przj_MPFs_B0_var);
	  fzj_var->GetObject("prMPFud_B0", przj_MPFud_B0_var);
	  fzj_var->GetObject("prMPFg_B0",  przj_MPFg_B0_var);

	  fzj_var->GetObject("prMPF_Bp",   przj_MPF_Bp_var);
	  //fzj_var->GetObject("prMPFb_Bp",  przj_MPFb_Bp_var);
	  fzj_var->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp_var);
	  fzj_var->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp_var);
	  fzj_var->GetObject("prMPFc_Bp",  przj_MPFc_Bp_var);
	  fzj_var->GetObject("prMPFs_Bp",  przj_MPFs_Bp_var);
	  fzj_var->GetObject("prMPFud_Bp", przj_MPFud_Bp_var);
	  fzj_var->GetObject("prMPFg_Bp",  przj_MPFg_Bp_var);

	  fzj_var->GetObject("prMPF_B0s",   przj_MPF_B0s_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_B0s_var);
	  fzj_var->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s_var);
	  fzj_var->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s_var);
	  fzj_var->GetObject("prMPFc_B0s",  przj_MPFc_B0s_var);
	  fzj_var->GetObject("prMPFs_B0s",  przj_MPFs_B0s_var);
	  fzj_var->GetObject("prMPFud_B0s", przj_MPFud_B0s_var);
	  fzj_var->GetObject("prMPFg_B0s",  przj_MPFg_B0s_var);

	  fzj_var->GetObject("prMPF_Bb",   przj_MPF_Bb_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_Bb_var);
	  fzj_var->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb_var);
	  fzj_var->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb_var);
	  fzj_var->GetObject("prMPFc_Bb",  przj_MPFc_Bb_var);
	  fzj_var->GetObject("prMPFs_Bb",  przj_MPFs_Bb_var);
	  fzj_var->GetObject("prMPFud_Bb", przj_MPFud_Bb_var);
	  fzj_var->GetObject("prMPFg_Bb",  przj_MPFg_Bb_var);

	  fzj_var->GetObject("prMPF_nonB",   przj_MPF_nonB_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_nonB_var);
	  fzj_var->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB_var);
	  fzj_var->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB_var);
	  fzj_var->GetObject("prMPFc_nonB",  przj_MPFc_nonB_var);
	  fzj_var->GetObject("prMPFs_nonB",  przj_MPFs_nonB_var);
	  fzj_var->GetObject("prMPFud_nonB", przj_MPFud_nonB_var);
	  fzj_var->GetObject("prMPFg_nonB",  przj_MPFg_nonB_var);

	  TH1D* hzj_MPF   = przj_MPF  ->ProjectionX();
	  //TH1D* hzj_MPFb  = przj_MPFb ->ProjectionX();
	  TH1D* hzj_MPFb_nl  = przj_MPFb_nl ->ProjectionX();
	  TH1D* hzj_MPFb_le  = przj_MPFb_le ->ProjectionX();
	  TH1D* hzj_MPFc  = przj_MPFc ->ProjectionX();
	  TH1D* hzj_MPFs  = przj_MPFs ->ProjectionX();
	  TH1D* hzj_MPFud = przj_MPFud->ProjectionX();
	  TH1D* hzj_MPFg  = przj_MPFg ->ProjectionX();

	  TH1D* hzj_MPF_var   = przj_MPF_var  ->ProjectionX();
	  //TH1D* hzj_MPFb_var  = przj_MPFb_var ->ProjectionX();
	  TH1D* hzj_MPFb_nl_var  = przj_MPFb_nl_var ->ProjectionX();
	  TH1D* hzj_MPFb_le_var  = przj_MPFb_le_var ->ProjectionX();
	  TH1D* hzj_MPFc_var  = przj_MPFc_var ->ProjectionX();
	  TH1D* hzj_MPFs_var  = przj_MPFs_var ->ProjectionX();
	  TH1D* hzj_MPFud_var = przj_MPFud_var->ProjectionX();
	  TH1D* hzj_MPFg_var  = przj_MPFg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_MPF->Clone();
	  //TH1D* diffb = (TH1D*) hzj_MPFb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_MPFb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_MPFb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_MPFc->Clone();
	  TH1D* diffs = (TH1D*) hzj_MPFs->Clone();
	  TH1D* diffud = (TH1D*) hzj_MPFud->Clone();
	  TH1D* diffg = (TH1D*) hzj_MPFg->Clone();

	  diff->Add(hzj_MPF_var,-1);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Add(hzj_MPFb_nl_var,-1);
	  diffb_le->Add(hzj_MPFb_le_var,-1);
	  diffc->Add(hzj_MPFc_var,-1);
	  diffs->Add(hzj_MPFs_var,-1);
	  diffud->Add(hzj_MPFud_var,-1);
	  diffg->Add(hzj_MPFg_var,-1);

	  diff->Divide(hzj_MPF);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Divide(hzj_MPFb_nl);
	  diffb_le->Divide(hzj_MPFb_le);
	  diffc->Divide(hzj_MPFc);
	  diffs->Divide(hzj_MPFs);
	  diffud->Divide(hzj_MPFud);
	  diffg->Divide(hzj_MPFg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	  double val_std_B0; double val_std_Bp; double val_std_B0s; double val_std_Bb; double val_std_nonB;
	  double w_B0; double w_Bp; double w_B0s; double w_Bb; double w_nonB;
	  double w_B0_var; double w_Bp_var; double w_B0s_var; double w_Bb_var; double w_nonB_var;
	  double norm_tot_w; double var_tot_w;

	  for (int i = 1; i < 15; i++){

		//all jets

	    //Different B-hadron categories
		w_B0 = przj_MPF_B0->GetBinEntries(i);
		w_Bp = przj_MPF_Bp->GetBinEntries(i);
		w_B0s = przj_MPF_B0s->GetBinEntries(i);
		w_Bb = przj_MPF_Bb->GetBinEntries(i);
		w_nonB = przj_MPF_nonB->GetBinEntries(i);

		w_B0_var = przj_MPF_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPF_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPF_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPF_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPF_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPF_B0->GetBinError(i);
		val_std_Bp = przj_MPF_Bp->GetBinError(i);
		val_std_B0s = przj_MPF_B0s->GetBinError(i);
		val_std_Bb = przj_MPF_Bb->GetBinError(i);
		val_std_nonB = przj_MPF_nonB->GetBinError(i);
 
	    error = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

		//b-jet semileptonic

	    //Different B-hadron categories
		w_B0 = przj_MPFb_le_B0->GetBinEntries(i);
		w_Bp = przj_MPFb_le_Bp->GetBinEntries(i);
		w_B0s = przj_MPFb_le_B0s->GetBinEntries(i);
		w_Bb = przj_MPFb_le_Bb->GetBinEntries(i);
		w_nonB = przj_MPFb_le_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFb_le_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFb_le_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFb_le_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFb_le_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFb_le_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFb_le_B0->GetBinError(i);
		val_std_Bp = przj_MPFb_le_Bp->GetBinError(i);
		val_std_B0s = przj_MPFb_le_B0s->GetBinError(i);
		val_std_Bb = przj_MPFb_le_Bb->GetBinError(i);
		val_std_nonB = przj_MPFb_le_nonB->GetBinError(i);
 
	    errorb_le = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		w_B0 = przj_MPFb_nl_B0->GetBinEntries(i);
		w_Bp = przj_MPFb_nl_Bp->GetBinEntries(i);
		w_B0s = przj_MPFb_nl_B0s->GetBinEntries(i);
		w_Bb = przj_MPFb_nl_Bb->GetBinEntries(i);
		w_nonB = przj_MPFb_nl_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFb_nl_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFb_nl_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFb_nl_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFb_nl_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFb_nl_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFb_nl_B0->GetBinError(i);
		val_std_Bp = przj_MPFb_nl_Bp->GetBinError(i);
		val_std_B0s = przj_MPFb_nl_B0s->GetBinError(i);
		val_std_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		val_std_nonB = przj_MPFb_nl_nonB->GetBinError(i);
 
	    errorb_nl = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//g-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFg_B0->GetBinEntries(i);
		w_Bp = przj_MPFg_Bp->GetBinEntries(i);
		w_B0s = przj_MPFg_B0s->GetBinEntries(i);
		w_Bb = przj_MPFg_Bb->GetBinEntries(i);
		w_nonB = przj_MPFg_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFg_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFg_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFg_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFg_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFg_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFg_B0->GetBinError(i);
		val_std_Bp = przj_MPFg_Bp->GetBinError(i);
		val_std_B0s = przj_MPFg_B0s->GetBinError(i);
		val_std_Bb = przj_MPFg_Bb->GetBinError(i);
		val_std_nonB = przj_MPFg_nonB->GetBinError(i);
 
	    errorg = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//ud-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFud_B0->GetBinEntries(i);
		w_Bp = przj_MPFud_Bp->GetBinEntries(i);
		w_B0s = przj_MPFud_B0s->GetBinEntries(i);
		w_Bb = przj_MPFud_Bb->GetBinEntries(i);
		w_nonB = przj_MPFud_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFud_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFud_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFud_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFud_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFud_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFud_B0->GetBinError(i);
		val_std_Bp = przj_MPFud_Bp->GetBinError(i);
		val_std_B0s = przj_MPFud_B0s->GetBinError(i);
		val_std_Bb = przj_MPFud_Bb->GetBinError(i);
		val_std_nonB = przj_MPFud_nonB->GetBinError(i);
 
	    errorud = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//s-jet

//		//Different B-hadron categories
		w_B0 = przj_MPFs_B0->GetBinEntries(i);
		w_Bp = przj_MPFs_Bp->GetBinEntries(i);
		w_B0s = przj_MPFs_B0s->GetBinEntries(i);
		w_Bb = przj_MPFs_Bb->GetBinEntries(i);
		w_nonB = przj_MPFs_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFs_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFs_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFs_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFs_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFs_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFs_B0->GetBinError(i);
		val_std_Bp = przj_MPFs_Bp->GetBinError(i);
		val_std_B0s = przj_MPFs_B0s->GetBinError(i);
		val_std_Bb = przj_MPFs_Bb->GetBinError(i);
		val_std_nonB = przj_MPFs_nonB->GetBinError(i);
 
	    errors = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 
//		//c-jet

//		//Different B-hadron categories

		w_B0 = przj_MPFc_B0->GetBinEntries(i);
		w_Bp = przj_MPFc_Bp->GetBinEntries(i);
		w_B0s = przj_MPFc_B0s->GetBinEntries(i);
		w_Bb = przj_MPFc_Bb->GetBinEntries(i);
		w_nonB = przj_MPFc_nonB->GetBinEntries(i);

		w_B0_var = przj_MPFc_B0_var->GetBinEntries(i);
		w_Bp_var = przj_MPFc_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_MPFc_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_MPFc_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_MPFc_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_MPFc_B0->GetBinError(i);
		val_std_Bp = przj_MPFc_Bp->GetBinError(i);
		val_std_B0s = przj_MPFc_B0s->GetBinError(i);
		val_std_Bb = przj_MPFc_Bb->GetBinError(i);
		val_std_nonB = przj_MPFc_nonB->GetBinError(i);
 
	    errorc = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		//Root won't plot 0 values, thus the 0 are replaced with small value

		if (diff->GetBinContent(i) == 0) {
    		diff->SetBinContent(i,1e-6);
		}
		if (diffb_le->GetBinContent(i) == 0) {
    		diffb_le->SetBinContent(i,1e-6);
		}
		if (diffb_nl->GetBinContent(i) == 0) {
    		diffb_nl->SetBinContent(i,1e-6);
		}
		if (diffg->GetBinContent(i) == 0) {
    		diffg->SetBinContent(i,1e-6);
		}
		if (diffud->GetBinContent(i) == 0) {
    		diffud->SetBinContent(i,1e-6);
		}
		if (diffs->GetBinContent(i) == 0) {
    		diffs->SetBinContent(i,1e-6);
		}
		if (diffc->GetBinContent(i) == 0) {
    		diffc->SetBinContent(i,1e-6);
		}

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}

		}

		cout << "error: " << error << endl;
		cout << "errorb_le: " << errorb_le << endl;
		cout << "errorb_nl: " << errorb_nl << endl;
		cout << "errorg: " << errorg << endl;
		cout << "errorud: " << errorud << endl;
		cout << "error:s " << errors << endl;
		cout << "error:c " << errorc << endl;
		cout << "" << endl;

	  }
	  diff->Scale(100.0);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_MPF = new TCanvas("MPF","",500,400);
	  canv_MPF->SetLeftMargin(0.13);
	  canv_MPF->SetBottomMargin(0.13);
	  canv_MPF->SetLogx();

	  //Legend
//	  TLegend* lz_MPF = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_MPF = new TLegend(0.37,0.17,0.64,0.39);
	  if (zoom_y) {
		lz_MPF = new TLegend(0.37,0.65,0.64,0.89);
	  }
		
	  lz_MPF->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  if (smaller_markers) {
	  	diff  ->SetMarkerSize(0.3);              
	  	//diffb ->SetMarkerSize(kRed+1);
	  	diffb_nl ->SetMarkerSize(0.3);
	  	diffb_le ->SetMarkerSize(0.3);
	  	diffc ->SetMarkerSize(0.3);             
	  	diffs->SetMarkerSize(0.3);
	  	diffud ->SetMarkerSize(0.3);            
	  	diffg ->SetMarkerSize(0.3);
	  }

	  //Legend
	  //TLegend* lz_MPF = new TLegend(0.55,0.17,0.75,0.42);
	  lz_MPF->SetBorderSize(0);
	  lz_MPF->AddEntry(diff,   "All",   "p");
	  //lz_MPF->AddEntry(diffb,  "b",     "p");
	  lz_MPF->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_MPF->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_MPF->AddEntry(diffc,  "c",     "p");
	  lz_MPF->AddEntry(diffs,  "s",     "p");
	  lz_MPF->AddEntry(diffud, "ud",    "p");
	  lz_MPF->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_MPF->Draw();

	  if (y_fixed) {
	  	diff->SetMaximum(0.6);
	  	diff->SetMinimum(-0.4);
	  }

	    diff->SetMaximum(0.9);
	    diff->SetMinimum(-0.9);

	  if (zoom_y) {
		diff->SetMaximum(0.4);
	  	diff->SetMinimum(-0.15);
	  }

	  string amount;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

      string plotName;
		
	  if (zoom_y) {
        plotName = "diff_plots/zoom_" + amount; 
	  } else {
        plotName = "diff_plots/" + amount;
	  }

      plotName += "_diff_MPF.pdf";	//Filetype suffix

	  //Save plot
	  canv_MPF->Print(plotName.c_str()); delete canv_MPF;
  } 

  if (pT_plot_ver2) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_pTp=0; TProfile *przj_pTpc=0;
	  TProfile *przj_pTps=0; TProfile *przj_pTpud=0; TProfile *przj_pTpg=0;
	  //TProfile *przj_pTpb=0;
	  TProfile *przj_pTpb_nl=0;
	  TProfile *przj_pTpb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_pTp_B0=0; TProfile *przj_pTpc_B0=0;
	  TProfile *przj_pTps_B0=0; TProfile *przj_pTpud_B0=0; TProfile *przj_pTpg_B0=0;
	  //TProfile *przj_pTpb_B0=0;
	  TProfile *przj_pTpb_nl_B0=0;
	  TProfile *przj_pTpb_le_B0=0;

	  TProfile *przj_pTp_Bp=0; TProfile *przj_pTpc_Bp=0;
	  TProfile *przj_pTps_Bp=0; TProfile *przj_pTpud_Bp=0; TProfile *przj_pTpg_Bp=0;
	  //TProfile *przj_pTpb_Bp=0;
	  TProfile *przj_pTpb_nl_Bp=0;
	  TProfile *przj_pTpb_le_Bp=0;

	  TProfile *przj_pTp_B0s=0; TProfile *przj_pTpc_B0s=0;
	  TProfile *przj_pTps_B0s=0; TProfile *przj_pTpud_B0s=0; TProfile *przj_pTpg_B0s=0;
	  //TProfile *przj_pTpb_B0s=0;
	  TProfile *przj_pTpb_nl_B0s=0;
	  TProfile *przj_pTpb_le_B0s=0;

	  TProfile *przj_pTp_Bb=0; TProfile *przj_pTpc_Bb=0;
	  TProfile *przj_pTps_Bb=0; TProfile *przj_pTpud_Bb=0; TProfile *przj_pTpg_Bb=0;
	  //TProfile *przj_pTpb_Bb=0;
	  TProfile *przj_pTpb_nl_Bb=0;
	  TProfile *przj_pTpb_le_Bb=0;

	  TProfile *przj_pTp_nonB=0; TProfile *przj_pTpc_nonB=0;
	  TProfile *przj_pTps_nonB=0; TProfile *przj_pTpud_nonB=0; TProfile *przj_pTpg_nonB=0;
	  //TProfile *przj_pTpb_nonB=0;
	  TProfile *przj_pTpb_nl_nonB=0;
	  TProfile *przj_pTpb_le_nonB=0;

	  //The weighted sample

	  TProfile *przj_pTp_var=0;   TProfile *przj_pTpc_var=0;
	  TProfile *przj_pTps_var=0; TProfile *przj_pTpud_var=0; TProfile *przj_pTpg_var=0;
	  //TProfile *przj_pTpb_var=0;
	  TProfile *przj_pTpb_nl_var=0;
	  TProfile *przj_pTpb_le_var=0;

	  //Different B-hadron categories

	  TProfile *przj_pTp_B0_var=0; TProfile *przj_pTpc_B0_var=0;
	  TProfile *przj_pTps_B0_var=0; TProfile *przj_pTpud_B0_var=0; TProfile *przj_pTpg_B0_var=0;
	  //TProfile *przj_pTpb_B0_var=0;
	  TProfile *przj_pTpb_nl_B0_var=0;
	  TProfile *przj_pTpb_le_B0_var=0;

	  TProfile *przj_pTp_Bp_var=0; TProfile *przj_pTpc_Bp_var=0;
	  TProfile *przj_pTps_Bp_var=0; TProfile *przj_pTpud_Bp_var=0; TProfile *przj_pTpg_Bp_var=0;
	  //TProfile *przj_pTpb_Bp_var=0;
	  TProfile *przj_pTpb_nl_Bp_var=0;
	  TProfile *przj_pTpb_le_Bp_var=0;

	  TProfile *przj_pTp_B0s_var=0; TProfile *przj_pTpc_B0s_var=0;
	  TProfile *przj_pTps_B0s_var=0; TProfile *przj_pTpud_B0s_var=0; TProfile *przj_pTpg_B0s_var=0;
	  //TProfile *przj_pTpb_B0s_var=0;
	  TProfile *przj_pTpb_nl_B0s_var=0;
	  TProfile *przj_pTpb_le_B0s_var=0;

	  TProfile *przj_pTp_Bb_var=0; TProfile *przj_pTpc_Bb_var=0;
	  TProfile *przj_pTps_Bb_var=0; TProfile *przj_pTpud_Bb_var=0; TProfile *przj_pTpg_Bb_var=0;
	  //TProfile *przj_pTpb_Bb_var=0;
	  TProfile *przj_pTpb_nl_Bb_var=0;
	  TProfile *przj_pTpb_le_Bb_var=0;

	  TProfile *przj_pTp_nonB_var=0; TProfile *przj_pTpc_nonB_var=0;
	  TProfile *przj_pTps_nonB_var=0; TProfile *przj_pTpud_nonB_var=0; TProfile *przj_pTpg_nonB_var=0;
	  //TProfile *przj_pTpb_nonB_var=0;
	  TProfile *przj_pTpb_nl_nonB_var=0;
	  TProfile *przj_pTpb_le_nonB_var=0;

	  // Read the normal sample

	  fzj->GetObject("prpTbal",   przj_pTp);
	  //fzj->GetObject("prpTbalb",  przj_pTpb);
	  fzj->GetObject("prpTbalb_nl",  przj_pTpb_nl);
	  fzj->GetObject("prpTbalb_le",  przj_pTpb_le);
	  fzj->GetObject("prpTbalc",  przj_pTpc);
	  fzj->GetObject("prpTbals",  przj_pTps);
	  fzj->GetObject("prpTbalud", przj_pTpud);
	  fzj->GetObject("prpTbalg",  przj_pTpg);

	  //Different B-hadron categories

	  fzj->GetObject("prpTbal_B0",   przj_pTp_B0);
	  //fzj->GetObject("prpTbalb_B0",  przj_pTpb_B0);
	  fzj->GetObject("prpTbalb_nl_B0",  przj_pTpb_nl_B0);
	  fzj->GetObject("prpTbalb_le_B0",  przj_pTpb_le_B0);
	  fzj->GetObject("prpTbalc_B0",  przj_pTpc_B0);
	  fzj->GetObject("prpTbals_B0",  przj_pTps_B0);
	  fzj->GetObject("prpTbalud_B0", przj_pTpud_B0);
	  fzj->GetObject("prpTbalg_B0",  przj_pTpg_B0);

	  fzj->GetObject("prpTbal_Bp",   przj_pTp_Bp);
	  //fzj->GetObject("prpTbalb_Bp",  przj_pTpb_Bp);
	  fzj->GetObject("prpTbalb_nl_Bp",  przj_pTpb_nl_Bp);
	  fzj->GetObject("prpTbalb_le_Bp",  przj_pTpb_le_Bp);
	  fzj->GetObject("prpTbalc_Bp",  przj_pTpc_Bp);
	  fzj->GetObject("prpTbals_Bp",  przj_pTps_Bp);
	  fzj->GetObject("prpTbalud_Bp", przj_pTpud_Bp);
	  fzj->GetObject("prpTbalg_Bp",  przj_pTpg_Bp);

	  fzj->GetObject("prpTbal_B0s",   przj_pTp_B0s);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_B0s);
	  fzj->GetObject("prpTbalb_nl_B0s",  przj_pTpb_nl_B0s);
	  fzj->GetObject("prpTbalb_le_B0s",  przj_pTpb_le_B0s);
	  fzj->GetObject("prpTbalc_B0s",  przj_pTpc_B0s);
	  fzj->GetObject("prpTbals_B0s",  przj_pTps_B0s);
	  fzj->GetObject("prpTbalud_B0s", przj_pTpud_B0s);
	  fzj->GetObject("prpTbalg_B0s",  przj_pTpg_B0s);

	  fzj->GetObject("prpTbal_Bb",   przj_pTp_Bb);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_Bb);
	  fzj->GetObject("prpTbalb_nl_Bb",  przj_pTpb_nl_Bb);
	  fzj->GetObject("prpTbalb_le_Bb",  przj_pTpb_le_Bb);
	  fzj->GetObject("prpTbalc_Bb",  przj_pTpc_Bb);
	  fzj->GetObject("prpTbals_Bb",  przj_pTps_Bb);
	  fzj->GetObject("prpTbalud_Bb", przj_pTpud_Bb);
	  fzj->GetObject("prpTbalg_Bb",  przj_pTpg_Bb);

	  fzj->GetObject("prpTbal_nonB",   przj_pTp_nonB);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_nonB);
	  fzj->GetObject("prpTbalb_nl_nonB",  przj_pTpb_nl_nonB);
	  fzj->GetObject("prpTbalb_le_nonB",  przj_pTpb_le_nonB);
	  fzj->GetObject("prpTbalc_nonB",  przj_pTpc_nonB);
	  fzj->GetObject("prpTbals_nonB",  przj_pTps_nonB);
	  fzj->GetObject("prpTbalud_nonB", przj_pTpud_nonB);
	  fzj->GetObject("prpTbalg_nonB",  przj_pTpg_nonB);

      //Read the weighted sample
	
	  fzj_var->GetObject("prpTbal",   przj_pTp_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_var);
	  fzj_var->GetObject("prpTbalb_nl",  przj_pTpb_nl_var);
	  fzj_var->GetObject("prpTbalb_le",  przj_pTpb_le_var);
	  fzj_var->GetObject("prpTbalc",  przj_pTpc_var);
	  fzj_var->GetObject("prpTbals",  przj_pTps_var);
	  fzj_var->GetObject("prpTbalud", przj_pTpud_var);
	  fzj_var->GetObject("prpTbalg",  przj_pTpg_var);

	  //Different B-hadron categories
	  fzj_var->GetObject("prpTbal_B0",   przj_pTp_B0_var);
	  //fzj_var->GetObject("prpTbalb_B0",  przj_pTpb_B0_var);
	  fzj_var->GetObject("prpTbalb_nl_B0",  przj_pTpb_nl_B0_var);
	  fzj_var->GetObject("prpTbalb_le_B0",  przj_pTpb_le_B0_var);
	  fzj_var->GetObject("prpTbalc_B0",  przj_pTpc_B0_var);
	  fzj_var->GetObject("prpTbals_B0",  przj_pTps_B0_var);
	  fzj_var->GetObject("prpTbalud_B0", przj_pTpud_B0_var);
	  fzj_var->GetObject("prpTbalg_B0",  przj_pTpg_B0_var);

	  fzj_var->GetObject("prpTbal_Bp",   przj_pTp_Bp_var);
	  //fzj_var->GetObject("prpTbalb_Bp",  przj_pTpb_Bp_var);
	  fzj_var->GetObject("prpTbalb_nl_Bp",  przj_pTpb_nl_Bp_var);
	  fzj_var->GetObject("prpTbalb_le_Bp",  przj_pTpb_le_Bp_var);
	  fzj_var->GetObject("prpTbalc_Bp",  przj_pTpc_Bp_var);
	  fzj_var->GetObject("prpTbals_Bp",  przj_pTps_Bp_var);
	  fzj_var->GetObject("prpTbalud_Bp", przj_pTpud_Bp_var);
	  fzj_var->GetObject("prpTbalg_Bp",  przj_pTpg_Bp_var);

	  fzj_var->GetObject("prpTbal_B0s",   przj_pTp_B0s_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_B0s_var);
	  fzj_var->GetObject("prpTbalb_nl_B0s",  przj_pTpb_nl_B0s_var);
	  fzj_var->GetObject("prpTbalb_le_B0s",  przj_pTpb_le_B0s_var);
	  fzj_var->GetObject("prpTbalc_B0s",  przj_pTpc_B0s_var);
	  fzj_var->GetObject("prpTbals_B0s",  przj_pTps_B0s_var);
	  fzj_var->GetObject("prpTbalud_B0s", przj_pTpud_B0s_var);
	  fzj_var->GetObject("prpTbalg_B0s",  przj_pTpg_B0s_var);

	  fzj_var->GetObject("prpTbal_Bb",   przj_pTp_Bb_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_Bb_var);
	  fzj_var->GetObject("prpTbalb_nl_Bb",  przj_pTpb_nl_Bb_var);
	  fzj_var->GetObject("prpTbalb_le_Bb",  przj_pTpb_le_Bb_var);
	  fzj_var->GetObject("prpTbalc_Bb",  przj_pTpc_Bb_var);
	  fzj_var->GetObject("prpTbals_Bb",  przj_pTps_Bb_var);
	  fzj_var->GetObject("prpTbalud_Bb", przj_pTpud_Bb_var);
	  fzj_var->GetObject("prpTbalg_Bb",  przj_pTpg_Bb_var);

	  fzj_var->GetObject("prpTbal_nonB",   przj_pTp_nonB_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_nonB_var);
	  fzj_var->GetObject("prpTbalb_nl_nonB",  przj_pTpb_nl_nonB_var);
	  fzj_var->GetObject("prpTbalb_le_nonB",  przj_pTpb_le_nonB_var);
	  fzj_var->GetObject("prpTbalc_nonB",  przj_pTpc_nonB_var);
	  fzj_var->GetObject("prpTbals_nonB",  przj_pTps_nonB_var);
	  fzj_var->GetObject("prpTbalud_nonB", przj_pTpud_nonB_var);
	  fzj_var->GetObject("prpTbalg_nonB",  przj_pTpg_nonB_var);

	  TH1D* hzj_pTp   = przj_pTp  ->ProjectionX();
	  //TH1D* hzj_pTpb  = przj_pTpb ->ProjectionX();
	  TH1D* hzj_pTpb_nl  = przj_pTpb_nl ->ProjectionX();
	  TH1D* hzj_pTpb_le  = przj_pTpb_le ->ProjectionX();
	  TH1D* hzj_pTpc  = przj_pTpc ->ProjectionX();
	  TH1D* hzj_pTps  = przj_pTps ->ProjectionX();
	  TH1D* hzj_pTpud = przj_pTpud->ProjectionX();
	  TH1D* hzj_pTpg  = przj_pTpg ->ProjectionX();

	  TH1D* hzj_pTp_var   = przj_pTp_var  ->ProjectionX();
	  //TH1D* hzj_pTpb_var  = przj_pTpb_var ->ProjectionX();
	  TH1D* hzj_pTpb_nl_var  = przj_pTpb_nl_var ->ProjectionX();
	  TH1D* hzj_pTpb_le_var  = przj_pTpb_le_var ->ProjectionX();
	  TH1D* hzj_pTpc_var  = przj_pTpc_var ->ProjectionX();
	  TH1D* hzj_pTps_var  = przj_pTps_var ->ProjectionX();
	  TH1D* hzj_pTpud_var = przj_pTpud_var->ProjectionX();
	  TH1D* hzj_pTpg_var  = przj_pTpg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_pTp->Clone();
	  //TH1D* diffb = (TH1D*) hzj_pTpb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_pTpb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_pTpb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_pTpc->Clone();
	  TH1D* diffs = (TH1D*) hzj_pTps->Clone();
	  TH1D* diffud = (TH1D*) hzj_pTpud->Clone();
	  TH1D* diffg = (TH1D*) hzj_pTpg->Clone();

	  diff->Add(hzj_pTp_var,-1);
	  //diffb->Add(hzj_pTpb_var,-1);
	  diffb_nl->Add(hzj_pTpb_nl_var,-1);
	  diffb_le->Add(hzj_pTpb_le_var,-1);
	  diffc->Add(hzj_pTpc_var,-1);
	  diffs->Add(hzj_pTps_var,-1);
	  diffud->Add(hzj_pTpud_var,-1);
	  diffg->Add(hzj_pTpg_var,-1);

//	  diff->Divide(hzj_pTp);
//	  //diffb->Add(hzj_pTpb_var,-1);
//	  diffb_nl->Divide(hzj_pTpb_nl);
//	  diffb_le->Divide(hzj_pTpb_le);
//	  diffc->Divide(hzj_pTpc);
//	  diffs->Divide(hzj_pTps);
//	  diffud->Divide(hzj_pTpud);
//	  diffg->Divide(hzj_pTpg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	  double val_std_B0; double val_std_Bp; double val_std_B0s; double val_std_Bb; double val_std_nonB;
	  double w_B0; double w_Bp; double w_B0s; double w_Bb; double w_nonB;
	  double w_B0_var; double w_Bp_var; double w_B0s_var; double w_Bb_var; double w_nonB_var;
	  double norm_tot_w; double var_tot_w;


	  for (int i = 1; i < 15; i++){

		//all jets

	    //Different B-hadron categories
		w_B0 = przj_pTp_B0->GetBinEntries(i);
		w_Bp = przj_pTp_Bp->GetBinEntries(i);
		w_B0s = przj_pTp_B0s->GetBinEntries(i);
		w_Bb = przj_pTp_Bb->GetBinEntries(i);
		w_nonB = przj_pTp_nonB->GetBinEntries(i);

		w_B0_var = przj_pTp_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTp_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTp_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTp_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTp_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTp_B0->GetBinError(i);
		val_std_Bp = przj_pTp_Bp->GetBinError(i);
		val_std_B0s = przj_pTp_B0s->GetBinError(i);
		val_std_Bb = przj_pTp_Bb->GetBinError(i);
		val_std_nonB = przj_pTp_nonB->GetBinError(i);
 
	    error = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

		//b-jet semileptonic

	    //Different B-hadron categories
		w_B0 = przj_pTpb_le_B0->GetBinEntries(i);
		w_Bp = przj_pTpb_le_Bp->GetBinEntries(i);
		w_B0s = przj_pTpb_le_B0s->GetBinEntries(i);
		w_Bb = przj_pTpb_le_Bb->GetBinEntries(i);
		w_nonB = przj_pTpb_le_nonB->GetBinEntries(i);

		w_B0_var = przj_pTpb_le_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTpb_le_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTpb_le_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTpb_le_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTpb_le_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTpb_le_B0->GetBinError(i);
		val_std_Bp = przj_pTpb_le_Bp->GetBinError(i);
		val_std_B0s = przj_pTpb_le_B0s->GetBinError(i);
		val_std_Bb = przj_pTpb_le_Bb->GetBinError(i);
		val_std_nonB = przj_pTpb_le_nonB->GetBinError(i);
 
	    errorb_le = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//b-jet non-semileptonic

//		//Different B-hadron categories
		w_B0 = przj_pTpb_nl_B0->GetBinEntries(i);
		w_Bp = przj_pTpb_nl_Bp->GetBinEntries(i);
		w_B0s = przj_pTpb_nl_B0s->GetBinEntries(i);
		w_Bb = przj_pTpb_nl_Bb->GetBinEntries(i);
		w_nonB = przj_pTpb_nl_nonB->GetBinEntries(i);

		w_B0_var = przj_pTpb_nl_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTpb_nl_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTpb_nl_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTpb_nl_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTpb_nl_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTpb_nl_B0->GetBinError(i);
		val_std_Bp = przj_pTpb_nl_Bp->GetBinError(i);
		val_std_B0s = przj_pTpb_nl_B0s->GetBinError(i);
		val_std_Bb = przj_pTpb_nl_Bb->GetBinError(i);
		val_std_nonB = przj_pTpb_nl_nonB->GetBinError(i);
 
	    errorb_nl = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//g-jet

//		//Different B-hadron categories
		w_B0 = przj_pTpg_B0->GetBinEntries(i);
		w_Bp = przj_pTpg_Bp->GetBinEntries(i);
		w_B0s = przj_pTpg_B0s->GetBinEntries(i);
		w_Bb = przj_pTpg_Bb->GetBinEntries(i);
		w_nonB = przj_pTpg_nonB->GetBinEntries(i);

		w_B0_var = przj_pTpg_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTpg_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTpg_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTpg_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTpg_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTpg_B0->GetBinError(i);
		val_std_Bp = przj_pTpg_Bp->GetBinError(i);
		val_std_B0s = przj_pTpg_B0s->GetBinError(i);
		val_std_Bb = przj_pTpg_Bb->GetBinError(i);
		val_std_nonB = przj_pTpg_nonB->GetBinError(i);
 
	    errorg = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//ud-jet

//		//Different B-hadron categories
		w_B0 = przj_pTpud_B0->GetBinEntries(i);
		w_Bp = przj_pTpud_Bp->GetBinEntries(i);
		w_B0s = przj_pTpud_B0s->GetBinEntries(i);
		w_Bb = przj_pTpud_Bb->GetBinEntries(i);
		w_nonB = przj_pTpud_nonB->GetBinEntries(i);

		w_B0_var = przj_pTpud_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTpud_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTpud_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTpud_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTpud_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTpud_B0->GetBinError(i);
		val_std_Bp = przj_pTpud_Bp->GetBinError(i);
		val_std_B0s = przj_pTpud_B0s->GetBinError(i);
		val_std_Bb = przj_pTpud_Bb->GetBinError(i);
		val_std_nonB = przj_pTpud_nonB->GetBinError(i);
 
	    errorud = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 

//		//s-jet

//		//Different B-hadron categories
		w_B0 = przj_pTps_B0->GetBinEntries(i);
		w_Bp = przj_pTps_Bp->GetBinEntries(i);
		w_B0s = przj_pTps_B0s->GetBinEntries(i);
		w_Bb = przj_pTps_Bb->GetBinEntries(i);
		w_nonB = przj_pTps_nonB->GetBinEntries(i);

		w_B0_var = przj_pTps_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTps_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTps_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTps_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTps_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTps_B0->GetBinError(i);
		val_std_Bp = przj_pTps_Bp->GetBinError(i);
		val_std_B0s = przj_pTps_B0s->GetBinError(i);
		val_std_Bb = przj_pTps_Bb->GetBinError(i);
		val_std_nonB = przj_pTps_nonB->GetBinError(i);
 
	    errors = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2)); 
//		//c-jet

//		//Different B-hadron categories

		w_B0 = przj_pTpc_B0->GetBinEntries(i);
		w_Bp = przj_pTpc_Bp->GetBinEntries(i);
		w_B0s = przj_pTpc_B0s->GetBinEntries(i);
		w_Bb = przj_pTpc_Bb->GetBinEntries(i);
		w_nonB = przj_pTpc_nonB->GetBinEntries(i);

		w_B0_var = przj_pTpc_B0_var->GetBinEntries(i);
		w_Bp_var = przj_pTpc_Bp_var->GetBinEntries(i);
		w_B0s_var = przj_pTpc_B0s_var->GetBinEntries(i);
		w_Bb_var = przj_pTpc_Bb_var->GetBinEntries(i);
		w_nonB_var = przj_pTpc_nonB_var->GetBinEntries(i);

		//The sum of weights for normal and weighted case
		norm_tot_w = w_B0 + w_Bp + w_B0s + w_Bb + w_nonB;
		var_tot_w = w_B0_var + w_Bp_var + w_B0s_var + w_Bb_var + w_nonB_var;

		//The error of the mean for different B-hadrons
		val_std_B0 = przj_pTpc_B0->GetBinError(i);
		val_std_Bp = przj_pTpc_Bp->GetBinError(i);
		val_std_B0s = przj_pTpc_B0s->GetBinError(i);
		val_std_Bb = przj_pTpc_Bb->GetBinError(i);
		val_std_nonB = przj_pTpc_nonB->GetBinError(i);
 
	    errorc = sqrt(pow((w_B0_var/var_tot_w - w_B0/norm_tot_w)*val_std_B0,2) +
			    pow((w_Bp_var/var_tot_w - w_Bp/norm_tot_w)*val_std_Bp,2) + 
				pow((w_B0s_var/var_tot_w - w_B0s/norm_tot_w)*val_std_B0s,2) + 
				pow((w_Bb_var/var_tot_w - w_Bb/norm_tot_w)*val_std_Bb,2) + 
				pow((w_nonB_var/var_tot_w - w_nonB/norm_tot_w)*val_std_nonB,2));

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		//Root won't plot 0 values, thus the 0 are replaced with small value

		if (diff->GetBinContent(i) == 0) {
    		diff->SetBinContent(i,1e-6);
		}
		if (diffb_le->GetBinContent(i) == 0) {
    		diffb_le->SetBinContent(i,1e-6);
		}
		if (diffb_nl->GetBinContent(i) == 0) {
    		diffb_nl->SetBinContent(i,1e-6);
		}
		if (diffg->GetBinContent(i) == 0) {
    		diffg->SetBinContent(i,1e-6);
		}
		if (diffud->GetBinContent(i) == 0) {
    		diffud->SetBinContent(i,1e-6);
		}
		if (diffs->GetBinContent(i) == 0) {
    		diffs->SetBinContent(i,1e-6);
		}
		if (diffc->GetBinContent(i) == 0) {
    		diffc->SetBinContent(i,1e-6);
		}

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}

		}

		cout << "error: " << error << endl;
		cout << "errorb_le: " << errorb_le << endl;
		cout << "errorb_nl: " << errorb_nl << endl;
		cout << "errorg: " << errorg << endl;
		cout << "errorud: " << errorud << endl;
		cout << "error:s " << errors << endl;
		cout << "error:c " << errorc << endl;
		cout << "" << endl;

	  }
	  diff->Scale(100.0);
	  //diffb->Add(hzj_pTpb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_pTp = new TCanvas("pTp","",500,400);
	  canv_pTp->SetLeftMargin(0.13);
	  canv_pTp->SetBottomMargin(0.13);
	  canv_pTp->SetLogx();

	  //Legend
//	  TLegend* lz_pTp = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_pTp = new TLegend(0.37,0.17,0.64,0.39);
	  lz_pTp->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  if (smaller_markers) {
	  	diff  ->SetMarkerSize(0.3);              
	  	//diffb ->SetMarkerSize(kRed+1);
	  	diffb_nl ->SetMarkerSize(0.3);
	  	diffb_le ->SetMarkerSize(0.3);
	  	diffc ->SetMarkerSize(0.3);             
	  	diffs->SetMarkerSize(0.3);
	  	diffud ->SetMarkerSize(0.3);            
	  	diffg ->SetMarkerSize(0.3);
	  }

	  //Legend
	  //TLegend* lz_pTp = new TLegend(0.55,0.17,0.75,0.42);
	  lz_pTp->SetBorderSize(0);
	  lz_pTp->AddEntry(diff,   "All",   "p");
	  //lz_pTp->AddEntry(diffb,  "b",     "p");
	  lz_pTp->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_pTp->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_pTp->AddEntry(diffc,  "c",     "p");
	  lz_pTp->AddEntry(diffs,  "s",     "p");
	  lz_pTp->AddEntry(diffud, "ud",    "p");
	  lz_pTp->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_pTp->Draw();

	  if (y_fixed) {
	    diff->SetMaximum(0.6);
	    diff->SetMinimum(-0.4);
	  }

	    diff->SetMaximum(0.9);
	    diff->SetMinimum(-0.9);

	  if (zoom_y) {
	    diff->SetMaximum(0.25);
	    diff->SetMinimum(-0.4);
	  }

	  string amount;

	  if (n_events == "3000") {
		amount = "3k";
	  }

	  if (n_events == "30000") {
		amount = "30k";
	  }

	  if (n_events == "100000") {
		amount = "100k";
	  }

	  if (n_events == "1000000") {
		amount = "1M";
	  }

	  if (n_events == "5000000") {
		amount = "5M";
	  }

	  string plotName;
	  if (zoom_y) {
        plotName = "diff_plots/zoom_" + amount; 
	  } else {
        plotName = "diff_plots/" + amount;
	  }

      plotName += "_diff_pTbal.pdf";	//Filetype suffix

	  //Save plot
	  canv_pTp->Print(plotName.c_str()); delete canv_pTp;
  } 

  if (mpf_plot_ver1) {

	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0=0; TProfile *przj_MPFc_B0=0;
	  TProfile *przj_MPFs_B0=0; TProfile *przj_MPFud_B0=0; TProfile *przj_MPFg_B0=0;
	  //TProfile *przj_MPFb_B0=0;
	  TProfile *przj_MPFb_nl_B0=0;
	  TProfile *przj_MPFb_le_B0=0;

	  TProfile *przj_MPF_Bp=0; TProfile *przj_MPFc_Bp=0;
	  TProfile *przj_MPFs_Bp=0; TProfile *przj_MPFud_Bp=0; TProfile *przj_MPFg_Bp=0;
	  //TProfile *przj_MPFb_Bp=0;
	  TProfile *przj_MPFb_nl_Bp=0;
	  TProfile *przj_MPFb_le_Bp=0;

	  TProfile *przj_MPF_B0s=0; TProfile *przj_MPFc_B0s=0;
	  TProfile *przj_MPFs_B0s=0; TProfile *przj_MPFud_B0s=0; TProfile *przj_MPFg_B0s=0;
	  //TProfile *przj_MPFb_B0s=0;
	  TProfile *przj_MPFb_nl_B0s=0;
	  TProfile *przj_MPFb_le_B0s=0;

	  TProfile *przj_MPF_Bb=0; TProfile *przj_MPFc_Bb=0;
	  TProfile *przj_MPFs_Bb=0; TProfile *przj_MPFud_Bb=0; TProfile *przj_MPFg_Bb=0;
	  //TProfile *przj_MPFb_Bb=0;
	  TProfile *przj_MPFb_nl_Bb=0;
	  TProfile *przj_MPFb_le_Bb=0;

	  TProfile *przj_MPF_nonB=0; TProfile *przj_MPFc_nonB=0;
	  TProfile *przj_MPFs_nonB=0; TProfile *przj_MPFud_nonB=0; TProfile *przj_MPFg_nonB=0;
	  //TProfile *przj_MPFb_nonB=0;
	  TProfile *przj_MPFb_nl_nonB=0;
	  TProfile *przj_MPFb_le_nonB=0;

	  //The weighted sample

	  TProfile *przj_MPF_var=0;   TProfile *przj_MPFc_var=0;
	  TProfile *przj_MPFs_var=0; TProfile *przj_MPFud_var=0; TProfile *przj_MPFg_var=0;
	  //TProfile *przj_MPFb_var=0;
	  TProfile *przj_MPFb_nl_var=0;
	  TProfile *przj_MPFb_le_var=0;

	  //Different B-hadron categories

	  TProfile *przj_MPF_B0_var=0; TProfile *przj_MPFc_B0_var=0;
	  TProfile *przj_MPFs_B0_var=0; TProfile *przj_MPFud_B0_var=0; TProfile *przj_MPFg_B0_var=0;
	  //TProfile *przj_MPFb_B0_var=0;
	  TProfile *przj_MPFb_nl_B0_var=0;
	  TProfile *przj_MPFb_le_B0_var=0;

	  TProfile *przj_MPF_Bp_var=0; TProfile *przj_MPFc_Bp_var=0;
	  TProfile *przj_MPFs_Bp_var=0; TProfile *przj_MPFud_Bp_var=0; TProfile *przj_MPFg_Bp_var=0;
	  //TProfile *przj_MPFb_Bp_var=0;
	  TProfile *przj_MPFb_nl_Bp_var=0;
	  TProfile *przj_MPFb_le_Bp_var=0;

	  TProfile *przj_MPF_B0s_var=0; TProfile *przj_MPFc_B0s_var=0;
	  TProfile *przj_MPFs_B0s_var=0; TProfile *przj_MPFud_B0s_var=0; TProfile *przj_MPFg_B0s_var=0;
	  //TProfile *przj_MPFb_B0s_var=0;
	  TProfile *przj_MPFb_nl_B0s_var=0;
	  TProfile *przj_MPFb_le_B0s_var=0;

	  TProfile *przj_MPF_Bb_var=0; TProfile *przj_MPFc_Bb_var=0;
	  TProfile *przj_MPFs_Bb_var=0; TProfile *przj_MPFud_Bb_var=0; TProfile *przj_MPFg_Bb_var=0;
	  //TProfile *przj_MPFb_Bb_var=0;
	  TProfile *przj_MPFb_nl_Bb_var=0;
	  TProfile *przj_MPFb_le_Bb_var=0;

	  TProfile *przj_MPF_nonB_var=0; TProfile *przj_MPFc_nonB_var=0;
	  TProfile *przj_MPFs_nonB_var=0; TProfile *przj_MPFud_nonB_var=0; TProfile *przj_MPFg_nonB_var=0;
	  //TProfile *przj_MPFb_nonB_var=0;
	  TProfile *przj_MPFb_nl_nonB_var=0;
	  TProfile *przj_MPFb_le_nonB_var=0;

	  // Read the normal sample

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  //Different B-hadron categories

	  fzj->GetObject("prMPF_B0",   przj_MPF_B0);
	  //fzj->GetObject("prMPFb_B0",  przj_MPFb_B0);
	  fzj->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0);
	  fzj->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0);
	  fzj->GetObject("prMPFc_B0",  przj_MPFc_B0);
	  fzj->GetObject("prMPFs_B0",  przj_MPFs_B0);
	  fzj->GetObject("prMPFud_B0", przj_MPFud_B0);
	  fzj->GetObject("prMPFg_B0",  przj_MPFg_B0);

	  fzj->GetObject("prMPF_Bp",   przj_MPF_Bp);
	  //fzj->GetObject("prMPFb_Bp",  przj_MPFb_Bp);
	  fzj->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp);
	  fzj->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp);
	  fzj->GetObject("prMPFc_Bp",  przj_MPFc_Bp);
	  fzj->GetObject("prMPFs_Bp",  przj_MPFs_Bp);
	  fzj->GetObject("prMPFud_Bp", przj_MPFud_Bp);
	  fzj->GetObject("prMPFg_Bp",  przj_MPFg_Bp);

	  fzj->GetObject("prMPF_B0s",   przj_MPF_B0s);
	  //fzj->GetObject("prMPFb",  przj_MPFb_B0s);
	  fzj->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s);
	  fzj->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s);
	  fzj->GetObject("prMPFc_B0s",  przj_MPFc_B0s);
	  fzj->GetObject("prMPFs_B0s",  przj_MPFs_B0s);
	  fzj->GetObject("prMPFud_B0s", przj_MPFud_B0s);
	  fzj->GetObject("prMPFg_B0s",  przj_MPFg_B0s);

	  fzj->GetObject("prMPF_Bb",   przj_MPF_Bb);
	  //fzj->GetObject("prMPFb",  przj_MPFb_Bb);
	  fzj->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb);
	  fzj->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb);
	  fzj->GetObject("prMPFc_Bb",  przj_MPFc_Bb);
	  fzj->GetObject("prMPFs_Bb",  przj_MPFs_Bb);
	  fzj->GetObject("prMPFud_Bb", przj_MPFud_Bb);
	  fzj->GetObject("prMPFg_Bb",  przj_MPFg_Bb);

	  fzj->GetObject("prMPF_nonB",   przj_MPF_nonB);
	  //fzj->GetObject("prMPFb",  przj_MPFb_nonB);
	  fzj->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB);
	  fzj->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB);
	  fzj->GetObject("prMPFc_nonB",  przj_MPFc_nonB);
	  fzj->GetObject("prMPFs_nonB",  przj_MPFs_nonB);
	  fzj->GetObject("prMPFud_nonB", przj_MPFud_nonB);
	  fzj->GetObject("prMPFg_nonB",  przj_MPFg_nonB);

      //Read the weighted sample
	
	  fzj_var->GetObject("prMPF",   przj_MPF_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_var);
	  fzj_var->GetObject("prMPFb_nl",  przj_MPFb_nl_var);
	  fzj_var->GetObject("prMPFb_le",  przj_MPFb_le_var);
	  fzj_var->GetObject("prMPFc",  przj_MPFc_var);
	  fzj_var->GetObject("prMPFs",  przj_MPFs_var);
	  fzj_var->GetObject("prMPFud", przj_MPFud_var);
	  fzj_var->GetObject("prMPFg",  przj_MPFg_var);

	  //Different B-hadron categories

	  fzj_var->GetObject("prMPF_B0",   przj_MPF_B0_var);
	  //fzj_var->GetObject("prMPFb_B0",  przj_MPFb_B0_var);
	  fzj_var->GetObject("prMPFb_nl_B0",  przj_MPFb_nl_B0_var);
	  fzj_var->GetObject("prMPFb_le_B0",  przj_MPFb_le_B0_var);
	  fzj_var->GetObject("prMPFc_B0",  przj_MPFc_B0_var);
	  fzj_var->GetObject("prMPFs_B0",  przj_MPFs_B0_var);
	  fzj_var->GetObject("prMPFud_B0", przj_MPFud_B0_var);
	  fzj_var->GetObject("prMPFg_B0",  przj_MPFg_B0_var);

	  fzj_var->GetObject("prMPF_Bp",   przj_MPF_Bp_var);
	  //fzj_var->GetObject("prMPFb_Bp",  przj_MPFb_Bp_var);
	  fzj_var->GetObject("prMPFb_nl_Bp",  przj_MPFb_nl_Bp_var);
	  fzj_var->GetObject("prMPFb_le_Bp",  przj_MPFb_le_Bp_var);
	  fzj_var->GetObject("prMPFc_Bp",  przj_MPFc_Bp_var);
	  fzj_var->GetObject("prMPFs_Bp",  przj_MPFs_Bp_var);
	  fzj_var->GetObject("prMPFud_Bp", przj_MPFud_Bp_var);
	  fzj_var->GetObject("prMPFg_Bp",  przj_MPFg_Bp_var);

	  fzj_var->GetObject("prMPF_B0s",   przj_MPF_B0s_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_B0s_var);
	  fzj_var->GetObject("prMPFb_nl_B0s",  przj_MPFb_nl_B0s_var);
	  fzj_var->GetObject("prMPFb_le_B0s",  przj_MPFb_le_B0s_var);
	  fzj_var->GetObject("prMPFc_B0s",  przj_MPFc_B0s_var);
	  fzj_var->GetObject("prMPFs_B0s",  przj_MPFs_B0s_var);
	  fzj_var->GetObject("prMPFud_B0s", przj_MPFud_B0s_var);
	  fzj_var->GetObject("prMPFg_B0s",  przj_MPFg_B0s_var);

	  fzj_var->GetObject("prMPF_Bb",   przj_MPF_Bb_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_Bb_var);
	  fzj_var->GetObject("prMPFb_nl_Bb",  przj_MPFb_nl_Bb_var);
	  fzj_var->GetObject("prMPFb_le_Bb",  przj_MPFb_le_Bb_var);
	  fzj_var->GetObject("prMPFc_Bb",  przj_MPFc_Bb_var);
	  fzj_var->GetObject("prMPFs_Bb",  przj_MPFs_Bb_var);
	  fzj_var->GetObject("prMPFud_Bb", przj_MPFud_Bb_var);
	  fzj_var->GetObject("prMPFg_Bb",  przj_MPFg_Bb_var);

	  fzj_var->GetObject("prMPF_nonB",   przj_MPF_nonB_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_nonB_var);
	  fzj_var->GetObject("prMPFb_nl_nonB",  przj_MPFb_nl_nonB_var);
	  fzj_var->GetObject("prMPFb_le_nonB",  przj_MPFb_le_nonB_var);
	  fzj_var->GetObject("prMPFc_nonB",  przj_MPFc_nonB_var);
	  fzj_var->GetObject("prMPFs_nonB",  przj_MPFs_nonB_var);
	  fzj_var->GetObject("prMPFud_nonB", przj_MPFud_nonB_var);
	  fzj_var->GetObject("prMPFg_nonB",  przj_MPFg_nonB_var);

	  TH1D* hzj_MPF   = przj_MPF  ->ProjectionX();
	  //TH1D* hzj_MPFb  = przj_MPFb ->ProjectionX();
	  TH1D* hzj_MPFb_nl  = przj_MPFb_nl ->ProjectionX();
	  TH1D* hzj_MPFb_le  = przj_MPFb_le ->ProjectionX();
	  TH1D* hzj_MPFc  = przj_MPFc ->ProjectionX();
	  TH1D* hzj_MPFs  = przj_MPFs ->ProjectionX();
	  TH1D* hzj_MPFud = przj_MPFud->ProjectionX();
	  TH1D* hzj_MPFg  = przj_MPFg ->ProjectionX();

	  TH1D* hzj_MPF_var   = przj_MPF_var  ->ProjectionX();
	  //TH1D* hzj_MPFb_var  = przj_MPFb_var ->ProjectionX();
	  TH1D* hzj_MPFb_nl_var  = przj_MPFb_nl_var ->ProjectionX();
	  TH1D* hzj_MPFb_le_var  = przj_MPFb_le_var ->ProjectionX();
	  TH1D* hzj_MPFc_var  = przj_MPFc_var ->ProjectionX();
	  TH1D* hzj_MPFs_var  = przj_MPFs_var ->ProjectionX();
	  TH1D* hzj_MPFud_var = przj_MPFud_var->ProjectionX();
	  TH1D* hzj_MPFg_var  = przj_MPFg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_MPF->Clone();
	  //TH1D* diffb = (TH1D*) hzj_MPFb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_MPFb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_MPFb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_MPFc->Clone();
	  TH1D* diffs = (TH1D*) hzj_MPFs->Clone();
	  TH1D* diffud = (TH1D*) hzj_MPFud->Clone();
	  TH1D* diffg = (TH1D*) hzj_MPFg->Clone();

	  diff->Add(hzj_MPF_var,-1);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Add(hzj_MPFb_nl_var,-1);
	  diffb_le->Add(hzj_MPFb_le_var,-1);
	  diffc->Add(hzj_MPFc_var,-1);
	  diffs->Add(hzj_MPFs_var,-1);
	  diffud->Add(hzj_MPFud_var,-1);
	  diffg->Add(hzj_MPFg_var,-1);

	  diff->Divide(hzj_MPF);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Divide(hzj_MPFb_nl);
	  diffb_le->Divide(hzj_MPFb_le);
	  diffc->Divide(hzj_MPFc);
	  diffs->Divide(hzj_MPFs);
	  diffud->Divide(hzj_MPFud);
	  diffg->Divide(hzj_MPFg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	  double val_B0; double var_val_B0; double val_std_B0; double var_val_std_B0;
	  double val_Bp; double var_val_Bp; double val_std_Bp; double var_val_std_Bp;
	  double val_B0s; double var_val_B0s; double val_std_B0s; double var_val_std_B0s;
	  double val_Bb; double var_val_Bb; double val_std_Bb; double var_val_std_Bb;
	  double val_nonB; double var_val_nonB; double val_std_nonB; double var_val_std_nonB;

  cout << "norm: " << przj_MPF_B0->GetBinEntries(6)*wB0 << endl;
  cout << "var: " << przj_MPF_B0_var->GetBinEntries(6) << endl;	


	  for (int i = 1; i < 15; i++){

		//The normal case

		val = przj_MPF->GetBinContent(i);
		var_val = przj_MPF_var->GetBinContent(i);
		val_std = przj_MPF->GetBinError(i);
		var_val_std = przj_MPF_var->GetBinError(i);  

	    //Different B-hadron categories

		val_B0 = przj_MPF_B0->GetBinContent(i);
		var_val_B0 = przj_MPF_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPF_B0->GetBinError(i);
		var_val_std_B0 = przj_MPF_B0_var->GetBinError(i);  

		val_Bp = przj_MPF_Bp->GetBinContent(i);
		var_val_Bp = przj_MPF_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPF_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPF_Bp_var->GetBinError(i);  

		val_B0s = przj_MPF_B0s->GetBinContent(i);
		var_val_B0s = przj_MPF_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPF_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPF_B0s_var->GetBinError(i);  

		val_Bb = przj_MPF_Bb->GetBinContent(i);
		var_val_Bb = przj_MPF_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPF_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPF_Bb_var->GetBinError(i);  

		val_nonB = przj_MPF_nonB->GetBinContent(i);
		var_val_nonB = przj_MPF_nonB_var->GetBinContent(i);
		val_std_nonB = przj_MPF_nonB->GetBinError(i);
		var_val_std_nonB = przj_MPF_nonB_var->GetBinError(i); 
 
	    error = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//b-jet semileptonic

		val = przj_MPFb_le->GetBinContent(i);
		var_val = przj_MPFb_le_var->GetBinContent(i);
		val_std = przj_MPFb_le->GetBinError(i);
		var_val_std = przj_MPFb_le_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFb_le_B0->GetBinContent(i);
		var_val_B0 = przj_MPFb_le_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFb_le_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFb_le_B0_var->GetBinError(i); 

		val_Bp = przj_MPFb_le_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFb_le_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFb_le_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFb_le_Bp_var->GetBinError(i);  

		val_B0s = przj_MPFb_le_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFb_le_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFb_le_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFb_le_B0s_var->GetBinError(i);  

		val_Bb = przj_MPFb_le_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFb_le_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFb_le_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFb_le_Bb_var->GetBinError(i);  

		val_nonB = przj_MPFb_le_nonB->GetBinContent(i);
		var_val_nonB = przj_MPFb_le_nonB_var->GetBinContent(i);
		val_std_nonB = przj_MPFb_le_nonB->GetBinError(i);
		var_val_std_nonB = przj_MPFb_le_nonB_var->GetBinError(i); 

	    errorb_le = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));  

		//b-jet non-semileptonic

		val = przj_MPFb_nl->GetBinContent(i);
		var_val = przj_MPFb_nl_var->GetBinContent(i);
		val_std = przj_MPFb_nl->GetBinError(i);
		var_val_std = przj_MPFb_nl_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFb_nl_B0->GetBinContent(i);
		var_val_B0 = przj_MPFb_nl_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFb_nl_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFb_nl_B0_var->GetBinError(i); 

		val_Bp = przj_MPFb_nl_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFb_nl_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFb_nl_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFb_nl_Bp_var->GetBinError(i); 

		val_B0s = przj_MPFb_nl_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFb_nl_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFb_nl_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFb_nl_B0s_var->GetBinError(i); 

		val_Bb = przj_MPFb_nl_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFb_nl_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFb_nl_Bb_var->GetBinError(i); 

		val_Bb = przj_MPFb_nl_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFb_nl_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFb_nl_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFb_nl_Bb_var->GetBinError(i); 

	    errorb_nl = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//g-jet

		val = przj_MPFg->GetBinContent(i);
		var_val = przj_MPFg_var->GetBinContent(i);
		val_std = przj_MPFg->GetBinError(i);
		var_val_std = przj_MPFg_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFg_B0->GetBinContent(i);
		var_val_B0 = przj_MPFg_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFg_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFg_B0_var->GetBinError(i);  

		val_Bp = przj_MPFg_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFg_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFg_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFg_Bp_var->GetBinError(i); 

		val_B0s = przj_MPFg_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFg_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFg_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFg_B0s_var->GetBinError(i); 

		val_Bb = przj_MPFg_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFg_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFg_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFg_Bb_var->GetBinError(i); 

		val_Bb = przj_MPFg_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFg_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFg_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFg_Bb_var->GetBinError(i); 

	    errorg = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//ud-jet

		val = przj_MPFud->GetBinContent(i);
		var_val = przj_MPFud_var->GetBinContent(i);
		val_std = przj_MPFud->GetBinError(i);
		var_val_std = przj_MPFud_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFud_B0->GetBinContent(i);
		var_val_B0 = przj_MPFud_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFud_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFud_B0_var->GetBinError(i);  		

		val_Bp = przj_MPFud_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFud_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFud_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFud_Bp_var->GetBinError(i);  

		val_B0s = przj_MPFud_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFud_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFud_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFud_B0s_var->GetBinError(i);  

		val_Bb = przj_MPFud_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFud_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFud_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFud_Bb_var->GetBinError(i);  

		val_Bb = przj_MPFud_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFud_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFud_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFud_Bb_var->GetBinError(i);  

	    errorud = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//s-jet

		val = przj_MPFs->GetBinContent(i);
		var_val = przj_MPFs_var->GetBinContent(i);
		val_std = przj_MPFs->GetBinError(i);
		var_val_std = przj_MPFs_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFs_B0->GetBinContent(i);
		var_val_B0 = przj_MPFs_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFs_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFs_B0_var->GetBinError(i); 

		val_Bp = przj_MPFs_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFs_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFs_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFs_Bp_var->GetBinError(i); 

		val_B0s = przj_MPFs_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFs_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFs_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFs_B0s_var->GetBinError(i); 

		val_Bb = przj_MPFs_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFs_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFs_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFs_Bb_var->GetBinError(i); 

		val_nonB = przj_MPFs_nonB->GetBinContent(i);
		var_val_nonB = przj_MPFs_nonB_var->GetBinContent(i);
		val_std_nonB = przj_MPFs_nonB->GetBinError(i);
		var_val_std_nonB = przj_MPFs_nonB_var->GetBinError(i); 

	    errors = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//c-jet

		val = przj_MPFc->GetBinContent(i);
		var_val = przj_MPFc_var->GetBinContent(i);
		val_std = przj_MPFc->GetBinError(i);
		var_val_std = przj_MPFc_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_MPFc_B0->GetBinContent(i);
		var_val_B0 = przj_MPFc_B0_var->GetBinContent(i);
		val_std_B0 = przj_MPFc_B0->GetBinError(i);
		var_val_std_B0 = przj_MPFc_B0_var->GetBinError(i);  

		val_Bp = przj_MPFc_Bp->GetBinContent(i);
		var_val_Bp = przj_MPFc_Bp_var->GetBinContent(i);
		val_std_Bp = przj_MPFc_Bp->GetBinError(i);
		var_val_std_Bp = przj_MPFc_Bp_var->GetBinError(i);  

		val_B0s = przj_MPFc_B0s->GetBinContent(i);
		var_val_B0s = przj_MPFc_B0s_var->GetBinContent(i);
		val_std_B0s = przj_MPFc_B0s->GetBinError(i);
		var_val_std_B0s = przj_MPFc_B0s_var->GetBinError(i);  

		val_Bb = przj_MPFc_Bb->GetBinContent(i);
		var_val_Bb = przj_MPFc_Bb_var->GetBinContent(i);
		val_std_Bb = przj_MPFc_Bb->GetBinError(i);
		var_val_std_Bb = przj_MPFc_Bb_var->GetBinError(i);  

		val_nonB = przj_MPFc_nonB->GetBinContent(i);
		var_val_nonB = przj_MPFc_nonB_var->GetBinContent(i);
		val_std_nonB = przj_MPFc_nonB->GetBinError(i);
		var_val_std_nonB = przj_MPFc_nonB_var->GetBinError(i);  

	    errorc = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		//Root won't plot 0 values, thus the 0 are replaced with small value

		if (diff->GetBinContent(i) == 0) {
    		diff->SetBinContent(i,1e-6);
		}
		if (diffb_le->GetBinContent(i) == 0) {
    		diffb_le->SetBinContent(i,1e-6);
		}
		if (diffb_nl->GetBinContent(i) == 0) {
    		diffb_nl->SetBinContent(i,1e-6);
		}
		if (diffg->GetBinContent(i) == 0) {
    		diffg->SetBinContent(i,1e-6);
		}
		if (diffud->GetBinContent(i) == 0) {
    		diffud->SetBinContent(i,1e-6);
		}
		if (diffs->GetBinContent(i) == 0) {
    		diffs->SetBinContent(i,1e-6);
		}
		if (diffc->GetBinContent(i) == 0) {
    		diffc->SetBinContent(i,1e-6);
		}

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}

		}

//		cout << "error: " << error << endl;
//		cout << "errorb_le: " << errorb_le << endl;
//		cout << "errorb_nl: " << errorb_nl << endl;
//		cout << "errorg: " << errorg << endl;
//		cout << "errorud: " << errorud << endl;
//		cout << "error:s " << errors << endl;
//		cout << "error:c " << errorc << endl;
//		cout << "" << endl;

	  }
	  diff->Scale(100.0);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_MPF = new TCanvas("MPF","",500,400);
	  canv_MPF->SetLeftMargin(0.13);
	  canv_MPF->SetBottomMargin(0.13);
	  canv_MPF->SetLogx();

	  //Legend
//	  TLegend* lz_MPF = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_MPF = new TLegend(0.37,0.17,0.64,0.39);
	  lz_MPF->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  //Legend
	  //TLegend* lz_MPF = new TLegend(0.55,0.17,0.75,0.42);
	  lz_MPF->SetBorderSize(0);
	  lz_MPF->AddEntry(diff,   "All",   "p");
	  //lz_MPF->AddEntry(diffb,  "b",     "p");
	  lz_MPF->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_MPF->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_MPF->AddEntry(diffc,  "c",     "p");
	  lz_MPF->AddEntry(diffs,  "s",     "p");
	  lz_MPF->AddEntry(diffud, "ud",    "p");
	  lz_MPF->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_MPF->Draw();

	  if (y_fixed) {
	    diff->SetMaximum(0.6);
	    diff->SetMinimum(-0.4);
	  }

	    diff->SetMaximum(0.9);
	    diff->SetMinimum(-0.9);

	  //Save plot
	  canv_MPF->Print("diff_plots/1M_diff_MPF_v1.pdf"); delete canv_MPF;
  } 

  if (pT_plot_ver1) {
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_pTp=0; TProfile *przj_pTpc=0;
	  TProfile *przj_pTps=0; TProfile *przj_pTpud=0; TProfile *przj_pTpg=0;
	  //TProfile *przj_pTpb=0;
	  TProfile *przj_pTpb_nl=0;
	  TProfile *przj_pTpb_le=0;

	  //Different B-hadron categories

	  TProfile *przj_pTp_B0=0; TProfile *przj_pTpc_B0=0;
	  TProfile *przj_pTps_B0=0; TProfile *przj_pTpud_B0=0; TProfile *przj_pTpg_B0=0;
	  //TProfile *przj_pTpb_B0=0;
	  TProfile *przj_pTpb_nl_B0=0;
	  TProfile *przj_pTpb_le_B0=0;

	  TProfile *przj_pTp_Bp=0; TProfile *przj_pTpc_Bp=0;
	  TProfile *przj_pTps_Bp=0; TProfile *przj_pTpud_Bp=0; TProfile *przj_pTpg_Bp=0;
	  //TProfile *przj_pTpb_Bp=0;
	  TProfile *przj_pTpb_nl_Bp=0;
	  TProfile *przj_pTpb_le_Bp=0;

	  TProfile *przj_pTp_B0s=0; TProfile *przj_pTpc_B0s=0;
	  TProfile *przj_pTps_B0s=0; TProfile *przj_pTpud_B0s=0; TProfile *przj_pTpg_B0s=0;
	  //TProfile *przj_pTpb_B0s=0;
	  TProfile *przj_pTpb_nl_B0s=0;
	  TProfile *przj_pTpb_le_B0s=0;

	  TProfile *przj_pTp_Bb=0; TProfile *przj_pTpc_Bb=0;
	  TProfile *przj_pTps_Bb=0; TProfile *przj_pTpud_Bb=0; TProfile *przj_pTpg_Bb=0;
	  //TProfile *przj_pTpb_Bb=0;
	  TProfile *przj_pTpb_nl_Bb=0;
	  TProfile *przj_pTpb_le_Bb=0;

	  TProfile *przj_pTp_nonB=0; TProfile *przj_pTpc_nonB=0;
	  TProfile *przj_pTps_nonB=0; TProfile *przj_pTpud_nonB=0; TProfile *przj_pTpg_nonB=0;
	  //TProfile *przj_pTpb_nonB=0;
	  TProfile *przj_pTpb_nl_nonB=0;
	  TProfile *przj_pTpb_le_nonB=0;

	  //The weighted sample

	  TProfile *przj_pTp_var=0;   TProfile *przj_pTpc_var=0;
	  TProfile *przj_pTps_var=0; TProfile *przj_pTpud_var=0; TProfile *przj_pTpg_var=0;
	  //TProfile *przj_pTpb_var=0;
	  TProfile *przj_pTpb_nl_var=0;
	  TProfile *przj_pTpb_le_var=0;

	  //Different B-hadron categories

	  TProfile *przj_pTp_B0_var=0; TProfile *przj_pTpc_B0_var=0;
	  TProfile *przj_pTps_B0_var=0; TProfile *przj_pTpud_B0_var=0; TProfile *przj_pTpg_B0_var=0;
	  //TProfile *przj_pTpb_B0_var=0;
	  TProfile *przj_pTpb_nl_B0_var=0;
	  TProfile *przj_pTpb_le_B0_var=0;

	  TProfile *przj_pTp_Bp_var=0; TProfile *przj_pTpc_Bp_var=0;
	  TProfile *przj_pTps_Bp_var=0; TProfile *przj_pTpud_Bp_var=0; TProfile *przj_pTpg_Bp_var=0;
	  //TProfile *przj_pTpb_Bp_var=0;
	  TProfile *przj_pTpb_nl_Bp_var=0;
	  TProfile *przj_pTpb_le_Bp_var=0;

	  TProfile *przj_pTp_B0s_var=0; TProfile *przj_pTpc_B0s_var=0;
	  TProfile *przj_pTps_B0s_var=0; TProfile *przj_pTpud_B0s_var=0; TProfile *przj_pTpg_B0s_var=0;
	  //TProfile *przj_pTpb_B0s_var=0;
	  TProfile *przj_pTpb_nl_B0s_var=0;
	  TProfile *przj_pTpb_le_B0s_var=0;

	  TProfile *przj_pTp_Bb_var=0; TProfile *przj_pTpc_Bb_var=0;
	  TProfile *przj_pTps_Bb_var=0; TProfile *przj_pTpud_Bb_var=0; TProfile *przj_pTpg_Bb_var=0;
	  //TProfile *przj_pTpb_Bb_var=0;
	  TProfile *przj_pTpb_nl_Bb_var=0;
	  TProfile *przj_pTpb_le_Bb_var=0;

	  TProfile *przj_pTp_nonB_var=0; TProfile *przj_pTpc_nonB_var=0;
	  TProfile *przj_pTps_nonB_var=0; TProfile *przj_pTpud_nonB_var=0; TProfile *przj_pTpg_nonB_var=0;
	  //TProfile *przj_pTpb_nonB_var=0;
	  TProfile *przj_pTpb_nl_nonB_var=0;
	  TProfile *przj_pTpb_le_nonB_var=0;

	  // Read the normal sample

	  fzj->GetObject("prpTbal",   przj_pTp);
	  //fzj->GetObject("prpTbalb",  przj_pTpb);
	  fzj->GetObject("prpTbalb_nl",  przj_pTpb_nl);
	  fzj->GetObject("prpTbalb_le",  przj_pTpb_le);
	  fzj->GetObject("prpTbalc",  przj_pTpc);
	  fzj->GetObject("prpTbals",  przj_pTps);
	  fzj->GetObject("prpTbalud", przj_pTpud);
	  fzj->GetObject("prpTbalg",  przj_pTpg);

	  //Different B-hadron categories

	  fzj->GetObject("prpTbal_B0",   przj_pTp_B0);
	  //fzj->GetObject("prpTbalb_B0",  przj_pTpb_B0);
	  fzj->GetObject("prpTbalb_nl_B0",  przj_pTpb_nl_B0);
	  fzj->GetObject("prpTbalb_le_B0",  przj_pTpb_le_B0);
	  fzj->GetObject("prpTbalc_B0",  przj_pTpc_B0);
	  fzj->GetObject("prpTbals_B0",  przj_pTps_B0);
	  fzj->GetObject("prpTbalud_B0", przj_pTpud_B0);
	  fzj->GetObject("prpTbalg_B0",  przj_pTpg_B0);

	  fzj->GetObject("prpTbal_Bp",   przj_pTp_Bp);
	  //fzj->GetObject("prpTbalb_Bp",  przj_pTpb_Bp);
	  fzj->GetObject("prpTbalb_nl_Bp",  przj_pTpb_nl_Bp);
	  fzj->GetObject("prpTbalb_le_Bp",  przj_pTpb_le_Bp);
	  fzj->GetObject("prpTbalc_Bp",  przj_pTpc_Bp);
	  fzj->GetObject("prpTbals_Bp",  przj_pTps_Bp);
	  fzj->GetObject("prpTbalud_Bp", przj_pTpud_Bp);
	  fzj->GetObject("prpTbalg_Bp",  przj_pTpg_Bp);

	  fzj->GetObject("prpTbal_B0s",   przj_pTp_B0s);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_B0s);
	  fzj->GetObject("prpTbalb_nl_B0s",  przj_pTpb_nl_B0s);
	  fzj->GetObject("prpTbalb_le_B0s",  przj_pTpb_le_B0s);
	  fzj->GetObject("prpTbalc_B0s",  przj_pTpc_B0s);
	  fzj->GetObject("prpTbals_B0s",  przj_pTps_B0s);
	  fzj->GetObject("prpTbalud_B0s", przj_pTpud_B0s);
	  fzj->GetObject("prpTbalg_B0s",  przj_pTpg_B0s);

	  fzj->GetObject("prpTbal_Bb",   przj_pTp_Bb);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_Bb);
	  fzj->GetObject("prpTbalb_nl_Bb",  przj_pTpb_nl_Bb);
	  fzj->GetObject("prpTbalb_le_Bb",  przj_pTpb_le_Bb);
	  fzj->GetObject("prpTbalc_Bb",  przj_pTpc_Bb);
	  fzj->GetObject("prpTbals_Bb",  przj_pTps_Bb);
	  fzj->GetObject("prpTbalud_Bb", przj_pTpud_Bb);
	  fzj->GetObject("prpTbalg_Bb",  przj_pTpg_Bb);

	  fzj->GetObject("prpTbal_nonB",   przj_pTp_nonB);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_nonB);
	  fzj->GetObject("prpTbalb_nl_nonB",  przj_pTpb_nl_nonB);
	  fzj->GetObject("prpTbalb_le_nonB",  przj_pTpb_le_nonB);
	  fzj->GetObject("prpTbalc_nonB",  przj_pTpc_nonB);
	  fzj->GetObject("prpTbals_nonB",  przj_pTps_nonB);
	  fzj->GetObject("prpTbalud_nonB", przj_pTpud_nonB);
	  fzj->GetObject("prpTbalg_nonB",  przj_pTpg_nonB);

      //Read the weighted sample
	
	  fzj_var->GetObject("prpTbal",   przj_pTp_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_var);
	  fzj_var->GetObject("prpTbalb_nl",  przj_pTpb_nl_var);
	  fzj_var->GetObject("prpTbalb_le",  przj_pTpb_le_var);
	  fzj_var->GetObject("prpTbalc",  przj_pTpc_var);
	  fzj_var->GetObject("prpTbals",  przj_pTps_var);
	  fzj_var->GetObject("prpTbalud", przj_pTpud_var);
	  fzj_var->GetObject("prpTbalg",  przj_pTpg_var);

	  //Different B-hadron categories

	  fzj->GetObject("prpTbal_B0",   przj_pTp_B0_var);
	  //fzj->GetObject("prpTbalb_B0",  przj_pTpb_B0_var);
	  fzj->GetObject("prpTbalb_nl_B0",  przj_pTpb_nl_B0_var);
	  fzj->GetObject("prpTbalb_le_B0",  przj_pTpb_le_B0_var);
	  fzj->GetObject("prpTbalc_B0",  przj_pTpc_B0_var);
	  fzj->GetObject("prpTbals_B0",  przj_pTps_B0_var);
	  fzj->GetObject("prpTbalud_B0", przj_pTpud_B0_var);
	  fzj->GetObject("prpTbalg_B0",  przj_pTpg_B0_var);

	  fzj->GetObject("prpTbal_Bp",   przj_pTp_Bp_var);
	  //fzj->GetObject("prpTbalb_Bp",  przj_pTpb_Bp_var);
	  fzj->GetObject("prpTbalb_nl_Bp",  przj_pTpb_nl_Bp_var);
	  fzj->GetObject("prpTbalb_le_Bp",  przj_pTpb_le_Bp_var);
	  fzj->GetObject("prpTbalc_Bp",  przj_pTpc_Bp_var);
	  fzj->GetObject("prpTbals_Bp",  przj_pTps_Bp_var);
	  fzj->GetObject("prpTbalud_Bp", przj_pTpud_Bp_var);
	  fzj->GetObject("prpTbalg_Bp",  przj_pTpg_Bp_var);

	  fzj->GetObject("prpTbal_B0s",   przj_pTp_B0s_var);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_B0s_var);
	  fzj->GetObject("prpTbalb_nl_B0s",  przj_pTpb_nl_B0s_var);
	  fzj->GetObject("prpTbalb_le_B0s",  przj_pTpb_le_B0s_var);
	  fzj->GetObject("prpTbalc_B0s",  przj_pTpc_B0s_var);
	  fzj->GetObject("prpTbals_B0s",  przj_pTps_B0s_var);
	  fzj->GetObject("prpTbalud_B0s", przj_pTpud_B0s_var);
	  fzj->GetObject("prpTbalg_B0s",  przj_pTpg_B0s_var);

	  fzj->GetObject("prpTbal_Bb",   przj_pTp_Bb_var);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_Bb_var);
	  fzj->GetObject("prpTbalb_nl_Bb",  przj_pTpb_nl_Bb_var);
	  fzj->GetObject("prpTbalb_le_Bb",  przj_pTpb_le_Bb_var);
	  fzj->GetObject("prpTbalc_Bb",  przj_pTpc_Bb_var);
	  fzj->GetObject("prpTbals_Bb",  przj_pTps_Bb_var);
	  fzj->GetObject("prpTbalud_Bb", przj_pTpud_Bb_var);
	  fzj->GetObject("prpTbalg_Bb",  przj_pTpg_Bb_var);

	  fzj->GetObject("prpTbal_nonB",   przj_pTp_nonB_var);
	  //fzj->GetObject("prpTbalb",  przj_pTpb_nonB_var);
	  fzj->GetObject("prpTbalb_nl_nonB",  przj_pTpb_nl_nonB_var);
	  fzj->GetObject("prpTbalb_le_nonB",  przj_pTpb_le_nonB_var);
	  fzj->GetObject("prpTbalc_nonB",  przj_pTpc_nonB_var);
	  fzj->GetObject("prpTbals_nonB",  przj_pTps_nonB_var);
	  fzj->GetObject("prpTbalud_nonB", przj_pTpud_nonB_var);
	  fzj->GetObject("prpTbalg_nonB",  przj_pTpg_nonB_var);

	  TH1D* hzj_pTp   = przj_pTp  ->ProjectionX();
	  //TH1D* hzj_pTpb  = przj_pTpb ->ProjectionX();
	  TH1D* hzj_pTpb_nl  = przj_pTpb_nl ->ProjectionX();
	  TH1D* hzj_pTpb_le  = przj_pTpb_le ->ProjectionX();
	  TH1D* hzj_pTpc  = przj_pTpc ->ProjectionX();
	  TH1D* hzj_pTps  = przj_pTps ->ProjectionX();
	  TH1D* hzj_pTpud = przj_pTpud->ProjectionX();
	  TH1D* hzj_pTpg  = przj_pTpg ->ProjectionX();

	  TH1D* hzj_pTp_var   = przj_pTp_var  ->ProjectionX();
	  //TH1D* hzj_pTpb_var  = przj_pTpb_var ->ProjectionX();
	  TH1D* hzj_pTpb_nl_var  = przj_pTpb_nl_var ->ProjectionX();
	  TH1D* hzj_pTpb_le_var  = przj_pTpb_le_var ->ProjectionX();
	  TH1D* hzj_pTpc_var  = przj_pTpc_var ->ProjectionX();
	  TH1D* hzj_pTps_var  = przj_pTps_var ->ProjectionX();
	  TH1D* hzj_pTpud_var = przj_pTpud_var->ProjectionX();
	  TH1D* hzj_pTpg_var  = przj_pTpg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_pTp->Clone();
	  //TH1D* diffb = (TH1D*) hzj_pTpb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_pTpb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_pTpb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_pTpc->Clone();
	  TH1D* diffs = (TH1D*) hzj_pTps->Clone();
	  TH1D* diffud = (TH1D*) hzj_pTpud->Clone();
	  TH1D* diffg = (TH1D*) hzj_pTpg->Clone();

	  diff->Add(hzj_pTp_var,-1);
	  //diffb->Add(hzj_pTpb_var,-1);
	  diffb_nl->Add(hzj_pTpb_nl_var,-1);
	  diffb_le->Add(hzj_pTpb_le_var,-1);
	  diffc->Add(hzj_pTpc_var,-1);
	  diffs->Add(hzj_pTps_var,-1);
	  diffud->Add(hzj_pTpud_var,-1);
	  diffg->Add(hzj_pTpg_var,-1);

//	  diff->Divide(hzj_pTp);
//	  //diffb->Add(hzj_pTpb_var,-1);
//	  diffb_nl->Divide(hzj_pTpb_nl);
//	  diffb_le->Divide(hzj_pTpb_le);
//	  diffc->Divide(hzj_pTpc);
//	  diffs->Divide(hzj_pTps);
//	  diffud->Divide(hzj_pTpud);
//	  diffg->Divide(hzj_pTpg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	  double val_B0; double var_val_B0; double val_std_B0; double var_val_std_B0;
	  double val_Bp; double var_val_Bp; double val_std_Bp; double var_val_std_Bp;
	  double val_B0s; double var_val_B0s; double val_std_B0s; double var_val_std_B0s;
	  double val_Bb; double var_val_Bb; double val_std_Bb; double var_val_std_Bb;
	  double val_nonB; double var_val_nonB; double val_std_nonB; double var_val_std_nonB;


	  for (int i = 1; i < 15; i++){

		//The normal case

		val = przj_pTp->GetBinContent(i);
		var_val = przj_pTp_var->GetBinContent(i);
		val_std = przj_pTp->GetBinError(i);
		var_val_std = przj_pTp_var->GetBinError(i);  

	    //Different B-hadron categories

		val_B0 = przj_pTp_B0->GetBinContent(i);
		var_val_B0 = przj_pTp_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTp_B0->GetBinError(i);
		var_val_std_B0 = przj_pTp_B0_var->GetBinError(i);  

		val_Bp = przj_pTp_Bp->GetBinContent(i);
		var_val_Bp = przj_pTp_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTp_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTp_Bp_var->GetBinError(i);  

		val_B0s = przj_pTp_B0s->GetBinContent(i);
		var_val_B0s = przj_pTp_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTp_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTp_B0s_var->GetBinError(i);  

		val_Bb = przj_pTp_Bb->GetBinContent(i);
		var_val_Bb = przj_pTp_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTp_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTp_Bb_var->GetBinError(i);  

		val_nonB = przj_pTp_nonB->GetBinContent(i);
		var_val_nonB = przj_pTp_nonB_var->GetBinContent(i);
		val_std_nonB = przj_pTp_nonB->GetBinError(i);
		var_val_std_nonB = przj_pTp_nonB_var->GetBinError(i); 
 
	    error = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//b-jet semileptonic

		val = przj_pTpb_le->GetBinContent(i);
		var_val = przj_pTpb_le_var->GetBinContent(i);
		val_std = przj_pTpb_le->GetBinError(i);
		var_val_std = przj_pTpb_le_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTpb_le_B0->GetBinContent(i);
		var_val_B0 = przj_pTpb_le_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTpb_le_B0->GetBinError(i);
		var_val_std_B0 = przj_pTpb_le_B0_var->GetBinError(i); 

		val_Bp = przj_pTpb_le_Bp->GetBinContent(i);
		var_val_Bp = przj_pTpb_le_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTpb_le_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTpb_le_Bp_var->GetBinError(i);  

		val_B0s = przj_pTpb_le_B0s->GetBinContent(i);
		var_val_B0s = przj_pTpb_le_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTpb_le_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTpb_le_B0s_var->GetBinError(i);  

		val_Bb = przj_pTpb_le_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpb_le_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpb_le_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpb_le_Bb_var->GetBinError(i);  

		val_nonB = przj_pTpb_le_nonB->GetBinContent(i);
		var_val_nonB = przj_pTpb_le_nonB_var->GetBinContent(i);
		val_std_nonB = przj_pTpb_le_nonB->GetBinError(i);
		var_val_std_nonB = przj_pTpb_le_nonB_var->GetBinError(i); 

	    errorb_le = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));  

		//b-jet non-semileptonic

		val = przj_pTpb_nl->GetBinContent(i);
		var_val = przj_pTpb_nl_var->GetBinContent(i);
		val_std = przj_pTpb_nl->GetBinError(i);
		var_val_std = przj_pTpb_nl_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTpb_nl_B0->GetBinContent(i);
		var_val_B0 = przj_pTpb_nl_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTpb_nl_B0->GetBinError(i);
		var_val_std_B0 = przj_pTpb_nl_B0_var->GetBinError(i); 

		val_Bp = przj_pTpb_nl_Bp->GetBinContent(i);
		var_val_Bp = przj_pTpb_nl_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTpb_nl_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTpb_nl_Bp_var->GetBinError(i); 

		val_B0s = przj_pTpb_nl_B0s->GetBinContent(i);
		var_val_B0s = przj_pTpb_nl_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTpb_nl_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTpb_nl_B0s_var->GetBinError(i); 

		val_Bb = przj_pTpb_nl_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpb_nl_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpb_nl_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpb_nl_Bb_var->GetBinError(i); 

		val_Bb = przj_pTpb_nl_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpb_nl_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpb_nl_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpb_nl_Bb_var->GetBinError(i); 

	    errorb_nl = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//g-jet

		val = przj_pTpg->GetBinContent(i);
		var_val = przj_pTpg_var->GetBinContent(i);
		val_std = przj_pTpg->GetBinError(i);
		var_val_std = przj_pTpg_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTpg_B0->GetBinContent(i);
		var_val_B0 = przj_pTpg_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTpg_B0->GetBinError(i);
		var_val_std_B0 = przj_pTpg_B0_var->GetBinError(i);  

		val_Bp = przj_pTpg_Bp->GetBinContent(i);
		var_val_Bp = przj_pTpg_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTpg_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTpg_Bp_var->GetBinError(i); 

		val_B0s = przj_pTpg_B0s->GetBinContent(i);
		var_val_B0s = przj_pTpg_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTpg_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTpg_B0s_var->GetBinError(i); 

		val_Bb = przj_pTpg_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpg_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpg_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpg_Bb_var->GetBinError(i); 

		val_Bb = przj_pTpg_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpg_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpg_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpg_Bb_var->GetBinError(i); 

	    errorg = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//ud-jet

		val = przj_pTpud->GetBinContent(i);
		var_val = przj_pTpud_var->GetBinContent(i);
		val_std = przj_pTpud->GetBinError(i);
		var_val_std = przj_pTpud_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTpud_B0->GetBinContent(i);
		var_val_B0 = przj_pTpud_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTpud_B0->GetBinError(i);
		var_val_std_B0 = przj_pTpud_B0_var->GetBinError(i);  		

		val_Bp = przj_pTpud_Bp->GetBinContent(i);
		var_val_Bp = przj_pTpud_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTpud_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTpud_Bp_var->GetBinError(i);  

		val_B0s = przj_pTpud_B0s->GetBinContent(i);
		var_val_B0s = przj_pTpud_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTpud_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTpud_B0s_var->GetBinError(i);  

		val_Bb = przj_pTpud_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpud_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpud_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpud_Bb_var->GetBinError(i);  

		val_Bb = przj_pTpud_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpud_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpud_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpud_Bb_var->GetBinError(i);  

	    errorud = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//s-jet

		val = przj_pTps->GetBinContent(i);
		var_val = przj_pTps_var->GetBinContent(i);
		val_std = przj_pTps->GetBinError(i);
		var_val_std = przj_pTps_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTps_B0->GetBinContent(i);
		var_val_B0 = przj_pTps_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTps_B0->GetBinError(i);
		var_val_std_B0 = przj_pTps_B0_var->GetBinError(i); 

		val_Bp = przj_pTps_Bp->GetBinContent(i);
		var_val_Bp = przj_pTps_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTps_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTps_Bp_var->GetBinError(i); 

		val_B0s = przj_pTps_B0s->GetBinContent(i);
		var_val_B0s = przj_pTps_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTps_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTps_B0s_var->GetBinError(i); 

		val_Bb = przj_pTps_Bb->GetBinContent(i);
		var_val_Bb = przj_pTps_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTps_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTps_Bb_var->GetBinError(i); 

		val_nonB = przj_pTps_nonB->GetBinContent(i);
		var_val_nonB = przj_pTps_nonB_var->GetBinContent(i);
		val_std_nonB = przj_pTps_nonB->GetBinError(i);
		var_val_std_nonB = przj_pTps_nonB_var->GetBinError(i); 

	    errors = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		//c-jet

		val = przj_pTpc->GetBinContent(i);
		var_val = przj_pTpc_var->GetBinContent(i);
		val_std = przj_pTpc->GetBinError(i);
		var_val_std = przj_pTpc_var->GetBinError(i);  

		//Different B-hadron categories

		val_B0 = przj_pTpc_B0->GetBinContent(i);
		var_val_B0 = przj_pTpc_B0_var->GetBinContent(i);
		val_std_B0 = przj_pTpc_B0->GetBinError(i);
		var_val_std_B0 = przj_pTpc_B0_var->GetBinError(i);  

		val_Bp = przj_pTpc_Bp->GetBinContent(i);
		var_val_Bp = przj_pTpc_Bp_var->GetBinContent(i);
		val_std_Bp = przj_pTpc_Bp->GetBinError(i);
		var_val_std_Bp = przj_pTpc_Bp_var->GetBinError(i);  

		val_B0s = przj_pTpc_B0s->GetBinContent(i);
		var_val_B0s = przj_pTpc_B0s_var->GetBinContent(i);
		val_std_B0s = przj_pTpc_B0s->GetBinError(i);
		var_val_std_B0s = przj_pTpc_B0s_var->GetBinError(i);  

		val_Bb = przj_pTpc_Bb->GetBinContent(i);
		var_val_Bb = przj_pTpc_Bb_var->GetBinContent(i);
		val_std_Bb = przj_pTpc_Bb->GetBinError(i);
		var_val_std_Bb = przj_pTpc_Bb_var->GetBinError(i);  

		val_nonB = przj_pTpc_nonB->GetBinContent(i);
		var_val_nonB = przj_pTpc_nonB_var->GetBinContent(i);
		val_std_nonB = przj_pTpc_nonB->GetBinError(i);
		var_val_std_nonB = przj_pTpc_nonB_var->GetBinError(i);  

	    errorc = sqrt(pow((wB0-1)*val_std_B0 ,2) + pow((wBp-1)*val_std_Bp ,2)
					+ pow((wB0s-1)*val_std_B0s ,2) + pow((wBb-1)*val_std_Bb ,2));

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		//Root won't plot 0 values, thus the 0 are replaced with small value

		if (diff->GetBinContent(i) == 0) {
    		diff->SetBinContent(i,1e-6);
		}
		if (diffb_le->GetBinContent(i) == 0) {
    		diffb_le->SetBinContent(i,1e-6);
		}
		if (diffb_nl->GetBinContent(i) == 0) {
    		diffb_nl->SetBinContent(i,1e-6);
		}
		if (diffg->GetBinContent(i) == 0) {
    		diffg->SetBinContent(i,1e-6);
		}
		if (diffud->GetBinContent(i) == 0) {
    		diffud->SetBinContent(i,1e-6);
		}
		if (diffs->GetBinContent(i) == 0) {
    		diffs->SetBinContent(i,1e-6);
		}
		if (diffc->GetBinContent(i) == 0) {
    		diffc->SetBinContent(i,1e-6);
		}

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}

		}

		cout << "error: " << error << endl;
		cout << "errorb_le: " << errorb_le << endl;
		cout << "errorb_nl: " << errorb_nl << endl;
		cout << "errorg: " << errorg << endl;
		cout << "errorud: " << errorud << endl;
		cout << "error:s " << errors << endl;
		cout << "error:c " << errorc << endl;
		cout << "" << endl;

	  }
	  diff->Scale(100.0);
	  //diffb->Add(hzj_pTpb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_pTp = new TCanvas("pTp","",500,400);
	  canv_pTp->SetLeftMargin(0.13);
	  canv_pTp->SetBottomMargin(0.13);
	  canv_pTp->SetLogx();

	  //Legend
//	  TLegend* lz_pTp = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_pTp = new TLegend(0.37,0.17,0.64,0.39);
	  lz_pTp->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  //Legend
	  //TLegend* lz_pTp = new TLegend(0.55,0.17,0.75,0.42);
	  lz_pTp->SetBorderSize(0);
	  lz_pTp->AddEntry(diff,   "All",   "p");
	  //lz_pTp->AddEntry(diffb,  "b",     "p");
	  lz_pTp->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_pTp->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_pTp->AddEntry(diffc,  "c",     "p");
	  lz_pTp->AddEntry(diffs,  "s",     "p");
	  lz_pTp->AddEntry(diffud, "ud",    "p");
	  lz_pTp->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_pTp->Draw();

	  if (y_fixed) {
	    diff->SetMaximum(0.6);
	    diff->SetMinimum(-0.4);
	  }

	    diff->SetMaximum(0.9);
	    diff->SetMinimum(-0.9);

	  //Save plot
	  //Save plot
	  canv_pTp->Print("diff_plots//1M_diff_pTbal_v1.pdf"); delete canv_pTp;
  } 


  if (mpf_plot) {

	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");

	  TProfile *przj_MPF=0; TProfile *przj_MPFc=0;
	  TProfile *przj_MPFs=0; TProfile *przj_MPFud=0; TProfile *przj_MPFg=0;
	  //TProfile *przj_MPFb=0;
	  TProfile *przj_MPFb_nl=0;
	  TProfile *przj_MPFb_le=0;

	  TProfile *przj_MPF_var=0;   TProfile *przj_MPFc_var=0;
	  TProfile *przj_MPFs_var=0; TProfile *przj_MPFud_var=0; TProfile *przj_MPFg_var=0;
	  //TProfile *przj_MPFb_var=0;
	  TProfile *przj_MPFb_nl_var=0;
	  TProfile *przj_MPFb_le_var=0;

	  fzj->GetObject("prMPF",   przj_MPF);
	  //fzj->GetObject("prMPFb",  przj_MPFb);
	  fzj->GetObject("prMPFb_nl",  przj_MPFb_nl);
	  fzj->GetObject("prMPFb_le",  przj_MPFb_le);
	  fzj->GetObject("prMPFc",  przj_MPFc);
	  fzj->GetObject("prMPFs",  przj_MPFs);
	  fzj->GetObject("prMPFud", przj_MPFud);
	  fzj->GetObject("prMPFg",  przj_MPFg);

	  fzj_var->GetObject("prMPF",   przj_MPF_var);
	  //fzj_var->GetObject("prMPFb",  przj_MPFb_var);
	  fzj_var->GetObject("prMPFb_nl",  przj_MPFb_nl_var);
	  fzj_var->GetObject("prMPFb_le",  przj_MPFb_le_var);
	  fzj_var->GetObject("prMPFc",  przj_MPFc_var);
	  fzj_var->GetObject("prMPFs",  przj_MPFs_var);
	  fzj_var->GetObject("prMPFud", przj_MPFud_var);
	  fzj_var->GetObject("prMPFg",  przj_MPFg_var);

	  TH1D* hzj_MPF   = przj_MPF  ->ProjectionX();
	  //TH1D* hzj_MPFb  = przj_MPFb ->ProjectionX();
	  TH1D* hzj_MPFb_nl  = przj_MPFb_nl ->ProjectionX();
	  TH1D* hzj_MPFb_le  = przj_MPFb_le ->ProjectionX();
	  TH1D* hzj_MPFc  = przj_MPFc ->ProjectionX();
	  TH1D* hzj_MPFs  = przj_MPFs ->ProjectionX();
	  TH1D* hzj_MPFud = przj_MPFud->ProjectionX();
	  TH1D* hzj_MPFg  = przj_MPFg ->ProjectionX();

	  TH1D* hzj_MPF_var   = przj_MPF_var  ->ProjectionX();
	  //TH1D* hzj_MPFb_var  = przj_MPFb_var ->ProjectionX();
	  TH1D* hzj_MPFb_nl_var  = przj_MPFb_nl_var ->ProjectionX();
	  TH1D* hzj_MPFb_le_var  = przj_MPFb_le_var ->ProjectionX();
	  TH1D* hzj_MPFc_var  = przj_MPFc_var ->ProjectionX();
	  TH1D* hzj_MPFs_var  = przj_MPFs_var ->ProjectionX();
	  TH1D* hzj_MPFud_var = przj_MPFud_var->ProjectionX();
	  TH1D* hzj_MPFg_var  = przj_MPFg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_MPF->Clone();
	  //TH1D* diffb = (TH1D*) hzj_MPFb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_MPFb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_MPFb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_MPFc->Clone();
	  TH1D* diffs = (TH1D*) hzj_MPFs->Clone();
	  TH1D* diffud = (TH1D*) hzj_MPFud->Clone();
	  TH1D* diffg = (TH1D*) hzj_MPFg->Clone();

	  diff->Add(hzj_MPF_var,-1);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Add(hzj_MPFb_nl_var,-1);
	  diffb_le->Add(hzj_MPFb_le_var,-1);
	  diffc->Add(hzj_MPFc_var,-1);
	  diffs->Add(hzj_MPFs_var,-1);
	  diffud->Add(hzj_MPFud_var,-1);
	  diffg->Add(hzj_MPFg_var,-1);

	  diff->Divide(hzj_MPF);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Divide(hzj_MPFb_nl);
	  diffb_le->Divide(hzj_MPFb_le);
	  diffc->Divide(hzj_MPFc);
	  diffs->Divide(hzj_MPFs);
	  diffud->Divide(hzj_MPFud);
	  diffg->Divide(hzj_MPFg);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;


	  for (int i = 1; i < 15; i++){

		val = przj_MPF->GetBinContent(i);
		var_val = przj_MPF_var->GetBinContent(i);
		val_std = przj_MPF->GetBinError(i);
		var_val_std = przj_MPF_var->GetBinError(i);  
	    error = 1;

		val = przj_MPFb_le->GetBinContent(i);
		var_val = przj_MPFb_le_var->GetBinContent(i);
		val_std = przj_MPFb_le->GetBinError(i);
		var_val_std = przj_MPFb_le_var->GetBinError(i);  
	    errorb_le = 1;

		val = przj_MPFb_nl->GetBinContent(i);
		var_val = przj_MPFb_nl_var->GetBinContent(i);
		val_std = przj_MPFb_nl->GetBinError(i);
		var_val_std = przj_MPFb_nl_var->GetBinError(i);  
	    errorb_nl = 1;

		val = przj_MPFg->GetBinContent(i);
		var_val = przj_MPFg_var->GetBinContent(i);
		val_std = przj_MPFg->GetBinError(i);
		var_val_std = przj_MPFg_var->GetBinError(i);  
	    errorg = 1;

		val = przj_MPFud->GetBinContent(i);
		var_val = przj_MPFud_var->GetBinContent(i);
		val_std = przj_MPFud->GetBinError(i);
		var_val_std = przj_MPFud_var->GetBinError(i);  
	    errorud = 1;

		val = przj_MPFs->GetBinContent(i);
		var_val = przj_MPFs_var->GetBinContent(i);
		val_std = przj_MPFs->GetBinError(i);
		var_val_std = przj_MPFs_var->GetBinError(i);  
	    errors = 1;

		val = przj_MPFc->GetBinContent(i);
		var_val = przj_MPFc_var->GetBinContent(i);
		val_std = przj_MPFc->GetBinError(i);
		var_val_std = przj_MPFc_var->GetBinError(i);  
	    errorc = 1;

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}

		}

//		cout << "error: " << error << endl;
//		cout << "errorb_le: " << errorb_le << endl;
//		cout << "errorb_nl: " << errorb_nl << endl;
//		cout << "errorg: " << errorg << endl;
//		cout << "errorud: " << errorud << endl;
//		cout << "error:s " << errors << endl;
//		cout << "error:c " << errorc << endl;
//		cout << "" << endl;

	  }
	  diff->Scale(100.0);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_MPF = new TCanvas("MPF","",500,400);
	  canv_MPF->SetLeftMargin(0.13);
	  canv_MPF->SetBottomMargin(0.13);
	  canv_MPF->SetLogx();

	  //Legend
//	  TLegend* lz_MPF = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_MPF = new TLegend(0.37,0.17,0.64,0.39);
	  lz_MPF->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  //Legend
	  //TLegend* lz_MPF = new TLegend(0.55,0.17,0.75,0.42);
	  lz_MPF->SetBorderSize(0);
	  lz_MPF->AddEntry(diff,   "All",   "p");
	  //lz_MPF->AddEntry(diffb,  "b",     "p");
	  lz_MPF->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_MPF->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_MPF->AddEntry(diffc,  "c",     "p");
	  lz_MPF->AddEntry(diffs,  "s",     "p");
	  lz_MPF->AddEntry(diffud, "ud",    "p");
	  lz_MPF->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_MPF->Draw();

	  if (y_fixed) {
	    diff->SetMaximum(0.6);
	    diff->SetMinimum(-0.4);
	  }

	    diff->SetMaximum(0.9);
	    diff->SetMinimum(-0.9);

	  //Save plot
	  canv_MPF->Print("diff_plots/1M_diff_MPF.pdf"); delete canv_MPF;
  } 
  
  if (pT_plot) {
	  //PT difference plot
//	  TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
//	  TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");
	  TFile* fzj = TFile::Open(OpenName.c_str());
	  TFile* fzj_var = TFile::Open(var_OpenName.c_str());

	  TProfile *przj_pTp=0;  TProfile *przj_pTpc=0;
	  TProfile *przj_pTps=0; TProfile *przj_pTpud=0; TProfile *przj_pTpg=0;
	  //TProfile *przj_pTpb=0;
	  TProfile *przj_pTpb_nl=0;
	  TProfile *przj_pTpb_le=0;

	  TProfile *przj_pTp_var=0;  TProfile *przj_pTpc_var=0;
	  TProfile *przj_pTps_var=0; TProfile *przj_pTpud_var=0; TProfile *przj_pTpg_var=0;
	  //TProfile *przj_pTpb_var=0;
	  TProfile *przj_pTpb_nl_var=0;
	  TProfile *przj_pTpb_le_var=0;

	  fzj->GetObject("prpTbal",   przj_pTp);
	  //fzj->GetObject("prpTbalb",  przj_pTpb);
	  fzj->GetObject("prpTbalb_nl",  przj_pTpb_nl);
	  fzj->GetObject("prpTbalb_le",  przj_pTpb_le);
	  fzj->GetObject("prpTbalc",  przj_pTpc);
	  fzj->GetObject("prpTbals",  przj_pTps);
	  fzj->GetObject("prpTbalud", przj_pTpud);
	  fzj->GetObject("prpTbalg",  przj_pTpg);

	  fzj_var->GetObject("prpTbal",   przj_pTp_var);
	  //fzj_var->GetObject("prpTbalb",  przj_pTpb_var);
	  fzj_var->GetObject("prpTbalb_nl",  przj_pTpb_nl_var);
	  fzj_var->GetObject("prpTbalb_le",  przj_pTpb_le_var);
	  fzj_var->GetObject("prpTbalc",  przj_pTpc_var);
	  fzj_var->GetObject("prpTbals",  przj_pTps_var);
	  fzj_var->GetObject("prpTbalud", przj_pTpud_var);
	  fzj_var->GetObject("prpTbalg",  przj_pTpg_var);

	  vector<Double_t>* cov_arr_prpTbal = new vector<Double_t>();
	  //vector<Double_t>* cov_arr_prMPFb = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbalb_le = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbalb_nl = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbalg = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTballq = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbalud = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbals = new vector<Double_t>();
	  vector<Double_t>* cov_arr_prpTbalc = new vector<Double_t>();

	  fzj_var->GetObject("cov_arr_prpTbal", cov_arr_prpTbal);
	  //fzj_var->GetObject("cov_arr_prMPFb", cov_arr_prMPFb);
	  fzj_var->GetObject("cov_arr_prpTbalb_le", cov_arr_prpTbalb_le);
	  fzj_var->GetObject("cov_arr_prpTbalb_nl", cov_arr_prpTbalb_nl);
	  fzj_var->GetObject("cov_arr_prpTbalg", cov_arr_prpTbalg);
	  fzj_var->GetObject("cov_arr_prpTballq", cov_arr_prpTballq);
	  fzj_var->GetObject("cov_arr_prpTbalud", cov_arr_prpTbalud);
	  fzj_var->GetObject("cov_arr_prpTbals", cov_arr_prpTbals);
	  fzj_var->GetObject("cov_arr_prpTbalc", cov_arr_prpTbalc);

	  TH1D* hzj_pTp   = przj_pTp  ->ProjectionX();
	  //TH1D* hzj_pTpb  = przj_pTpb ->ProjectionX();
	  TH1D* hzj_pTpb_nl  = przj_pTpb_nl ->ProjectionX();
	  TH1D* hzj_pTpb_le  = przj_pTpb_le ->ProjectionX();
	  TH1D* hzj_pTpc  = przj_pTpc ->ProjectionX();
	  TH1D* hzj_pTps  = przj_pTps ->ProjectionX();
	  TH1D* hzj_pTpud = przj_pTpud->ProjectionX();
	  TH1D* hzj_pTpg  = przj_pTpg ->ProjectionX();

	  TH1D* hzj_pTp_var   = przj_pTp_var  ->ProjectionX();
	  //TH1D* hzj_pTpb_var  = przj_pTpb_var ->ProjectionX();
	  TH1D* hzj_pTpb_nl_var  = przj_pTpb_nl_var ->ProjectionX();
	  TH1D* hzj_pTpb_le_var  = przj_pTpb_le_var ->ProjectionX();
	  TH1D* hzj_pTpc_var  = przj_pTpc_var ->ProjectionX();
	  TH1D* hzj_pTps_var  = przj_pTps_var ->ProjectionX();
	  TH1D* hzj_pTpud_var = przj_pTpud_var->ProjectionX();
	  TH1D* hzj_pTpg_var  = przj_pTpg_var ->ProjectionX();

	  TH1D* diff = (TH1D*) hzj_pTp->Clone();
	  //TH1D* diffb = (TH1D*) hzj_pTpb->Clone();
	  TH1D* diffb_nl = (TH1D*) hzj_pTpb_nl->Clone();
	  TH1D* diffb_le = (TH1D*) hzj_pTpb_le->Clone();
	  TH1D* diffc = (TH1D*) hzj_pTpc->Clone();
	  TH1D* diffs = (TH1D*) hzj_pTps->Clone();
	  TH1D* diffud = (TH1D*) hzj_pTpud->Clone();
	  TH1D* diffg = (TH1D*) hzj_pTpg->Clone();

	  diff->Add(hzj_pTp_var,-1);
	  //diffb->Add(hzj_pTpb_var,-1);
	  diffb_nl->Add(hzj_pTpb_nl_var,-1);
	  diffb_le->Add(hzj_pTpb_le_var,-1);
	  diffc->Add(hzj_pTpc_var,-1);
	  diffs->Add(hzj_pTps_var,-1);
	  diffud->Add(hzj_pTpud_var,-1);
	  diffg->Add(hzj_pTpg_var,-1);


	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double val; double var_val; double val_std; double var_val_std;
	
	  for (int i = 1; i < 15; i++){
		val = przj_pTp->GetBinContent(i);
 		var_val = przj_pTp_var->GetBinContent(i);
		val_std = przj_pTp->GetBinError(i);
		var_val_std = przj_pTp_var->GetBinError(i);  
	    error = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbal)[i-1]*val_std*var_val_std)/(val * var_val));

	   /* error = sqrt(przj_MPF->GetBinEffectiveEntries(i)*pow(przj_MPF->GetBinError(i),2)
					+ przj_MPF_var->GetBinEffectiveEntries(i)*pow(przj_MPF_var->GetBinError(i),2)
 					- 2 * (*cov_arr_prMPF)[i]); */

		val = przj_pTpb_le->GetBinContent(i);
 		var_val = przj_pTpb_le_var->GetBinContent(i);
		val_std = przj_pTpb_le->GetBinError(i);
		var_val_std = przj_pTpb_le_var->GetBinError(i);  
	    errorb_le = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbalb_le)[i-1]*val_std*var_val_std)/(val * var_val));

		val = przj_pTpb_nl->GetBinContent(i);
 		var_val = przj_pTpb_nl_var->GetBinContent(i);
		val_std = przj_pTpb_nl->GetBinError(i);
		var_val_std = przj_pTpb_nl_var->GetBinError(i);  
	    errorb_nl = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbalb_nl)[i-1]*val_std*var_val_std)/(val * var_val));

		val = przj_pTpg->GetBinContent(i);
 		var_val = przj_pTpg_var->GetBinContent(i);
		val_std = przj_pTpg->GetBinError(i);
		var_val_std = przj_pTpg_var->GetBinError(i);  
	    errorg = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbalg)[i-1]*val_std*var_val_std)/(val * var_val));

		val = przj_pTpud->GetBinContent(i);
 		var_val = przj_pTpud_var->GetBinContent(i);
		val_std = przj_pTpud->GetBinError(i);
		var_val_std = przj_pTpud_var->GetBinError(i);  
	    errorud = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbalud)[i-1]*val_std*var_val_std)/(val * var_val));

		val = przj_pTps->GetBinContent(i);
 		var_val = przj_pTps_var->GetBinContent(i);
		val_std = przj_pTps->GetBinError(i);
		var_val_std = przj_pTps_var->GetBinError(i);  
	    errors = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbals)[i-1]*val_std*var_val_std)/(val * var_val));

//		cout << "1: " << setprecision(14) << val_std/val*val_std/val + var_val_std/var_val*var_val_std/var_val << endl;
//		cout << "2: " << - 2 * ((*cov_arr_prpTbals)[i-1])/(val * var_val) << endl;

		val = przj_pTpc->GetBinContent(i);
 		var_val = przj_pTpc_var->GetBinContent(i);
		val_std = przj_pTpc->GetBinError(i);
		var_val_std = przj_pTpc_var->GetBinError(i);  
	    errorc = fabs(var_val/val)*sqrt(pow(val_std/val,2) + pow(var_val_std/var_val,2)
			   - 2 * ((*cov_arr_prpTbalc)[i-1]*val_std*var_val_std)/(val * var_val));
//		cout << "error: " << errorc << endl;
//		cout << "1: " << pow(val_std/val,2) + pow(var_val_std/var_val,2) << endl;
//		cout << "2: " << - 2 * ((*cov_arr_prpTbalc)[i-1]*val_std*var_val_std)/(val * var_val) << endl;

//		cout << "old: " << przj_pTpc->GetBinError(i) << endl; 
//		cout << "new: " << errorc << endl;

		cout << "error: " << error << endl;
		cout << "errorb_le: " << errorb_le << endl;
		cout << "errorb_nl: " << errorb_nl << endl;
		cout << "errorg: " << errorg << endl;
		cout << "errorud: " << errorud << endl;
		cout << "error:s " << errors << endl;
		cout << "error:c " << errorc << endl;
		cout << "" << endl;

		diff->SetBinError(i,error);
		//diffb->SetBinError(i,errorb);
		diffb_le->SetBinError(i,errorb_le);
		diffb_nl->SetBinError(i,errorb_nl);
		diffg->SetBinError(i,errorg);
		diffud->SetBinError(i,errorud);
		diffs->SetBinError(i,errors);
		diffc->SetBinError(i,errorc);

		if (no_nan) {
			if (error != error) {
				diff->SetBinError(i,0.0);
			}
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,0.0);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,0.0);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,0.0);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,0.0);
			}
			if (errors != errors) {
				diffs->SetBinError(i,0.0);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,0.0);
			}
		}
	  }
		cout << "" << endl;
	  diff->Scale(100.0);
	  //diffb->Add(hzj_MPFb_var,-1);
	  diffb_nl->Scale(100.0);
	  diffb_le->Scale(100.0);
	  diffc->Scale(100.0);
	  diffs->Scale(100.0);
	  diffud->Scale(100.0);
	  diffg->Scale(100.0); 

	  //Canvas
	  TCanvas* canv_pTp = new TCanvas("pTp","",500,400);
	  canv_pTp->SetLeftMargin(0.13);
	  canv_pTp->SetBottomMargin(0.13);
	  canv_pTp->SetLogx();

	  //Legend
//	  TLegend* lz_pTp = new TLegend(0.62,0.70,0.89,0.89);
	  TLegend* lz_pTp = new TLegend(0.37,0.17,0.64,0.39);
	  lz_pTp->SetBorderSize(0);

	  diff  ->SetMarkerStyle(kOpenCircle);      diff  ->SetMarkerColor(kBlack);
	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  diff  ->SetLineColor(kBlack);              
	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  //Legend
	  //TLegend* lz_pTp = new TLegend(0.55,0.17,0.75,0.42);
	  lz_pTp->SetBorderSize(0);
	  lz_pTp->AddEntry(diff,   "All",   "p");
	  //lz_pTp->AddEntry(diffb,  "b",     "p");
	  lz_pTp->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_pTp->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_pTp->AddEntry(diffc,  "c",     "p");
	  lz_pTp->AddEntry(diffs,  "s",     "p");
	  lz_pTp->AddEntry(diffud, "ud",    "p");
	  lz_pTp->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diff->SetStats(0);
	  diff->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

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
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("PSAME");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_pTp->Draw();

	  if (y_fixed) {
	    diff->SetMaximum(0.6);
	    diff->SetMinimum(-0.4);
 	  }

	  diff->SetMaximum(0.9);
	  diff->SetMinimum(-0.9);

	  //Save plot
	  canv_pTp->Print("new_cov_plots/1M_diff_pTbal.pdf"); delete canv_pTp;
  } 

	 if (F_plot) {
	//Ratio plot

		//open and create histograms for normal run
//		TFile* fzj = TFile::Open("output_ROOT_files/CMSJES_P8_Zjet_100000.root");
		TFile* fzj = TFile::Open(OpenName.c_str());
		TProfile *przj_F=0; 
		//TProfile *przj_Fb=0;
		TProfile *przj_Fb_nl=0;
		TProfile *przj_Fb_le=0; 
		TProfile *przj_Fc=0; 
		TProfile *przj_Fs=0; 
		TProfile *przj_Fud=0; 
		TProfile *przj_Fg=0; 

		fzj->GetObject("prRjet"   ,przj_F  );
		//fzj->GetObject("prRjetb"  ,przj_Fb );
		fzj->GetObject("prRjetb_nl"  ,przj_Fb_nl);
		fzj->GetObject("prRjetb_le"  ,przj_Fb_le);
		fzj->GetObject("prRjetc"  ,przj_Fc);
		fzj->GetObject("prRjets"  ,przj_Fs);
		fzj->GetObject("prRjetud"  ,przj_Fud);
		fzj->GetObject("prRjetg"  ,przj_Fg);

		TH1D* hzj_F   = przj_F->ProjectionX();
		//TH1D* hzj_Fb  = przj_Fb->ProjectionX();
		TH1D* hzj_Fb_nl  = przj_Fb_nl->ProjectionX();
		TH1D* hzj_Fb_le  = przj_Fb_le->ProjectionX();
		TH1D* hzj_Fc  = przj_Fc->ProjectionX();
		TH1D* hzj_Fs  = przj_Fs->ProjectionX();
		TH1D* hzj_Fud  = przj_Fud->ProjectionX();
		TH1D* hzj_Fg  = przj_Fg->ProjectionX();
		
//		cout << "tot: " << hzj_F->GetBinContent(1) << endl;
//		cout << "sum: " << hzj_Fb_nl->GetBinContent(1)+hzj_Fb_le->GetBinContent(1)+hzj_Fc->GetBinContent(1)+hzj_Fs->GetBinContent(1)+hzj_Fud->GetBinContent(1)+hzj_Fg->GetBinContent(1) << endl;
		

		//hzj_Fb->Divide(hzj_F);
		hzj_Fb_nl->Divide(hzj_F);
		hzj_Fb_le->Divide(hzj_F);
		hzj_Fc->Divide(hzj_F);
		hzj_Fs->Divide(hzj_F);
		hzj_Fud->Divide(hzj_F);
		hzj_Fg->Divide(hzj_F);

		//open and create histograms for B-hadron weighted run
//		TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_100000.root");
//		TFile* fzj_var = TFile::Open("output_ROOT_files/var_CMSJES_P8_Zjet_5000000.root");
		TFile* fzj_var = TFile::Open(var_OpenName.c_str());
		TProfile *przj_F_var=0; 
		//TProfile *przj_Fb_var=0;
		TProfile *przj_Fb_nl_var=0;
		TProfile *przj_Fb_le_var=0;
		TProfile *przj_Fc_var=0; 
		TProfile *przj_Fs_var=0; 
		TProfile *przj_Fud_var=0; 
		TProfile *przj_Fg_var=0; 

		fzj_var->GetObject("prRjet"   ,przj_F_var  );
		//fzj_var->GetObject("prRjetb"  ,przj_Fb_var);
		fzj_var->GetObject("prRjetb_nl"  ,przj_Fb_nl_var);
		fzj_var->GetObject("prRjetb_le"  ,przj_Fb_le_var);
		fzj_var->GetObject("prRjetc"  ,przj_Fc_var);
		fzj_var->GetObject("prRjets"  ,przj_Fs_var);
		fzj_var->GetObject("prRjetud"  ,przj_Fud_var);
		fzj_var->GetObject("prRjetg"  ,przj_Fg_var);

		vector<Double_t>* cov_arr_prRjet = new vector<Double_t>();
		//vector<Double_t>* cov_arr_prMPFb = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetb_le = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetb_nl = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetg = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetlq = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetud = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjets = new vector<Double_t>();
		vector<Double_t>* cov_arr_prRjetc = new vector<Double_t>();

		fzj_var->GetObject("cov_arr_prRjet", cov_arr_prRjet);
		//fzj_var->GetObject("cov_arr_prMPFb", cov_arr_prMPFb);
		fzj_var->GetObject("cov_arr_prRjetb_le", cov_arr_prRjetb_le);
		fzj_var->GetObject("cov_arr_prRjetb_nl", cov_arr_prRjetb_nl);
		fzj_var->GetObject("cov_arr_prRjetg", cov_arr_prRjetg);
		fzj_var->GetObject("cov_arr_prRjetlq", cov_arr_prRjetlq);
		fzj_var->GetObject("cov_arr_prRjetud", cov_arr_prRjetud);
		fzj_var->GetObject("cov_arr_prRjets", cov_arr_prRjets);
		fzj_var->GetObject("cov_arr_prRjetc", cov_arr_prRjetc);

		TH1D* hzj_F_var   = przj_F_var->ProjectionX();
		//TH1D* hzj_Fb_var  = przj_Fb_var->ProjectionX();
		TH1D* hzj_Fb_nl_var  = przj_Fb_nl_var->ProjectionX();
		TH1D* hzj_Fb_le_var  = przj_Fb_le_var->ProjectionX();
		TH1D* hzj_Fc_var  = przj_Fc_var->ProjectionX();
		TH1D* hzj_Fs_var  = przj_Fs_var->ProjectionX();
		TH1D* hzj_Fud_var  = przj_Fud_var->ProjectionX();
		TH1D* hzj_Fg_var  = przj_Fg_var->ProjectionX();

		//hzj_Fb_var->Divide(hzj_F_var);
		hzj_Fb_nl_var->Divide(hzj_F_var);
		hzj_Fb_le_var->Divide(hzj_F_var);
		hzj_Fc_var->Divide(hzj_F_var);
		hzj_Fs_var->Divide(hzj_F_var);
		hzj_Fud_var->Divide(hzj_F_var);
		hzj_Fg_var->Divide(hzj_F_var);

		TH1D *diffb_nl = (TH1D*) hzj_Fb_nl->Clone();
		TH1D *diffb_le = (TH1D*) hzj_Fb_le->Clone();
		TH1D *diffc = (TH1D*) hzj_Fc->Clone();
		TH1D *diffs = (TH1D*) hzj_Fs->Clone();
		TH1D *diffud = (TH1D*) hzj_Fud->Clone();
		TH1D *diffg = (TH1D*) hzj_Fg->Clone();

		diffb_nl->Add(hzj_Fb_nl_var,-1);
		diffb_le->Add(hzj_Fb_le_var,-1);
		diffc->Add(hzj_Fc_var,-1);
		diffs->Add(hzj_Fs_var,-1);
		diffud->Add(hzj_Fud_var,-1);
		diffg->Add(hzj_Fg_var,-1);

	  double error; double errorb; double errorb_le; double errorb_nl; 
	  double errorg; double errorud; double errors; double errorc;
	  double R; double var_R; double R_std; double var_R_std;
	  double R_all; double var_R_all; double R_all_std; double var_R_all_std;
	
	  for (int i = 1; i < 15; i++){
		R_all = przj_F->GetBinContent(i);
		R_all_std = przj_F->GetBinError(i);
		var_R_all = przj_F_var->GetBinContent(i);
		var_R_all_std = przj_F_var->GetBinError(i);


		R = przj_Fb_nl->GetBinContent(i);
		R_std = przj_Fb_nl->GetBinError(i);
		var_R = przj_Fb_nl_var->GetBinContent(i); 
		var_R_std = przj_Fb_nl_var->GetBinError(i);  
	    errorb_nl = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjetb_nl)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));

		R = przj_Fb_le->GetBinContent(i);
		R_std = przj_Fb_le->GetBinError(i);
		var_R = przj_Fb_le_var->GetBinContent(i); 
		var_R_std = przj_Fb_le_var->GetBinError(i);  
	    errorb_le = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjetb_le)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));

		R = przj_Fg->GetBinContent(i);
		R_std = przj_Fg->GetBinError(i);
		var_R = przj_Fg_var->GetBinContent(i); 
		var_R_std = przj_Fg_var->GetBinError(i);  
	    errorg = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjetg)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));

		R = przj_Fud->GetBinContent(i);
		R_std = przj_Fud->GetBinError(i);
		var_R = przj_Fud_var->GetBinContent(i); 
		var_R_std = przj_Fud_var->GetBinError(i);  
	    errorud = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjetud)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));

		R = przj_Fs->GetBinContent(i);
		R_std = przj_Fs->GetBinError(i);
		var_R = przj_Fs_var->GetBinContent(i); 
		var_R_std = przj_Fs_var->GetBinError(i);  
	    errors = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjets)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));

		R = przj_Fc->GetBinContent(i);
		R_std = przj_Fc->GetBinError(i);
		var_R = przj_Fc_var->GetBinContent(i); 
		var_R_std = przj_Fc_var->GetBinError(i);  
	    errorc = fabs(((var_R)/(var_R_all))/((R)/(R_all)))*sqrt(pow(R_std/R,2) + pow(var_R_std/var_R,2)
			   + pow(R_all_std/R_all,2) + pow(var_R_all_std/var_R_all,2) 
			   - 2 * ((*cov_arr_prRjetc)[i-1]*R_std*var_R_std)/(R * var_R) 
			   - 2 * ((*cov_arr_prRjet)[i-1]*R_all_std*var_R_all_std)/(R_all * var_R_all));


//		cout << "old: " << przj_Fb_nl_var->GetBinError(i) << endl;
//		cout << "new: " << errorb_nl << endl;

//		cout << "errorb_le: " << errorb_le << endl;
//		cout << "errorb_nl: " << errorb_nl << endl;
//		cout << "errorg: " << errorg << endl;
//		cout << "errorud: " << errorud << endl;
//		cout << "error:s " << errors << endl;
//		cout << "error:c " << errorc << endl;
//		cout << "" << endl;


		if (no_nan) {
			//diffb->SetBinError(i,errorb);
			if (errorb_le != errorb_le) {
				diffb_le->SetBinError(i,errorb_le);
			}
			if (errorb_nl != errorb_nl) {
				diffb_nl->SetBinError(i,errorb_nl);
			}
			if (errorg != errorg) {
				diffg->SetBinError(i,errorg);
			}	
			if (errorud != errorud) {
				diffud->SetBinError(i,errorud);
			}
			if (errors != errors) {
				diffs->SetBinError(i,errors);
			}
			if (errorc != errorc) {
				diffc->SetBinError(i,errorc);
			}
		} else {
			//diffb->SetBinError(i,errorb);
			diffb_le->SetBinError(i,errorb_le);
			diffb_nl->SetBinError(i,errorb_nl);
			diffg->SetBinError(i,errorg);
			diffud->SetBinError(i,errorud);
			diffs->SetBinError(i,errors);
			diffc->SetBinError(i,errorc);
		}

//		cout << (*cov_arr_prRjetb_le)[i-1]<< endl;
	  }

		//cout << diffc->GetBinError(14) << endl;
		diffb_nl->Scale(100);
		diffb_le->Scale(100);
		diffc->Scale(100);
		diffs->Scale(100);
		diffud->Scale(100);
		diffg->Scale(100);

	  //Canvas
	  TCanvas* canv_F = new TCanvas("pTp","",500,400);
	  canv_F->SetLeftMargin(0.13);
	  canv_F->SetBottomMargin(0.13);
	  canv_F->SetLogx();

	  //Legend
	  TLegend* lz_F = new TLegend(0.62,0.70,0.89,0.89);
	  lz_F->SetBorderSize(0);

	  //diffb ->SetMarkerStyle(kFullCircle);      diffb ->SetMarkerColor(kRed+1);
	  diffb_nl ->SetMarkerStyle(kFullCircle);      diffb_nl ->SetMarkerColor(kRed+1);
	  diffb_le ->SetMarkerStyle(kOpenCircle);      diffb_le ->SetMarkerColor(kRed+1);
	  diffc ->SetMarkerStyle(kFullSquare);      diffc ->SetMarkerColor(kBlue+1);
	  diffs->SetMarkerStyle(kFullDiamond);     diffs->SetMarkerColor(kMagenta+2);
	  diffud->SetMarkerStyle(kFullTriangleUp);   diffud->SetMarkerColor(kOrange+1);
	  diffg->SetMarkerStyle(kFullTriangleDown); diffg->SetMarkerColor(kGreen+2);

	  //diffb ->SetLineColor(kRed+1);
	  diffb_nl ->SetLineColor(kRed+1);
	  diffb_le ->SetLineColor(kRed+1);
	  diffc ->SetLineColor(kBlue+1);             
	  diffs->SetLineColor(kMagenta+2);
	  diffud ->SetLineColor(kOrange+1);            
	  diffg ->SetLineColor(kGreen+2);

	  //Legend
	  //TLegend* lz_pTp = new TLegend(0.55,0.17,0.75,0.42);
	  lz_F->SetBorderSize(0);
	  //lz_pTp->AddEntry(diffb,  "b",     "p");
	  lz_F->AddEntry(diffb_nl,  "b (non-semileptonic)",     "p");
	  lz_F->AddEntry(diffb_le,  "b (semileptonic)",     "p");
	  lz_F->AddEntry(diffc,  "c",     "p");
	  lz_F->AddEntry(diffs,  "s",     "p");
	  lz_F->AddEntry(diffud, "ud",    "p");
	  lz_F->AddEntry(diffg,  "gluon", "p");

	  //Title and axis setup
	  diffb_nl->SetStats(0);
	  diffb_nl->SetTitle("");
	  //diff->SetAxisRange(-0.2,0.2,"Y"); //Vertical axis limits

	  diffb_nl->GetXaxis()->SetMoreLogLabels();
	  diffb_nl->GetXaxis()->SetNoExponent();
	  diffb_nl->GetYaxis()->SetTitleOffset(1.1);
	  diffb_nl->GetXaxis()->SetTitleOffset(1.1);
	  diffb_nl->GetXaxis()->SetTitle("p_{T,jet}^{gen} (GeV)");
	  diffb_nl->GetYaxis()->SetTitle("F - F_{scaled} (%)");
	  diffb_nl->GetYaxis()->SetTitleSize(0.05);
	  diffb_nl->GetXaxis()->SetTitleSize(0.05);
	  gPad->SetTickx();   gPad->SetTicky();

	  //Plot
	  //diffb->Draw("PSAME");
	  diffb_nl->Draw("P");
	  diffb_le->Draw("PSAME");
	  diffc->Draw("PSAME");
	  diffs->Draw("PSAME");
	  diffud->Draw("PSAME");
	  diffg->Draw("PSAME");
	  lz_F->Draw();

	  if (y_fixed) {
	    diffb_nl->SetMaximum(0.6);
	    diffb_nl->SetMinimum(-0.4);
	  }

	  canv_F->Print("new_cov_plots/1M_diff_F.pdf");

	}
}
