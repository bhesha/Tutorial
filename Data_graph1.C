#include <TCanvas.h>
#include <TGraphErrors.h>

void Data_graph1(){
    // Define the data
    const int npoints = 5;
    double x[] = {1.25, 1.75, 2.5, 4, 7};
    double y[] = {0.0921044, 0.0857653,0.077879,0.0800191,0.0755042};
    double ey[] = {0.00019152, 0.000512515, 0.000657792, 0.000947931, 0.0013666};

  

    // Create a TGraphErrors object
    //  TGraphErrors *graph = new TGraphErrors(5, x, y, 0, ey);    //thrown
      TGraphErrors *graph = new TGraphErrors(npoints, x, y, 0, ey);    //Observed Sim  

    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "graph from arrays");
            //c1->SetLogy();
    // Set the axis labels and titles
    graph->GetXaxis()->SetTitle("|t|");
    graph->GetYaxis()->SetTitle("Yield ");
    graph->SetTitle("1)Graph from arrays");
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(1.2);
    graph->SetLineColor(kRed);
    graph->SetMarkerColor(kRed);
    graph->SetFillColor(0);

    // Set the range for the X axis
    graph->GetXaxis()->SetLimits(1, 9);

    // Draw the graph
    graph->Draw("AP");

    // Show the canvas
    c1->Draw();

   TH1D *hist = new TH1D("hist", "Histogram from Arrays", npoints, x[0], x[npoints-1]);
      for (int i = 0; i < npoints; ++i) {
        hist->SetBinContent(i+1, y[i]);
        hist->SetBinError(i+1, ey[i]);
    }
    TCanvas *c2 = new TCanvas("c2", "Histogram from arrays");
    hist->Draw("E");

    
    // Create a new histogram with the same number of bins as graph_ratio
TH1D* hist_ratio = new TH1D("hist_ratio", "Histogram from graph 1", graph->GetN(), graph->GetX()[0], graph->GetX()[graph->GetN()-1]);
 for (int i = 0; i < graph->GetN(); ++i) {
  hist_ratio->SetBinContent(i+1, graph->GetY()[i]);
  hist_ratio->SetBinError(i+1, graph->GetEY()[i]);
}
  TCanvas *c3 = new TCanvas("c3", "Histogram from graph 1");

hist_ratio->Draw("E");

   // c1->close();

 TCanvas *c4 = new TCanvas("c4", " graph from histogram");
    // Create TGraphErrors object from histogram
    TGraphErrors* garaph = new TGraphErrors(hist);

    // Set graph options
    garaph->SetTitle("Graph with Error Bars");
    garaph->GetXaxis()->SetTitle("x");
    garaph->GetYaxis()->SetTitle("y");
    garaph->SetMarkerStyle(20);
    garaph->SetMarkerSize(1.5);

    // Create canvas and draw graph
    
    garaph->Draw("AP");
}
