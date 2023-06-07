void hist_check(){
TString histName = "dHist_2Pi_t1.0_1.5_c0.00_1.40";
TFile* file = new TFile("pminus_cut_range.root", "READ");
TH1* hist = nullptr;
if (!file || file->IsZombie()) {
  std::cout << "Error opening file: myFile.root" << std::endl;
  return;
}
hist = dynamic_cast<TH1*>(file->Get(histName));
TH1F *hist  = (TH1F*)file->Get(histName); 
if (!hist) {
  std::cout << "Failed to retrieve histogram " << histName << "." << std::endl;
  return;
}

std::cout << "Histogram " << histName << " retrieved successfully." << std::endl;
// Rest of your code for working with the histogram goes here

// Clean up
file->Close();
delete file;
}


/////////////////////////////
void hist_check(){
TString histName = "dHist_2Pi_t1.0_1.5_c0.00_1.40";
TFile* file = new TFile("pminus_cut_range.root", "READ");
if (!file || file->IsZombie()) {
  std::cout << "Error opening file: myFile.root" << std::endl;
  return;
}
TH1F *hist  = (TH1F*)file->Get(histName); 
if (!hist) {
  std::cout << "Failed to retrieve histogram " << histName << "." << std::endl;
  return;
}

std::cout << "Histogram " << histName << " retrieved successfully." << std::endl;
// Rest of your code for working with the histogram goes here

// Clean up
file->Close();
delete file;
}