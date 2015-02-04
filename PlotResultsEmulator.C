#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TH1I.h>
#include <TH2I.h>
#include <TLatex.h>
#include <TGraph.h>
#include <TString.h>
#include <TLegendEntry.h>
#include <TGraphAsymmErrors.h>

#include <vector>
#include <iostream>
#include <map>

void PlotResultsEmulator(int option=1,TString suffix="jets"){

  TString inputfile;
  if(option==1) inputfile="OutputEmulator/fileoutput.root";
  if(option==2) inputfile="OutputUnpacker/fileoutput.root";

  TFile*fout=new TFile(inputfile.Data(),"read");

  TH1D *hwPt = (TH1D*)fout->Get(Form("hwPt_%s",suffix.Data()));
  TH1D *hwEta= (TH1D*)fout->Get(Form("hwEta_%s",suffix.Data()));
  TH1D *hwPhi= (TH1D*)fout->Get(Form("hwPhi_%s",suffix.Data()));
  TH1D *hwQual= (TH1D*)fout->Get(Form("hwQual_%s",suffix.Data()));
  TH1D *hwIso= (TH1D*)fout->Get(Form("hwIso_%s",suffix.Data()));
  TH1D *hpt= (TH1D*)fout->Get(Form("hpt_%s",suffix.Data()));
  TH1D *heta= (TH1D*)fout->Get(Form("heta_%s",suffix.Data()));
  TH1D *hphi= (TH1D*)fout->Get(Form("hphi_%s",suffix.Data()));


  TCanvas*canvas=new TCanvas("canvas","canvas",1500,1000);  
  canvas->Divide(4,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  if(suffix!="etsums") hwPt->GetXaxis()->SetRangeUser(0.,50.);
  else hwPt->GetXaxis()->SetRangeUser(0.,700.);
  hwPt->Draw();
  canvas->cd(2);
  //canvas_2->SetLogy();
  hwEta->GetXaxis()->SetRangeUser(0.,20.);
  hwEta->Draw();
  canvas->cd(3);
  //canvas_3->SetLogy();
  hwPhi->GetXaxis()->SetRangeUser(0.,30.);
  hwPhi->Draw();
  canvas->cd(4);
  //canvas_4->SetLogy();
  hwQual->GetXaxis()->SetRangeUser(0.,4.);
  hwQual->Draw();

  canvas->cd(5);
  //canvas_5->SetLogy();
  hwIso->GetXaxis()->SetRangeUser(0.,4.);
  hwIso->Draw();
  canvas->cd(6);
  //canvas_6->SetLogy();
  hpt->GetXaxis()->SetRangeUser(0.,100.);
  hpt->Draw();
  canvas->cd(7);
  //canvas_7->SetLogy();
  heta->GetXaxis()->SetRangeUser(-6.,6.);
  heta->Draw();
  canvas->cd(8);
  //canvas_8->SetLogy();
  hphi->GetXaxis()->SetRangeUser(-6.,6.);
  hphi->Draw();


  if(option==1) canvas->SaveAs(Form("PlotsEmulator/canvas_%s.pdf",suffix.Data()));
  if(option==2) canvas->SaveAs(Form("PlotsUnpacker/canvas_%s.pdf",suffix.Data()));

}


