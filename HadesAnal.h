#ifndef HadesAnal_h
#define HadesAnal_h
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TEventList.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include "TRandom3.h"
#include "TMatrixD.h"
#include "TCanvas.h"
#include "ClassName.h"
#include "utility.h"
#include "TLorentzVector.h"
#include "TCutG.h"


class HadesAnal: public InheritClass {

  TFile *theOut;
  Char_t theOutFileName[64];
  Bool_t WriteTree;
  Int_t Pen;
  TFile *f;
  
  Int_t OpenGeometry(); // Gets the geometry information
  void CreateHistos();
  void WriteHistos();

 public:
  HadesAnal(TTree *tree=0);
  ~HadesAnal();
  void   Init();
  void   Loop(Char_t *file);
  Int_t  ReadLine(FILE *fID, char *line);
  void SetWriteTree(Bool_t f) {WriteTree = f;}
  void SetEnergy(int en) {Pen = en;}

  TH1F *PID_histo;
  TH1F *theta_p1;
  TH1F *theta_p2;
  TH1F *theta_p3;
  TH2F *EPthmom2_4pi;
  TH2F *EMthmom3_4pi;
  TH2F *Pimthmom9_4pi;
  TH2F *Pthmom14_4pi;
  TH1F *Pimphi;
  TH1F *Pimtheta;
  TH1F *PimthetaCM;
  TH1F *PimVerX9_4pi;
  TH1F *PimVerY9_4pi;
  TH1F *PimVerZ9_4pi;

  TH1F *PimmomX9_4pi;
  TH1F *PimmomY9_4pi;
  TH1F *PimmomZ9_4pi;
  TH1F *PimMomtot9_4pi;

  TH1F *EMphi;
  TH1F *EMtheta;
  TH1F *EMthetaCM;
  TH1F *EMVerX3_4pi;
  TH1F *EMVerY3_4pi;
  TH1F *EMVerZ3_4pi;

  TH1F *EMmomX3_4pi;
  TH1F *EMmomY3_4pi;
  TH1F *EMmomZ3_4pi;
  TH1F *EMMomtot3_4pi;

  TH1F *EPphi;
  TH1F *EPtheta;
  TH1F *EPthetaCM;
  TH1F *EPVerX2_4pi;
  TH1F *EPVerY2_4pi;
  TH1F *EPVerZ2_4pi;
  TH1F *EPmomX2_4pi;
  TH1F *EPmomY2_4pi;
  TH1F *EPmomZ2_4pi;
  TH1F *EPMomtot2_4pi;

  TH1F *Pphi;
  TH1F *Ptheta;
  TH1F *PthetaCM;
  TH1F *PVerX14_4pi;
  TH1F *PVerY14_4pi;
  TH1F *PVerZ14_4pi;

  TH1F *PmomX14_4pi;
  TH1F *PmomY14_4pi;
  TH1F *PmomZ14_4pi;
  TH1F *PMomtot14_4pi; 

  TH1F *PMass14_4pi;
  TH1F *PimMass9_4pi;
  TH1F *EMMass3_4pi;
  TH1F *EPMass2_4pi;
  TH1F *MissingMass;
  TH1F *MissingMass1; 
  TH1F *MissingMass2; 
  TH1F *MissingMass3; 
  TH1F *MissingMass4; 
  TH1F *MissingMass5; 
  TH1F *MissingMass6; 
  TH1F *MissingMass7; 

 
  TH2F *  Pi0thmom7_4pi;
  TH1F *  Pi0Mass7_4pi;       
  TH1F *  Pi0momX7_4pi;
  TH1F *  Pi0momY7_4pi;
  TH1F *  Pi0momZ7_4pi;
  TH1F *  Pi0Momtot7_4pi;
  TH1F *  Pi0theta;
  TH1F *  Pi0thetaCM;
  TH1F *  Pi0phi;
  TH1F *  Pi0VerZ7_4pi;
  TH2F *  Histo;

  
  TH1F *ALLMass;
  TH1F *EpEm_OA;

  TH1F *OpnAng;
  TH1F *OpenAngle;
};



R__EXTERN HadesAnal *gHadesA; // external pointer to KRAnal.

#endif


