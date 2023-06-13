#include "/home/dutta/Script_library/Recon_Flat_branch.h"
#include "/home/dutta/Script_library/User_fit.h"
void Sample_script() {
    TString data_dir = "/home/dutta/Documents/SRC_CT_Rho_Analysis/Ifarm_root_file/Flat_root_file/";
    TString root_file_name = "Reconst_flat_Deuterium_neutron.root ";  
    TString root_tree_name = "rho0_Tree";    
    TFile* file = get_file(data_dir + root_file_name);
    if (!file || file->IsZombie()) {
        std::cout << "Unable to retrieve TFile." << std::endl;
        return 1;
    }
    TTree *tree = get_tree(file,root_tree_name);
    if (!tree) {
        std::cout << "Unable to retrieve TTree.  " << root_tree_name<< std::endl;
        return 1 ;
    }    
   TH1D *dHist_2Pi_12 =  new TH1D("2Pi_tu_12", ";#pi^{+}#pi^{-} Invariant Mass (GeV/c^{2})(Kinfit)(flat); " , 400 , 0 ,4);     
   TH1D *dHist_2Pi_24 =  new TH1D("2Pi_tu_24", ";#pi^{+}#pi^{-} Invariant Mass (GeV/c^{2})(Kinfit)(flat); " , 400 , 0 ,4);     
   TH1D *dHist_coplan =  new TH1D("coplan", ";coplanitary; " , 400 , 150 ,110);  
   TH1D *dHist_beam =  new TH1D("beam", ";beam; " , 400 , 6 ,12);      
   TH1D *adHist_2Pi_12 =  new TH1D("a2Pi_tu_12", ";#pi^{+}#pi^{-} Invariant Mass (negate); " , 400 , 0 ,4);     
   //TH1D *dHist_2Pi_24 =  new TH1D("2Pi_tu_24", ";#pi^{+}#pi^{-} Invariant Mass (GeV/c^{2})(Kinfit)(flat); " , 400 , 0 ,4);     
   TH1D *adHist_coplan =  new TH1D("acoplan", ";coplanitary(negate); " , 400 , 150 ,110);  
   TH1D *adHist_beam =  new TH1D("abeam", ";beam(negate); " , 400 , 6 ,12);      
   TH2D * dHist_2D = new TH2D("h_2D",";mass;coplan",400,0,4,400,50,300);
   TH2D * adHist_2D = new TH2D("ah_2D",";mass;coplan",400,0,4,400,50,300);
  
         
      Long64_t numEntries =   tree->GetEntries();
     for (Long64_t i = 0; i < numEntries; ++i) {
        tree->GetEntry(i);
        // if ((beam_energy < 8.2) || (beam_energy > 8.7))
         //  continue;
        Bool_t t_1_15 = ((fabs(Minus_t_kin) >= 5) && (fabs(Minus_t_kin) < 9));
        Bool_t Coplaniraty = ((Coplaniraty_meas >=165) && (Coplaniraty_meas < 195));

         // tree->GetEntry(i);
        Bool_t t_23 = ((fabs(Minus_t_kin) >= 2) && (fabs(Minus_t_kin) < 3));
      //  Bool_t t_within_range = (Minus_t_kin >= t_min && Minus_t_kin <t_max);
         // tree->GetEntry(i);
              if (t_1_15 )
              {                 
                 dHist_2Pi_12->Fill(mass_2pi_kin,accidweight); 
                 dHist_coplan->Fill(Coplaniraty_meas,accidweight);    
                 dHist_beam->Fill(beam_energy,accidweight); 
                 dHist_2D->Fill(mass_2pi_kin,Coplaniraty_meas,accidweight);          
              }

               if (t_1_15 && !Coplaniraty)
              {                 
                 adHist_2Pi_12->Fill(mass_2pi_kin,accidweight); 
                 adHist_coplan->Fill(Coplaniraty_meas,accidweight);    
                 adHist_beam->Fill(beam_energy,accidweight); 
                    adHist_2D->Fill(mass_2pi_kin,Coplaniraty_meas,accidweight);    
              }
                      
    }

    TCanvas *c1 = new TCanvas("c1", "c1a", 600, 800);
    //c1->SetFillColor(42);
    c1->Divide(3, 2);
    c1->cd(1);
   dHist_2Pi_12->Draw("hist");
    c1->cd(2);
    dHist_coplan->Draw("hist");
    c1->cd(3);
   dHist_beam->Draw("hist");
    c1->cd(4);
   adHist_2Pi_12->Draw("hist");
    c1->cd(5);
    adHist_coplan->Draw("hist");
    c1->cd(6);
    adHist_beam->Draw("hist");

 TCanvas *c2 = new TCanvas("c2", "c2a", 600, 800);
 c2->Divide(1, 3);
 c2->cd(1);
 dHist_2Pi_12->Draw("hist");
 adHist_2Pi_12->Draw("same");
 adHist_2Pi_12->SetLineColor(kRed);
   //  c1->Print("test.pdf");
 c2->cd(2);
 dHist_2D->Draw("colz");
  c2->cd(3);
 adHist_2D->Draw("colz");
 TCanvas *c3 = new TCanvas("c3", "c3a",600,400);
 dHist_2Pi_12->Draw(); 
 TF1 *func1 = new TF1("func1",User_fit::mybw_relative,0,4,3);
 //func1->SetParameter(0, dHist_coplan->GetBinContent(dHist_coplan->GetMaximumBin()));
 func1->SetParameter(0,  88.82 );
        func1->SetParameter(1, 0.1491); 
        func1->SetParameter(2, 0.77526); 
 dHist_2Pi_12->Fit("func1","R ");
}
  