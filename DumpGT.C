#include<stdio.h>
#include <iostream>
#include <stdlib.h>  

using std::cout;
using std::endl;

void DumpGT(int MaxBX=100,int option=0,bool isverbose=false){

  TString filename;
  TString folder;
  if(option==0) {folder="inputfiles/inputHIFW"; filename="JetsHI";}
  if(option==1) {folder="inputfiles/ttbar_2_5February"; filename="ttbar_2_MP7.txt";}
  if(option==2) {folder="inputfiles/ttbar_2_5February"; filename="GTDump_RCTInput_ttbar_2_FromP5.txt";}
  if(option==3) {folder="/afs/cern.ch/user/g/ginnocen/public/MP7testsP5"; filename="tx_summary_100events_GTlike";}

  FILE *fp = fopen(Form("%s/%s.txt",folder.Data(),filename.Data()),"read");
  if(!fp) std::cout<<"FILE NOT FOUND"<<std::endl;

  int counter=0;

  char central_l[10];
  char central_r[10];
  char forward_l[10];
  char forward_r[10];
  char dummy[10];
  char everything[10];

  int intcentral_l[10000];
  int intcentral_r[10000];
  int intforward_l[10000];
  int intforward_r[10000];
  int intindex[10000];


  char nall[10];
  //while(fscanf(fp,"%s %s %s %s %s %s %s %s %s",dummy,central_l,central_r,forward_l,forward_r,everything,everything,everything,everything)!=EOF) {
  while(fscanf(fp,"%s %s %s %s",central_l,central_r,forward_l,forward_r)!=EOF) {
    //intindex[counter]=(int)strtol(dummy, NULL, 16);
    intcentral_l[counter]=(int)strtol(central_l, NULL, 16);
    intcentral_r[counter]=(int)strtol(central_r, NULL, 16);
    intforward_l[counter]=(int)strtol(forward_l, NULL, 16);
    intforward_r[counter]=(int)strtol(forward_r, NULL, 16);

    counter++;
  }
  int mycounter=0;

  TH1F*hPtCentral=new TH1F("hPtCentral","hPtCentral",300,0,300);
  TH1F*hPtForward=new TH1F("hPtForward","hPtForward",300,0,300);
  TH1F*hPtAllJets=new TH1F("hPtAllJets","hPtAllJets",300,0,300);
  TH1F*hMaxPtAllJets=new TH1F("hMaxPtAllJets","hMaxPtAllJets",300,0,300);

  TH1F*hPtCentralHw=new TH1F("hPtCentralHw","hPtCentralHw",300,0,300);
  TH1F*hPtForwardHw=new TH1F("hPtForwardHw","hPtForwardHw",300,0,300);
  TH1F*hPtAllJetsHw=new TH1F("hPtAllJetsHw","hPtAllJetsHw",300,0,300);
  TH1F*hMaxPtAllJetsHw=new TH1F("hMaxPtAllJetsHw","hMaxPtAllJetsHw",300,0,300);

  int centralpt[4];
  int forwardpt[4];
  int centralptHw[4];
  int forwardptHw[4];
  int i=0;

  int isjetsabove16=0;
  int isjetsabove32=0;
  int isjetsabove52=0;
  int isjetsabove68=0;
  int isjetsabove92=0;
  int isjetsabove128=0;

  int counterBX=0;


  for (int iBX=0;iBX<MaxBX;iBX++){

    int maxPtAllJet=-999;

    int counter_jetsabove16=0;
    int counter_jetsabove32=0;
    int counter_jetsabove52=0;
    int counter_jetsabove68=0;
    int counter_jetsabove92=0;
    int counter_jetsabove128=0;    

    i=2*iBX;
    counterBX++;

    centralpt[0]=(intcentral_l[i]&0x3F)*4;
    centralpt[1]=(intcentral_r[i]&0x3F)*4;
    centralpt[2]=(intcentral_l[i+1]&0x3F)*4;
    centralpt[3]=(intcentral_r[i+1]&0x3F)*4;

    forwardpt[0]=(intforward_l[i]&0x3F)*4;
    forwardpt[1]=(intforward_r[i]&0x3F)*4;
    forwardpt[2]=(intforward_l[i+1]&0x3F)*4;
    forwardpt[3]=(intforward_r[i+1]&0x3F)*4;

    centralptHw[0]=(intcentral_l[i]&0x3F);
    centralptHw[1]=(intcentral_r[i]&0x3F);
    centralptHw[2]=(intcentral_l[i+1]&0x3F);
    centralptHw[3]=(intcentral_r[i+1]&0x3F);

    forwardptHw[0]=(intforward_l[i]&0x3F);
    forwardptHw[1]=(intforward_r[i]&0x3F);
    forwardptHw[2]=(intforward_l[i+1]&0x3F);
    forwardptHw[3]=(intforward_r[i+1]&0x3F);


    for (int m=0;m<4;m++){

      if(centralpt[m]>16.) counter_jetsabove16++;
      if(forwardpt[m]>16.) counter_jetsabove16++;

      if(centralpt[m]>32.) counter_jetsabove32++;
      if(forwardpt[m]>32.) counter_jetsabove32++;

      if(centralpt[m]>52.) counter_jetsabove52++;
      if(forwardpt[m]>52.) counter_jetsabove52++;

      if(centralpt[m]>68.) counter_jetsabove68++;
      if(forwardpt[m]>68.) counter_jetsabove68++;

      if(centralpt[m]>92.) counter_jetsabove92++;
      if(forwardpt[m]>92.) counter_jetsabove92++;

      if(centralpt[m]>128.) counter_jetsabove128++;
      if(forwardpt[m]>128.) counter_jetsabove128++;




    }

    if(counter_jetsabove16>0)isjetsabove16++;
    if(counter_jetsabove32>0)isjetsabove32++;
    if(counter_jetsabove52>0)isjetsabove52++;
    if(counter_jetsabove68>0)isjetsabove68++;
    if(counter_jetsabove92>0)isjetsabove92++;
    if(counter_jetsabove128>0)isjetsabove128++;

    if(isverbose){
      std::cout<<"*************** BX number="<<iBX<<" ***************"<<std::endl; 
      std::cout<<std::hex<<"central_l[0]="<<intcentral_l[i]<<std::endl;
      std::cout<<std::hex<<"central_r[0]="<<intcentral_r[i]<<std::endl;
      std::cout<<std::hex<<"central_l[1]="<<intcentral_l[i+1]<<std::endl;
      std::cout<<std::hex<<"central_r[1]="<<intcentral_r[i+1]<<std::endl;
      std::cout<<std::hex<<"forward_l[0]="<<intforward_l[i]<<std::endl;
      std::cout<<std::hex<<"forward_r[0]="<<intforward_r[i]<<std::endl;
      std::cout<<std::hex<<"forward_l[1]="<<intforward_l[i+1]<<std::endl;
      std::cout<<std::hex<<"forward_r[1]="<<intforward_r[i+1]<<std::endl;


      std::cout<<"central rank 0 (GeV)="<<std::dec<<centralpt[0]<<std::endl;
      std::cout<<"central rank 1 (GeV)="<<std::dec<<centralpt[1]<<std::endl;
      std::cout<<"central rank 2 (GeV)="<<std::dec<<centralpt[2]<<std::endl;
      std::cout<<"central rank 3 (GeV)="<<std::dec<<centralpt[3]<<std::endl;
      std::cout<<"forward rank 0 (GeV)="<<std::dec<<forwardpt[0]<<std::endl;
      std::cout<<"forward rank 1 (GeV)="<<std::dec<<forwardpt[1]<<std::endl;
      std::cout<<"forward rank 2 (GeV)="<<std::dec<<forwardpt[2]<<std::endl;
      std::cout<<"forward rank 3 (GeV)="<<std::dec<<forwardpt[3]<<std::endl;

    }    

    for (int jetindex=0; jetindex<4;jetindex++){

      hPtCentral->Fill(centralpt[jetindex]);
      hPtForward->Fill(forwardpt[jetindex]);
      hPtAllJets->Fill(centralpt[jetindex]);
      hPtAllJets->Fill(forwardpt[jetindex]);

      hPtCentralHw->Fill(centralptHw[jetindex]);
      hPtForwardHw->Fill(forwardptHw[jetindex]);
      hPtAllJetsHw->Fill(centralptHw[jetindex]);
      hPtAllJetsHw->Fill(forwardptHw[jetindex]);

      if(centralpt[jetindex]>maxPtAllJet) maxPtAllJet=centralpt[jetindex];
      if(forwardpt[jetindex]>maxPtAllJet) maxPtAllJet=forwardpt[jetindex];

    }

    hMaxPtAllJets->Fill(maxPtAllJet);    
  }


  TCanvas*canvas=new TCanvas("canvas","canvas",1400,1400);
  canvas->Divide(2,2);
  canvas->cd(1);
  hPtCentral->GetXaxis()->SetTitle("GeV");
  hPtCentral->GetYaxis()->SetTitle("Central jets");
  hPtCentral->Draw();
  canvas->cd(2);
  hPtForward->GetYaxis()->SetTitle("Forward jets");
  hPtForward->GetXaxis()->SetTitle("GeV");
  hPtForward->Draw();
  canvas->cd(3);
  hPtAllJets->GetYaxis()->SetTitle("Forward+Central jets");
  hPtAllJets->GetXaxis()->SetTitle("GeV");
  hPtAllJets->Draw();
  canvas->cd(4);
  hMaxPtAllJets->GetYaxis()->SetTitle("Highest pt central+forward jet");
  hMaxPtAllJets->GetXaxis()->SetTitle("GeV");
  hMaxPtAllJets->Draw();


  if(counterBX=!MaxBX)cout<<"error, you didnt run on the right number of BX"<<endl;
  cout<<"number of BX analyzed="<<MaxBX<<endl;
  cout<<"number of BX with a jet above 16="<<isjetsabove16<<endl;
  cout<<"number of BX with a jet above 32="<<isjetsabove32<<endl;
  cout<<"number of BX with a jet above 52="<<isjetsabove52<<endl;
  cout<<"number of BX with a jet above 68="<<isjetsabove68<<endl;
  cout<<"number of BX with a jet above 92="<<isjetsabove92<<endl;
  cout<<"number of BX with a jet above 128="<<isjetsabove128<<endl;

  fclose(fp);

  canvas->SaveAs(Form("Plots/%s.pdf",filename.Data()));

  TFile*fout=new TFile(Form("Results/%s.root",filename.Data()),"recreate");
  fout->cd();
  hPtCentral->Write();
  hPtForward->Write();
  hPtAllJets->Write();
  hMaxPtAllJets->Write();
  hPtCentralHw->Write();
  hPtForwardHw->Write();
  hPtAllJetsHw->Write();
  hMaxPtAllJetsHw->Write();

}
