void openroot(){
TString fileName = "pminus_cut_range.root";
TFile* file = new TFile(fileName, "READ");
if (file->IsZombie()) {
  std::cout << "Error opening file: " << fileName << std::endl;
  delete file;
  return;
}

// File opened successfully, continue with your code

// Clean up
file->Close();
delete file;
}

//////////////////////////////////////


TString fileName = "myFile.root";
TFile* file = TFile::Open(fileName, "READ");

if (!file || file->IsZombie()) {
  std::cout << "Error opening file: " << fileName << std::endl;
  return;
}

// File opened successfully, continue with your code

// Clean up
file->Close();
delete file;
