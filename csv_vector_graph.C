#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TGraphErrors.h"

int csv_vector_graph() {
  // Read data from CSV file
  std::ifstream inFile("data2.csv");
  std::string line;
  std::vector<double> x, y, yErr;
  std::getline(inFile, line);  // Skip header line
  while (std::getline(inFile, line)) {
    std::stringstream ss(line);
    std::string field;
    std::getline(ss, field, ',');
    x.push_back(std::stod(field));
    std::getline(ss, field, ',');
    y.push_back(std::stod(field));
    std::getline(ss, field, ',');
    yErr.push_back(std::stod(field));
  }
  inFile.close();

  // Create TGraphErrors object
  const int nPoints = x.size();
  TGraphErrors* gr = new TGraphErrors(nPoints, x.data(), y.data(), nullptr, yErr.data());

  // Draw the graph
  TCanvas* c1 = new TCanvas("c1", "Graph with Errors", 600, 400);
  gr->SetTitle("Graph with Errors");
  gr->GetXaxis()->SetTitle("x");
  gr->GetYaxis()->SetTitle("y");
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);
  gr->Draw("AP");

  return 0;
}
