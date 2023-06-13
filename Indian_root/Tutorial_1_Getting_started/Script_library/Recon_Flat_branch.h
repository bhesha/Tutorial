#ifndef RECON_BRANCH_H_06_13
#define RECON_BRANCH_H_06_13
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include <iostream>

//Declaration of leaves types
   Double_t        accidweight;
   Double_t        tagger;
   Double_t        extraE;
   Double_t        unused_track;
   Double_t        unused_shower;
   Double_t        kinfit_CL;
   Double_t        Proton_dEdx_CDC;
   Double_t        PiPlus_dEdx_CDC;
   Double_t        Proton_meas_vertex;
   Double_t        Proton_kin_vertex;
   Double_t        MM2;
   Double_t        ME;
   Double_t        Mp;
   Double_t        Coplaniraty_meas;
   Double_t        Coplaniraty_kin;
   Double_t        Final_Energy_kin;
   Double_t        Final_Energy_meas;
   Double_t        Final_pz_kin;
   Double_t        Final_pz_M;
   Double_t        pMinus_Meas;
   Double_t        pMinus_kin;
   Double_t        S_kin;
   Double_t        Minus_t_kin;
   Double_t        Minus_u_kin;
   Double_t        Minus_t_meas;
   Double_t        Minus_u_meas;
   Double_t        PiPlus_kin_Theta;
   Double_t        PiMinus_kin_Theta;
   Double_t        Proton_kin_Theta;
   Double_t        PiPlus_meas_Theta;
   Double_t        PiMinus_meas_Theta;
   Double_t        Proton_meas_Theta;
   Double_t        beam_energy;
   Double_t        mass_2pi_meas;
   Double_t        mass_2pi_kin;
   Double_t        mass_PipProt;
   Double_t        mass_PipProt_Meas;
   Double_t        mass_PimProt;
   Double_t        mass_PimProt_meas;
   Double_t        Momentum_Piplus_meas;
   Double_t        Momentum_PiMinus_meas;
   Double_t        Momentum_Proton_meas;
   Double_t        Momentum_Piplus_kin;
   Double_t        Momentum_PiMinus_kin;
   Double_t        Momentum_Proton_kin;
   Double_t        event_num;
   Double_t        run_num;
   Double_t        proton_PIDFOM;
   Double_t        PiPlus_PIDFOM;
   Double_t        PiMInus_PIDFOM;//Load the ROOT-file, get the ROOT-tree and set the variables:

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
    TTree*   rho0_Tree = dynamic_cast<TTree*>(file->Get(tree_name));
    if (!  rho0_Tree) {
        std::cout << "Error accessing TTree from file: " << std::endl;
        file->Close();
        return nullptr;
    }
       
  rho0_Tree->SetBranchAddress("accidweight",&accidweight);
   rho0_Tree->SetBranchAddress("tagger",&tagger);
   rho0_Tree->SetBranchAddress("extraE",&extraE);
   rho0_Tree->SetBranchAddress("unused_track",&unused_track);
   rho0_Tree->SetBranchAddress("unused_shower",&unused_shower);
   rho0_Tree->SetBranchAddress("kinfit_CL",&kinfit_CL);
   rho0_Tree->SetBranchAddress("Proton_dEdx_CDC",&Proton_dEdx_CDC);
   rho0_Tree->SetBranchAddress("PiPlus_dEdx_CDC",&PiPlus_dEdx_CDC);
   rho0_Tree->SetBranchAddress("Proton_meas_vertex",&Proton_meas_vertex);
   rho0_Tree->SetBranchAddress("Proton_kin_vertex",&Proton_kin_vertex);
   rho0_Tree->SetBranchAddress("MM2",&MM2);
   rho0_Tree->SetBranchAddress("ME",&ME);
   rho0_Tree->SetBranchAddress("Mp",&Mp);
   rho0_Tree->SetBranchAddress("Coplaniraty_meas",&Coplaniraty_meas);
   rho0_Tree->SetBranchAddress("Coplaniraty_kin",&Coplaniraty_kin);
   rho0_Tree->SetBranchAddress("Final_Energy_kin",&Final_Energy_kin);
   rho0_Tree->SetBranchAddress("Final_Energy_meas",&Final_Energy_meas);
   rho0_Tree->SetBranchAddress("Final_pz_kin",&Final_pz_kin);
   rho0_Tree->SetBranchAddress("Final_pz_M",&Final_pz_M);
   rho0_Tree->SetBranchAddress("pMinus_Meas",&pMinus_Meas);
   rho0_Tree->SetBranchAddress("pMinus_kin",&pMinus_kin);
   rho0_Tree->SetBranchAddress("S_kin",&S_kin);
   rho0_Tree->SetBranchAddress("Minus_t_kin",&Minus_t_kin);
   rho0_Tree->SetBranchAddress("Minus_u_kin",&Minus_u_kin);
   rho0_Tree->SetBranchAddress("Minus_t_meas",&Minus_t_meas);
   rho0_Tree->SetBranchAddress("Minus_u_meas",&Minus_u_meas);
   rho0_Tree->SetBranchAddress("PiPlus_kin_Theta",&PiPlus_kin_Theta);
   rho0_Tree->SetBranchAddress("PiMinus_kin_Theta",&PiMinus_kin_Theta);
   rho0_Tree->SetBranchAddress("Proton_kin_Theta",&Proton_kin_Theta);
   rho0_Tree->SetBranchAddress("PiPlus_meas_Theta",&PiPlus_meas_Theta);
   rho0_Tree->SetBranchAddress("PiMinus_meas_Theta",&PiMinus_meas_Theta);
   rho0_Tree->SetBranchAddress("Proton_meas_Theta",&Proton_meas_Theta);
   rho0_Tree->SetBranchAddress("beam_energy",&beam_energy);
   rho0_Tree->SetBranchAddress("mass_2pi_meas",&mass_2pi_meas);
   rho0_Tree->SetBranchAddress("mass_2pi_kin",&mass_2pi_kin);
   rho0_Tree->SetBranchAddress("mass_PipProt",&mass_PipProt);
   rho0_Tree->SetBranchAddress("mass_PipProt_Meas",&mass_PipProt_Meas);
   rho0_Tree->SetBranchAddress("mass_PimProt",&mass_PimProt);
   rho0_Tree->SetBranchAddress("mass_PimProt_meas",&mass_PimProt_meas);
   rho0_Tree->SetBranchAddress("Momentum_Piplus_meas",&Momentum_Piplus_meas);
   rho0_Tree->SetBranchAddress("Momentum_PiMinus_meas",&Momentum_PiMinus_meas);
   rho0_Tree->SetBranchAddress("Momentum_Proton_meas",&Momentum_Proton_meas);
   rho0_Tree->SetBranchAddress("Momentum_Piplus_kin",&Momentum_Piplus_kin);
   rho0_Tree->SetBranchAddress("Momentum_PiMinus_kin",&Momentum_PiMinus_kin);
   rho0_Tree->SetBranchAddress("Momentum_Proton_kin",&Momentum_Proton_kin);
   rho0_Tree->SetBranchAddress("event_num",&event_num);
   rho0_Tree->SetBranchAddress("run_num",&run_num);
   rho0_Tree->SetBranchAddress("proton_PIDFOM",&proton_PIDFOM);
   rho0_Tree->SetBranchAddress("PiPlus_PIDFOM",&PiPlus_PIDFOM);
   rho0_Tree->SetBranchAddress("PiMInus_PIDFOM",&PiMInus_PIDFOM);

  rho0_Tree->SetBranchStatus("*",0);
  rho0_Tree->SetBranchStatus("Minus_t_kin", 1);
  rho0_Tree->SetBranchStatus("mass_2pi_kin", 1);
  rho0_Tree->SetBranchStatus("accidweight", 1);
  //tree->SetBranchStatus("kinfit_CL", 1);
  rho0_Tree->SetBranchStatus("Coplaniraty_meas", 1);
 // tree->SetBranchStatus("Final_Energy_kin", 1);
 // tree->SetBranchStatus("pMinus_Meas", 1);
 // tree->SetBranchStatus("proton_PIDFOM", 1);
 // tree->SetBranchStatus("PiPlus_PIDFOM", 1);
 // tree->SetBranchStatus("PiMInus_PIDFOM", 1);
  rho0_Tree->SetBranchStatus("beam_energy", 1);

    
    return rho0_Tree;
}
   
#endif

