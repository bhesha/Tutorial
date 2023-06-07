void tree_check(){
TFile* file = new TFile("../../Flat_testout2.root", "READ");
if (!file || file->IsZombie()) {
  std::cout << "Error opening file: myFile.root" << std::endl;
  return;
}
TTree* tree = nullptr;
TString treeName = "rho0_Tree";
tree = dynamic_cast<TTree*>(file->Get(treeName));

if (!tree) {
  std::cout << "Failed to retrieve tree " << treeName << "." << std::endl;
  return;
}

std::cout << "Tree " << treeName << " retrieved successfully." << std::endl;
// Rest of your code for working with the tree goes here

// Clean up
file->Close();
delete file;
}
////////////////////////////////////////
void tree_check(){
TFile* file = new TFile("../../Flat_testout2.root", "READ");
if (!file || file->IsZombie()) {
  std::cout << "Error opening file: myFile.root" << std::endl;
  return;
}
TString treeName = "rho0_Tree";
TTree *tree = (TTree*)file->Get(treeName);

if (!tree) {
  std::cout << "Failed to retrieve tree " << treeName << "." << std::endl;
  return;
}

std::cout << "Tree " << treeName << " retrieved successfully." << std::endl;
// Rest of your code for working with the tree goes here

// Clean up
file->Close();
delete file;
}

