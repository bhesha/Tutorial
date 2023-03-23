#include <iostream>
#include <fstream>
#include "TGraphErrors.h"

int csv_to_graph() {
  // Read data from CSV file
  const int nMaxPoints = 1000;
  double x[nMaxPoints], y[nMaxPoints], yErr[nMaxPoints];
  int nPoints = 0;
  
  std::ifstream inFile("data2.csv");
  std::string line;
  std::getline(inFile, line);  // Skip header line
  while (std::getline(inFile, line)) {
    std::stringstream ss(line);
    std::string field;
    std::getline(ss, field, ',');
    x[nPoints] = std::stod(field);
    std::getline(ss, field, ',');
    y[nPoints] = std::stod(field);
    std::getline(ss, field, ',');
    yErr[nPoints] = std::stod(field);
    nPoints++;
  }
  inFile.close();

  // Create TGraphErrors object
  TGraphErrors* gr = new TGraphErrors(nPoints, x, y, nullptr, yErr);

  // Draw the graph
  TCanvas* c1 = new TCanvas("c1", "Graph", 800, 600);
  gr->Draw("ALP");
  gr->SetTitle("My Graph");
  gr->GetXaxis()->SetTitle("x");
  gr->GetYaxis()->SetTitle("y");
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);

  return 0;
}
