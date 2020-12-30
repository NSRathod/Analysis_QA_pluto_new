
void HadesAnal::WriteHistos(void)
{
  
  float x1,x2,y1,y2;
  x1=0.52; y1=0.8;x2=0.7;y2=0.87;
   TPaveText *t1,*t2; 

  f = new TFile("hades_PPim_Bremsstrahlung_OUTPUT1.root","recreate");
  //if (!f || !f->IsOpen()){
  //f=new TFile("SymulHe3_histos.root","recreate");
  //}

  PID_histo->Write();
  
  TCanvas *c1=new TCanvas("PlutoOut_Proton1","PlutoOut_Proton1");
  c1->Divide(2,2);
  c1->cd(1);
  PMomtot14_4pi->Draw();
  c1->cd(2);
  Pphi->Draw();
  c1->cd(3);
  Ptheta->Draw();
  c1->cd(4);
  PthetaCM->Draw();

  c1->Write();
  c1->SaveAs("PlutoOut_Proton1.png");
  
  TCanvas *c2=new TCanvas("PlutoOut_Proton2","PlutoOut_Proton2");
  c2->Divide(2,2);  
  c2->cd(1);
  Pthmom14_4pi->Draw("colz");
  c2->cd(2);
  PmomX14_4pi->Draw();
  c2->cd(3);
  PmomY14_4pi->Draw();
  c2->cd(4);
  PmomZ14_4pi->Draw();
  
  c2->Write();

  c2->SaveAs("PlutoOut_Proton2.png");
  
  TCanvas *c3=new TCanvas("PlutoOut_PIM1","PlutoOut_PIM1");
  c3->Divide(2,2);
  c3->cd(1);
  PimMomtot9_4pi->Draw();
  c3->cd(2);
  Pimphi->Draw();
  c3->cd(3);
  Pimtheta->Draw();
  c3->cd(4);
  PimthetaCM->Draw();

  c3->Write();
  c3->SaveAs("PlutoOut_PIM1.png");

  TCanvas *c4=new TCanvas("PlutoOut_PIM2","PlutoOut_PIM2");
  c4->Divide(2,2);  
  c4->cd(1);
  Pimthmom9_4pi->Draw("colz");
  c4->cd(2);
  PimmomX9_4pi->Draw();
  c4->cd(3);
  PimmomY9_4pi->Draw();
  c4->cd(4);
  PimmomZ9_4pi->Draw();
  
  c4->Write();
  c4->SaveAs("PlutoOut_PIM2.png");


  TCanvas *c5=new TCanvas("PlutoOut_EP1","PlutoOut_EP1");
  c5->Divide(2,2);
  c5->cd(1);
  EPMomtot2_4pi->Draw();
  c5->cd(2);
  EPphi->Draw();
  c5->cd(3);
  EPtheta->Draw();
  c5->cd(4);
  EPthetaCM->Draw();

  c5->Write();
  c5->SaveAs("PlutoOut_EP1.png");

  TCanvas *c6=new TCanvas("PlutoOut_EP2","PlutoOut_EP2");
  c6->Divide(2,2);  
  c6->cd(1);
  EPthmom2_4pi->Draw("colz");
  c6->cd(2);
  EPmomX2_4pi->Draw();
  c6->cd(3);
  EPmomY2_4pi->Draw();
  c6->cd(4);
  EPmomZ2_4pi->Draw();
  
  c6->Write();
  c6->SaveAs("PlutoOut_EP2.png");

  TCanvas *c7=new TCanvas("PlutoOut_EM1","PlutoOut_EM1");
  c7->Divide(2,2);
  c7->cd(1);
  EMMomtot3_4pi->Draw();
  c7->cd(2);
  EMphi->Draw();
  c7->cd(3);
  EMtheta->Draw();
  c7->cd(4);
  EMthetaCM->Draw();

  c7->Write();
  c7->SaveAs("PlutoOut_EM1.png");

  TCanvas *c8=new TCanvas("PlutoOut_EM2","PlutoOut_EM2");
  c8->Divide(2,2);  
  c8->cd(1);
  EMthmom3_4pi->Draw("colz");
  c8->cd(2);
  EMmomX3_4pi->Draw();
  c8->cd(3);
  EMmomY3_4pi->Draw();
  c8->cd(4);
  EMmomZ3_4pi->Draw();
  
  c8->Write();
  c8->SaveAs("PlutoOut_EM2.png");

  //TCanvas *c3=new TCanvas("Out(#pi- p --> #pi- p #gamma e+ e-)","Out(#pi- p --> #pi- p #gamma e+ e-)");
  //c3->Divide(2,2);  

  //  theta_p1->Write();
  /*  thmom2_4pi->Write();
  thmom3_4pi->Write();
  thmom9_4pi->Write();
  thmom14_4pi->Write();*/

  EPtheta->Write();
  EMtheta->Write();
  Ptheta->Write();
  Pimtheta->Write();

  EPthetaCM->Write();
  EMthetaCM->Write();
  PthetaCM->Write();
  PimthetaCM->Write();

  EPphi->Write();
  EMphi->Write();
  Pphi->Write();
  Pimphi->Write();
    
  EPMass2_4pi->Write();
  EMMass3_4pi->Write();
  PMass14_4pi->Write();
  PimMass9_4pi->Write();

  MissingMass->Write();
  MissingMass1->Write();
  MissingMass2->Write();
  MissingMass3->Write();
  MissingMass4->Write();
  MissingMass5->Write();
  MissingMass6->Write();
   
  EMthmom3_4pi->Write();
  //  EMVerX3_4pi->Write();
  //  EMVerY3_4pi->Write();
  //  EMVerZ3_4pi->Write();
      
  EMmomX3_4pi->Write();
  EMmomY3_4pi->Write();
  EMmomZ3_4pi->Write();
  EMMomtot3_4pi->Write(); 
		
  EPthmom2_4pi->Write();
  //  EPVerX2_4pi->Write();
  //  EPVerY2_4pi->Write();
  //  EPVerZ2_4pi->Write();
      
  EPmomX2_4pi->Write();
  EPmomY2_4pi->Write();
  EPmomZ2_4pi->Write();
  EPMomtot2_4pi->Write(); 
		
  Pthmom14_4pi->Write();
  PVerX14_4pi->Write();
  PVerY14_4pi->Write();
  PVerZ14_4pi->Write();
      
  PmomX14_4pi->Write();
  PmomY14_4pi->Write();
  PmomZ14_4pi->Write();
  PMomtot14_4pi->Write(); 
		
  Pimthmom9_4pi->Write();
  //  PimVerX9_4pi->Write();
  //  PimVerY9_4pi->Write();
  //  PimVerZ9_4pi->Write();
      
  PimmomX9_4pi->Write();
  PimmomY9_4pi->Write();
  PimmomZ9_4pi->Write();
  PimMomtot9_4pi->Write(); 


  Pi0thmom7_4pi->Write();
  Pi0Mass7_4pi->Write();       
  Pi0momX7_4pi->Write();
  Pi0momY7_4pi->Write();
  Pi0momZ7_4pi->Write();
  Pi0Momtot7_4pi->Write();
  Pi0theta->Write();
  Pi0thetaCM->Write();
  Pi0phi->Write();
		      
  Pi0VerZ7_4pi->Write();
  
  ALLMass->Write();
  EpEm_OA->Write();
  
    f->Write();
    f->Close();
  
}
