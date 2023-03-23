#include <iostream>
#include <fstream>
#include <vector>
#include "TGraphErrors.h"

int graph1_vector(){

  // Define x and y data
  const int nPoints = 10;
  std::vector<double> x {15, 28, 30, 33, 35, 47, 67, 108, 112, 137};
  std::vector<double> y {12, 14, 15, 23, 34, 55, 37,48, 34,56};
  std::vector<double> yErr {1.0, 2.0, 1.5, 2.5, 5.0, 11, 3.0 ,14.0 ,5.0 ,6.0 };  // Define errors for y values

  // Create TGraphErrors object
  TGraphErrors* gr = new TGraphErrors(nPoints, x.data(), y.data(), nullptr, yErr.data());

  // Save data to CSV file
  std::ofstream outFile("data2.csv");
  outFile << "x,y,yErr" << std::endl;
  for (int i = 0; i < nPoints; i++) {
    outFile << x[i] << "," << y[i] << "," << yErr[i] << std::endl;
  }
  outFile.close();

  // Plot graph
  TCanvas* c1 = new TCanvas("c1", "Graph with Errors", 600, 400);
  gr->SetTitle("Graph with Errors");
  gr->GetXaxis()->SetTitle("x");
  gr->GetYaxis()->SetTitle("y");
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);
  gr->Draw("ALP");

  return 0;
}
