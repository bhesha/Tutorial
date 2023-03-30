#include "TF1.h"
#include "TH1.h"
#include "TMath.h"
#include<iostream>          // For printing messages to the terminal
#include<string>            // For strings
#include<TH1D.h>            // ROOT histograms
#include<TFile.h>           // ROOT files
#include<TCanvas.h>         // ROOT canvas for plotting
#include<TPad.h>            // ROOT pads for advanced plotting
#include<TLegend.h>         // ROOT legends for plots
#include<TLatex.h>          // ROOT latex for flexible text drawing
#include<TLine.h>  
void Efficiency_test2(){
//gStyle->SetOptFit(11111111);      //This includes both Xisquare fit
TString Thrown= "calc_effic";   
TFile *file_thrown = new TFile(Thrown +".root","read");  
if (!file_thrown->IsOpen()) 
    {  cout << "Error: could not open file " << (Thrown + ".root").Data() << endl;
      return;
    }  
  cout << "Opening root file: " << (Thrown+".root").Data() << endl;
  TH1F *t_thrown_above_1 = (TH1F*)file_thrown->Get("thrown_t_above_tu_1"); 
  TH1F *t_thrown_above_1_constr = (TH1F*)file_thrown->Get("thrown_t_Range"); 
  TH1F *t_accepted_above_1 = (TH1F*)file_thrown->Get("Observed_t_above_tu_1"); 
  TH1F *t_accepted_above_1_constr = (TH1F*)file_thrown->Get("Observed_t_Range"); 
  t_thrown_above_1->SetMarkerStyle(33);
  t_accepted_above_1->SetMarkerStyle(33);
  t_thrown_above_1->Sumw2();
  t_accepted_above_1->Sumw2();
  t_thrown_above_1_constr->Sumw2();
  t_accepted_above_1_constr->Sumw2();

  t_thrown_above_1_constr->SetMarkerStyle(20);
//  t_thrown_above_1_constr->SetMarkerColor(7); 
    
  
  t_accepted_above_1_constr->SetMarkerStyle(20);
  //t_accepted_above_1_constr->SetMarkerColor(7);

    TH1F *Hist_Effic = (TH1F*)t_accepted_above_1_constr->Clone("efficiency");
    Hist_Effic->Sumw2();
    Hist_Effic->Divide(t_thrown_above_1_constr);
    Hist_Effic->SetTitle("; |t| < 0.6 < #pi^{+} #pi^{-} < 0.92; efficiency");
    //t_thrown_above_1->SetMarkerColor(7);

    TH1F *Hist_Effic2 = (TH1F*)t_accepted_above_1->Clone("efficiency_2");
    Hist_Effic2->Sumw2();
    Hist_Effic2->Divide(t_thrown_above_1);
    Hist_Effic2->SetTitle("; |t| < 0 < #pi^{+} #pi^{-} < 4; efficiency2");

    TCanvas *Efficiency2 = new TCanvas("Efficiency2", "   Efficiency2");
    Efficiency2->Divide(3,1);
    TLatex *lat1 = new TLatex();
    TLatex *lat2 = new TLatex();
    TLatex *lat3 = new TLatex();
     
    

    Efficiency2->cd(1);
    t_thrown_above_1->Draw("ep");
    lat1->DrawLatexNDC(.15,.95,"t_thrown");
    
    
    Efficiency2->cd(2);
    t_accepted_above_1->Draw("ep");
    lat2->DrawLatexNDC(.15,.95,"t_accepted");
    

    // draw efficiency vs Egamma
    Efficiency2->cd(3);
    Hist_Effic2->Draw("ep");
    lat3->DrawLatexNDC(.15,.95,"Efficiency 2");
       
 
    TCanvas *Efficiency1 = new TCanvas("Efficiency1", "Efficiency1", 1000, 400);
    Efficiency1->Divide(3,1);
    TLatex *lat4 = new TLatex();
    TLatex *lat5 = new TLatex();
    TLatex *lat6 = new TLatex();


    Efficiency1->cd(1);
    t_thrown_above_1_constr->Draw("ep");
    lat4->DrawLatexNDC(.15,.95,"t_thrown_constrained_Mass");
    
    Efficiency1->cd(2);
    t_accepted_above_1_constr->Draw("ep");
    lat5->DrawLatexNDC(.15,.95,"t_accepted_constrained_Mass");

    // draw efficiency vs Egamma
    Efficiency1->cd(3);
    Hist_Effic->Draw("ep");
    lat6->DrawLatexNDC(.15,.95,"Efficiency_constrained");

    ////////////////////////////////Graph from Histogram///////////////////////
    TCanvas *c4 = new TCanvas("c4", " graph from histogram");
    // Create TGraphErrors object from histogram
    TGraphErrors* garaph = new TGraphErrors(Hist_Effic);

    // Set graph options
    garaph->SetTitle("Efficiency (Histogram->graph)");
    garaph->GetXaxis()->SetTitle("|t|");
    garaph->GetYaxis()->SetTitle("efficiency");
    garaph->SetMarkerStyle(20);
    garaph->SetMarkerSize(1.5);

    // Create canvas and draw graph
    
    garaph->Draw("AP");
/////////////////////////////Histogram to graph 1///////////////////
   TCanvas *c5 = new TCanvas("c5", " graph from histogram 1");
   c5->Divide(3,1);
   c5->cd(1);
    // Create TGraphErrors object from histogram
    TGraphErrors* garah1 = new TGraphErrors(t_thrown_above_1_constr);

    // Set graph options
    garah1->SetTitle("t_thrown_constr (Histogram->graph)");
    garah1->GetXaxis()->SetTitle("|t|");
    garah1->GetYaxis()->SetTitle("counts");
    garah1->SetMarkerStyle(20);
    garah1->SetMarkerSize(1.5);

    // Create canvas and draw graph
    
    garah1->Draw("AP");
    c5->cd(2);

    TGraphErrors* garah2 = new TGraphErrors(t_accepted_above_1_constr);

    // Set graph options
    garah2->SetTitle("t_accepted_constr (Histogram->graph)");
    garah2->GetXaxis()->SetTitle("|t|");
    garah2->GetYaxis()->SetTitle("counts");
    garah2->SetMarkerStyle(20);
    garah2->SetMarkerSize(1.5);
    garah2->Draw("AP");


    // Create a new canvas to draw the ratio graph
TCanvas *c6 = new TCanvas("c6", "Ratio graph");

// Create a new TGraphErrors object to hold the ratio
TGraphErrors *graph_ratio = new TGraphErrors();
graph_ratio->SetTitle("Ratio of Observed Sim to thrown_sim = Efficiency");
graph_ratio->SetMarkerStyle(20);
graph_ratio->SetMarkerSize(1.2);
graph_ratio->SetLineColor(kRed);
graph_ratio->SetMarkerColor(kRed);
graph_ratio->SetFillColor(0);

// Loop through the points of the two graphs and calculate the ratio
for (int i=0; i<t_accepted_above_1_constr->GetNbinsX(); i++) {
    double xval, yval, y1val, y2val, eyval, ey1val, ey2val;
    xval = t_accepted_above_1_constr->GetBinCenter(i+1);
    y1val = t_thrown_above_1_constr->GetBinContent(i+1);
    y2val = t_accepted_above_1_constr->GetBinContent(i+1);
    ey1val = t_thrown_above_1_constr->GetBinError(i+1);
    ey2val = t_accepted_above_1_constr->GetBinError(i+1);
    if (y1val == 0) continue; // Avoid division by zero
    yval = y2val / y1val;
    eyval = yval * sqrt(pow(ey2val/y2val, 2) + pow(ey1val/y1val, 2));
    graph_ratio->SetPoint(i, xval, yval);
    graph_ratio->SetPointError(i, 0, eyval);
}

// Set graph options
graph_ratio->GetXaxis()->SetTitle("|t|");
graph_ratio->GetYaxis()->SetTitle("Efficiency");
graph_ratio->Draw("AP");




}

  

