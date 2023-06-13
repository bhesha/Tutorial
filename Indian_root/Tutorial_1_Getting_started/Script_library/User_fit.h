#ifndef Breight_H_06_09_2023
#define Breight_H_06_09_2023
namespace User_fit{

  Double_t mybw_relative(Double_t* x, Double_t* par)
  {Double_t amplitude = par[0];
  Double_t gamma0 = par[1]; // Gamma = par[1] M =par2
  Double_t mass = par[2]; 
  //Apply the variable width correction.
  Double_t mpi = 0.13957;  
  Double_t y = pow((x[0]*x[0] - 4*mpi*mpi)/(mass*mass-4*mpi*mpi),1.5);
  Double_t gamma = ((mass*gamma0*y)/x[0]);    //gamma correction
  // Calcuate the Breit-Weigner resonance function.
  Double_t xxMinusmm = pow(mass, 2) - pow(x[0], 2);
 // Double_t bw  = amplitude*mass*gamma*x[0]/((pow(xxMinusmm, 2)) + (pow(mass*gamma, 2))); //Width corrected applied
  Double_t bw  = amplitude*mass*gamma0*x[0]/((pow(xxMinusmm, 2)) + (pow(mass*gamma0, 2))); //Width corrected not applied
  return bw;
}

Double_t Backgnd_pol(Double_t* x, Double_t* par)
{
  Double_t poly_2 = par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
  return poly_2;
}

Double_t total1(Double_t* x, Double_t* par)
{
  return mybw_relative(x, par) + Backgnd_pol(x, &par[3]);
}

Double_t total2(Double_t* x, Double_t* par)
{
  return mybw_relative(x, par) + Backgnd_pol(x, &par[3]) + mybw_relative(x, &par[6]);

}

}
#endif