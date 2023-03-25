#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TGraphErrors.h"

int csv_vector_graph2() {
  // Read data from CSV file
  std::ifstream inFile("data2.csv");
  std::string line;
  std::vector<double> x, y, yErr;
  double val1, val2, val3;
  char separator;
  std::getline(inFile, line);  // Skip header line
  //while (std::getline(inFile, line)) {
  /*  std::stringstream ss(line);
    std::string field;
    std::getline(ss, field, ',');
    x.push_back(std::stod(field));
    std::getline(ss, field, ',');
    y.push_back(std::stod(field));
    std::getline(ss, field, ',');
    yErr.push_back(std::stod(field));
    */
    while (inFile >> val1 >> separator >> val2 >> separator >> val3) {
    x.push_back(val1);
    y.push_back(val2);
    yErr.push_back(val3);
  //}
  }
  inFile.close();

  // Create TGraphErrors object
  //const int nPoints = x.size();
  //  TGraphErrors* gr = new TGraphErrors(x.size(), x.data(), y.data(), nullptr, yErr.data());
  TGraphErrors* gr = new TGraphErrors(x.size(), &x[0], &y[0], nullptr, &yErr[0]); 
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
