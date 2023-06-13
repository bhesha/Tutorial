#ifndef THROWN_BRANCH_H_06_13
#define THROWN_BRANCH_H_06_13
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include <iostream>

//Declaration of leaves types
  Double_t        accidweight;
   Double_t        vertex_cut;
   Double_t        Proton_kin_vertex;
   Double_t        MM2;
   Double_t        ME;
   Double_t        Mp;
   Double_t        Coplaniraty;
   Double_t        Final_Energy_kin;
   Double_t        Final_pz_kin;
   Double_t        pMinus_Meas;
   Double_t        Minus_t_kin;
   Double_t        Minus_u_kin;
   Double_t        PiPlus_Theta;
   Double_t        PiMinus_Theta;
   Double_t        Proton_Theta;
   Double_t        beam_energy;
   Double_t        mass_2pi_kin;
   Double_t        mass_PipProt;
   Double_t        mass_PimProt;
   Double_t        event_num;
   Double_t        run_num;

    TFile* get_file(TString file_name) {
    TFile* file = new TFile(file_name, "read");
    if (!file || file->IsZombie()) {
        std::cout << "Error opening file: " << file_name << std::endl;
        return nullptr;
    }
    return file;
}
    TTree *get_tree(TFile* file, TString tree_name){
     if (!file) {
        std::cout << "Invalid file pointer." << std::endl;
        return nullptr;
    }
    TTree*   rho0_Tree_MC = dynamic_cast<TTree*>(file->Get(tree_name));
    if (!  rho0_Tree_MC) {
        std::cout << "Error accessing TTree from file: " << std::endl;
        file->Close();
        return nullptr;
    }
       
   rho0_Tree_MC->SetBranchAddress("accidweight",&accidweight);
   rho0_Tree_MC->SetBranchAddress("vertex_cut",&vertex_cut);
   rho0_Tree_MC->SetBranchAddress("Proton_kin_vertex",&Proton_kin_vertex);
   rho0_Tree_MC->SetBranchAddress("MM2",&MM2);
   rho0_Tree_MC->SetBranchAddress("ME",&ME);
   rho0_Tree_MC->SetBranchAddress("Mp",&Mp);
   rho0_Tree_MC->SetBranchAddress("Coplaniraty",&Coplaniraty);
   rho0_Tree_MC->SetBranchAddress("Final_Energy_kin",&Final_Energy_kin);
   rho0_Tree_MC->SetBranchAddress("Final_pz_kin",&Final_pz_kin);
   rho0_Tree_MC->SetBranchAddress("pMinus_Meas",&pMinus_Meas);
   rho0_Tree_MC->SetBranchAddress("Minus_t_kin",&Minus_t_kin);
   rho0_Tree_MC->SetBranchAddress("Minus_u_kin",&Minus_u_kin);
   rho0_Tree_MC->SetBranchAddress("PiPlus_Theta",&PiPlus_Theta);
   rho0_Tree_MC->SetBranchAddress("PiMinus_Theta",&PiMinus_Theta);
   rho0_Tree_MC->SetBranchAddress("Proton_Theta",&Proton_Theta);
   rho0_Tree_MC->SetBranchAddress("beam_energy",&beam_energy);
   rho0_Tree_MC->SetBranchAddress("mass_2pi_kin",&mass_2pi_kin);
   rho0_Tree_MC->SetBranchAddress("mass_PipProt",&mass_PipProt);
   rho0_Tree_MC->SetBranchAddress("mass_PimProt",&mass_PimProt);
   rho0_Tree_MC->SetBranchAddress("event_num",&event_num);
   rho0_Tree_MC->SetBranchAddress("run_num",&run_num);


  rho0_Tree_MC->SetBranchStatus("*",0);
  rho0_Tree_MC->SetBranchStatus("Minus_t_kin", 1);
  rho0_Tree_MC->SetBranchStatus("mass_2pi_kin", 1);
  rho0_Tree_MC->SetBranchStatus("accidweight", 1);
  rho0_Tree_MC->SetBranchStatus("Coplaniraty_meas", 1);
 // tree->SetBranchStatus("Final_Energy_kin", 1);
 // tree->SetBranchStatus("pMinus_Meas", 1);
 // tree->SetBranchStatus("proton_PIDFOM", 1);
 // tree->SetBranchStatus("PiPlus_PIDFOM", 1);
 // tree->SetBranchStatus("PiMInus_PIDFOM", 1);
  rho0_Tree_MC->SetBranchStatus("beam_energy", 1);

    
    return rho0_Tree_MC;
}

#endif

