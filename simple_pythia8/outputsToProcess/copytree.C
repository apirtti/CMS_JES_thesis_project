// Load the library at macro parsing time: we need this to use its content in the code
//R__LOAD_LIBRARY($ROOTSYS/test/libEvent.so)
void copytree()
{
   //TString dir = "$ROOTSYS/test/Event.root";
   //gSystem->ExpandPathName(dir);
   //const auto filename = gSystem->AccessPathName(dir) ? "./Event.root" : "$ROOTSYS/test/Event.root";
   TFile oldfile("pjets_pythia8_dijet_5000000.root");
   TTree *oldtree;
   oldfile.GetObject("Pythia8Jets", oldtree);
   // Deactivate all branches
   oldtree->SetBranchStatus("*", 0);
   // Activate only four of them
   for (auto activeBranchName : {"jet_pt", "jet_eta", "jet_phi", "jet_e", "weight"})
      oldtree->SetBranchStatus(activeBranchName, 1);
   // Create a new file + a clone of old tree in new file
   TFile newfile("pythia8_dijet_5000000.root", "recreate");
   auto newtree = oldtree->CloneTree();
   newtree->Print();
   newfile.Write();
}
