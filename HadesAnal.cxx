#include "HadesAnal.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TH2F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TText.h"
#include "TMath.h"
#include "TRandom.h"
#include "TSystem.h"
#include "TMatrixD.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
//#include <random>
#include "TCanvas.h"
#include "TPad.h"
#include "TCutG.h"


#define SQR(x) ((x)*(x))
using namespace std;

Int_t   nentries;

HadesAnal *gHadesA;  
//HFilter *filter=new HFilter;

double openingangle(const TLorentzVector& a, const TLorentzVector& b)
{
  return TMath::ACos( (a.Px()*b.Px() + a.Py()*b.Py() +  a.Pz()*b.Pz() ) / ( a.Vect().Mag() * b.Vect().Mag() ) );
}

//--------------------------------------------------------------------
HadesAnal::HadesAnal(TTree *tree):InheritClass(tree)
{
  //gSystem->Load("libSymRun.so");
   gHadesA = this;

  nentries = Int_t(fChain->GetEntries());
  printf("Entries in the tree: %d\n",nentries);
  
  strcpy(theOutFileName,"HadesAnal.root");

  //!Open the nprun geometry
  if(!OpenGeometry())
    {
      printf("Error: The geometry can not be open!\n");
      return;
    }
 

  CreateHistos();
}

//--------------------------------------------------------------------

#include "CreateHistos.cxx"
#include "WriteHistos.cxx"

void HadesAnal::Init(void)
{
  //CreateHistos();
  //Reading kinematic files
  //TFile* fi = TFile::Open("cuts_mod5.root");

  char cname1[100];
  char cname2[100];

  //TFile* f1 = new TFile("matrices_agag_ckt.root");
  //  TFile* f1 = new TFile("matrices_agag.root");
  
  //heff3d_el= (TH3F*) f1->Get("heff3D_ele")->Clone();
  //hacc3d_el= (TH3F*) f1->Get("hacc3D_ele")->Clone();

  //heff3d_pos= (TH3F*) f1->Get("heff3D_pos")->Clone();
  //hacc3d_pos= (TH3F*) f1->Get("hacc3D_pos")->Clone();

  
    
  //sprintf(cname1,"cutg_mod5_%d",Pen);
  //fcut1_mod5  = (TCutG*)fi->Get(cname1)->Clone();
  // sprintf(cname2,"cutg2_mod5_%d",Pen);
  // fcut2_mod5  = (TCutG*)fi->Get(cname2)->Clone();
  //fi->Close();
  //delete fi;
   
}


//
//________________________________________________________________________
Int_t HadesAnal::ReadLine(FILE *fID, char *line)
{
  char buff[128];
  char ch;

  while (  fgets(buff, 127, fID) != NULL) 
    {
      ch = buff[0];
      if (ch != '!' && ch != '*' && ch != '#') // some comment characters 
	{
	  strcpy(line, buff);
	  return 1;
	}
    }
  return EOF;
}

//--------------------------------------------------------------------
HadesAnal::~HadesAnal()
{
  WriteHistos();

  //if(fcut1_mod5) delete fcut1_mod5;
 }

//--------------------------------------------------------------------
void HadesAnal::Loop(Char_t * file)
{
 
	    
  //    if(file == NULL)
  //	      {
  //		theOut=new TFile(theOutFileName,"recreate");
  //	      }


  //	    TTree TT("TT","TreeHades");

	   
	    // declare the tree structure
      
	    //TT.Branch("evnb",&evnb, "evnb/I" );
	    //TT.Branch("lep","TLorentzVector", &lvep);
	    //TT.Branch("lem","TLorentzVector", &lvem);
  //double pion_momentum = 1015.31;
  double pion_momentum = 687.2;   
  double pion_energy = sqrt(pion_momentum*pion_momentum + 139.56995*139.56995);

  TLorentzVector *proj;
  proj = new TLorentzVector(0,0,pion_momentum, pion_energy); //---------------PION BEAM
  TLorentzVector *targ;
  targ = new TLorentzVector(0,0,0, 938.27231);          //-------------------PROTON TARGET
  TLorentzVector *beam;
  beam = new TLorentzVector(0,0,0,0);
  *beam = *proj + *targ;

  TLorentzVector *p;
  p = new TLorentzVector(0,0,0,0);            //---------------PION BEAM
  TLorentzVector *pim;
  pim = new TLorentzVector(0,0,0,0);          //-------------------PROTON TARGET
  TLorentzVector *ep;
  ep = new TLorentzVector(0,0,0,0);
  TLorentzVector *em;
  em = new TLorentzVector(0,0,0,0);
  TLorentzVector *mm;
  mm = new TLorentzVector(0,0,0,0);
  TLorentzVector *total;
  total = new TLorentzVector(0,0,0,0);
		   
  Double_t gloW;
  
	    if (fChain == 0) return;

	    
	    for (Long_t event=0; event<nentries; event++) 
	      {
		if(!(event%100000))  
		  {
		    printf("Event: %ld\r",event);
		    fflush(stdout);
		  }
		LoadTree(event);
		fChain->GetEntry(event);
		//cout<< eventNum<<endl;
		
		if (Npart){
		  for (int i=0;i<Npart;i++){
	 
		    TVector3 m3,vert, p1, p2, p3, p4;
		    TLorentzVector *lv = new TLorentzVector;
		    TLorentzVector *Theta_CM;
		    TLorentzVector *lv1 = new TLorentzVector;
		    TLorentzVector *lv2 = new TLorentzVector;	
		    TLorentzVector *lv3 = new TLorentzVector;
		    TLorentzVector *lv4 = new TLorentzVector;
	    		    
		    m3.SetXYZ(Particles_fP_fX[i],Particles_fP_fY[i],Particles_fP_fZ[i]);
		    vert.SetXYZ(Particles_fV_fX[i],Particles_fV_fY[i],Particles_fV_fZ[i]);
		    
		    lv->SetPxPyPzE(Particles_fP_fX[i],Particles_fP_fY[i],Particles_fP_fZ[i],Particles_fE[i]);	 
		    lv1->SetPxPyPzE(Particles_fP_fX[i],Particles_fP_fY[i],Particles_fP_fZ[i],Particles_fE[i]);	 
		    lv1->Boost(-(*beam).BoostVector());

		    double ThetaCM=lv1->Theta()*180./TMath::Pi();
		      
		    double theta=m3.Theta()*180./TMath::Pi();
		    int pid=Particles_pid[i];
		    int pin=Particles_parentIndex[i];


		    //int gloW=Particles_wt[i];
		    gloW=Particles_wt[0];
	  

		    float th=lv->Theta()*180./TMath::Pi();
		    float ph=lv->Phi()*180./TMath::Pi();	  
		    float mom=lv->Rho()*1000;

		    *total = *pim + *ep + *em;  
		    
		    PID_histo->Fill(pid);
		    
		    if(pid==9){
		      //p1.SetXYZ(lv->Px()*sin(th)*cos(ph),lv->Py()*sin(th)*sin(ph),lv->Pz()*cos(ph));
		      //pim->SetVectM(p1, 139.56995);
		      Pimthmom9_4pi->Fill(mom,th);
		      PimMass9_4pi->Fill(pim->M()/1000.);       
		      PimmomX9_4pi->Fill(lv->Px()*1000.);
		      PimmomY9_4pi->Fill(lv->Py()*1000.);
		      PimmomZ9_4pi->Fill(lv->Pz()*1000.);
		      PimMomtot9_4pi->Fill(lv->P()*1000.);
		      PimthetaCM->Fill(ThetaCM);
		      Pimtheta->Fill(th);
		      Pimphi->Fill(ph);
		    }
		     

		    if(pid==14){
		      //p2.SetXYZ(lv->Px()*sin(th)*cos(ph),lv->Py()*sin(th)*sin(ph),lv->Pz()*cos(ph));
		      //p->SetVectM(p2, 938.27231);
		      Pthmom14_4pi->Fill(mom,th);
		      PMass14_4pi->Fill(lv->M()/1000.);       
		      PmomX14_4pi->Fill(lv->Px()*1000.);
		      PmomY14_4pi->Fill(lv->Py()*1000.);
		      PmomZ14_4pi->Fill(lv->Pz()*1000.);
		      PMomtot14_4pi->Fill(lv->P()*1000.);
		      PVerX14_4pi->Fill(vert.X());
		      PVerY14_4pi->Fill(vert.Y());
		      PVerZ14_4pi->Fill(vert.Z());
		      PthetaCM->Fill(ThetaCM);
                      Ptheta->Fill(th);
		      Pphi->Fill(ph);
		    } 		      

		    if(pid==2){
		      p3.SetXYZ(lv->Px()*1000,lv->Py()*1000,lv->Pz()*1000);
                      ep->SetVectM(p4, 0.51099906);
		      EPthmom2_4pi->Fill(mom,th);
		      EPMass2_4pi->Fill(lv->M()/1000.);       
		      EPmomX2_4pi->Fill(lv->Px()*1000.);
		      EPmomY2_4pi->Fill(lv->Py()*1000.);
		      EPmomZ2_4pi->Fill(lv->Pz()*1000.);
		      EPMomtot2_4pi->Fill(lv->P()*1000.);
		      EPthetaCM->Fill(ThetaCM);
		      EPtheta->Fill(th);
		      EPphi->Fill(ph);
		    }		      

		    if(pid==3){
		      p4.SetXYZ(lv->Px()*1000,lv->Py()*1000,lv->Pz()*1000);
                      em->SetVectM(p4, 0.51099906);
		      EMthmom3_4pi->Fill(mom,th);
		      EMMass3_4pi->Fill(lv->M()/1000.);       
		      EMmomX3_4pi->Fill(lv->Px()*1000.);
		      EMmomY3_4pi->Fill(lv->Py()*1000.);
		      EMmomZ3_4pi->Fill(lv->Pz()*1000.);
		      EMMomtot3_4pi->Fill(lv->P()*1000.);
		      EMtheta->Fill(th);
		      EMthetaCM->Fill(ThetaCM);
		      EMphi->Fill(ph);
		      }		      

		    if(pid==7){
		      //p4.SetXYZ(lv->Px()*1000,lv->Py()*1000,lv->Pz()*1000);
                      //em->SetVectM(p4, 0.51099906);
		      Pi0thmom7_4pi->Fill(mom,th);
		      Pi0Mass7_4pi->Fill(lv->M()/1000.);       
		      Pi0momX7_4pi->Fill(lv->Px()*1000.);
		      Pi0momY7_4pi->Fill(lv->Py()*1000.);
		      Pi0momZ7_4pi->Fill(lv->Pz()*1000.);
		      Pi0Momtot7_4pi->Fill(lv->P()*1000.);
		      Pi0theta->Fill(th);
		      Pi0thetaCM->Fill(ThetaCM);
		      Pi0phi->Fill(ph);
		      }		      

		    //cout<<pid<<endl;
      		    //theta_p1->Fill(th);
		    ALLMass->Fill(total->M()/1000.);

		  }

		  *mm = *ep + *em;
		  float Invmass = mm->M()/1000.;
		  //float mass2 = Invmass*Invmass;
		  float EpEm_mom = mm->P()/1000.;
		  float EpEm_energy = mm->E()/1000.;
		  cout<<"M =  " <<Invmass <<"\t\t" << "P =  " << EpEm_mom <<"\t\t" <<"E =  " << EpEm_energy <<endl;
		  float Opang = openingangle(*ep,*em);
		  OpnAng->Fill(Opang);
		  float Opang_theta = Opang*TMath::RadToDeg();
		  cout << "Opening angle : " << Opang_theta << endl;
		  /*if( 4 < Opang_theta )*/ MissingMass->Fill(Invmass);
		  if( 5 < Opang_theta ) MissingMass1->Fill(Invmass);
		  if( 6 < Opang_theta ) MissingMass2->Fill(Invmass);
		  if( 7 < Opang_theta ) MissingMass3->Fill(Invmass);
		  if( 8 < Opang_theta ) MissingMass4->Fill(Invmass);
		  if( 9 < Opang_theta ) MissingMass5->Fill(Invmass);
		  if( 10 < Opang_theta ) MissingMass6->Fill(Invmass);

		  //if(pid==2) p3.SetXYZ(lv->Px()*sin(th)*cos(ph),lv->Py()*sin(th)*sin(ph),lv->Pz()*cos(ph)); ep->SetVectM(p3, 0.51099906);
		  //if(pid==3) p4.SetXYZ(lv->Px()*sin(th)*cos(ph),lv->Py()*sin(th)*sin(ph),lv->Pz()*cos(ph)); em->SetVectM(p4, 0.51099906);
		  OpenAngle->Fill(Opang_theta);
		  Histo->Fill(Invmass,Opang_theta);

		   

		  
	   }
	      
	      }//end event loop 


 
	    //TT.Write(); 
}

//------------------------------------------------------------------
Int_t HadesAnal::OpenGeometry()
{
    return 1;//OK
}


