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

void PlotResultsEmulator(TString suffix="egammas"){

  TString inputfileEmulator="OutputEmulator/fileoutput.root";
  TString inputfileUnpacker="OutputUnpacker/fileoutput.root";

  TFile*foutEmulator=new TFile(inputfileEmulator.Data(),"read");
  TFile*foutUnpacker=new TFile(inputfileUnpacker.Data(),"read");

  TH1D *hwPtEmulator = (TH1D*)foutEmulator->Get(Form("hwPt_%s",suffix.Data()));
  TH1D *hwEtaEmulator= (TH1D*)foutEmulator->Get(Form("hwEta_%s",suffix.Data()));
  TH1D *hwPhiEmulator= (TH1D*)foutEmulator->Get(Form("hwPhi_%s",suffix.Data()));
  TH1D *hwQualEmulator= (TH1D*)foutEmulator->Get(Form("hwQual_%s",suffix.Data()));
  TH1D *hwIsoEmulator= (TH1D*)foutEmulator->Get(Form("hwIso_%s",suffix.Data()));
  TH1D *hptEmulator= (TH1D*)foutEmulator->Get(Form("hpt_%s",suffix.Data()));
  TH1D *hetaEmulator= (TH1D*)foutEmulator->Get(Form("heta_%s",suffix.Data()));
  TH1D *hphiEmulator= (TH1D*)foutEmulator->Get(Form("hphi_%s",suffix.Data()));

  TH1D *hwPtUnpacker = (TH1D*)foutUnpacker->Get(Form("hwPt_%s",suffix.Data()));
  TH1D *hwEtaUnpacker= (TH1D*)foutUnpacker->Get(Form("hwEta_%s",suffix.Data()));
  TH1D *hwPhiUnpacker= (TH1D*)foutUnpacker->Get(Form("hwPhi_%s",suffix.Data()));
  TH1D *hwQualUnpacker= (TH1D*)foutUnpacker->Get(Form("hwQual_%s",suffix.Data()));
  TH1D *hwIsoUnpacker= (TH1D*)foutUnpacker->Get(Form("hwIso_%s",suffix.Data()));
  TH1D *hptUnpacker= (TH1D*)foutUnpacker->Get(Form("hpt_%s",suffix.Data()));
  TH1D *hetaUnpacker= (TH1D*)foutUnpacker->Get(Form("heta_%s",suffix.Data()));
  TH1D *hphiUnpacker= (TH1D*)foutUnpacker->Get(Form("hphi_%s",suffix.Data()));


  TCanvas*canvas=new TCanvas("canvas","canvas",1500,1000);  
  canvas->Divide(4,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  if(suffix!="etsums") hwPtEmulator->GetXaxis()->SetRangeUser(0.,50.);
  else hwPtEmulator->GetXaxis()->SetRangeUser(0.,700.);
  hwPtEmulator->SetLineWidth(3);
  hwPtEmulator->Draw();
  hwPtUnpacker->SetLineColor(2);
  hwPtUnpacker->Draw("same");
  canvas->cd(2);
  //canvas_2->SetLogy();
  hwEtaEmulator->GetXaxis()->SetRangeUser(0.,20.);
  hwEtaEmulator->SetLineWidth(3);
  hwEtaEmulator->Draw();
  hwEtaUnpacker->SetLineColor(2);
  hwEtaUnpacker->Draw("same");
  canvas->cd(3);
  //canvas_3->SetLogy();
  hwPhiEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hwPhiEmulator->SetLineWidth(3);
  hwPhiEmulator->Draw();
  hwPhiUnpacker->SetLineColor(2);
  hwPhiUnpacker->Draw("same");
  canvas->cd(4);
  //canvas_4->SetLogy();
  hwQualEmulator->GetXaxis()->SetRangeUser(-10.,9.);
  hwQualEmulator->SetLineWidth(3);
  hwQualEmulator->Draw();
  hwQualUnpacker->SetLineColor(2);
  hwQualUnpacker->Draw("same");

  canvas->cd(5);
  //canvas_5->SetLogy();
  hwIsoEmulator->GetXaxis()->SetRangeUser(0.,4.);
  hwIsoEmulator->SetLineWidth(3);
  hwIsoEmulator->Draw();
  hwIsoUnpacker->SetLineColor(2);
  hwIsoUnpacker->Draw("same");
  canvas->cd(6);
  //canvas_6->SetLogy();
  hptEmulator->GetXaxis()->SetRangeUser(0.,100.);
  hptEmulator->SetLineWidth(3);
  hptEmulator->Draw();
  hptUnpacker->SetLineColor(2);
  hptUnpacker->Draw("same");
  canvas->cd(7);
  //canvas_7->SetLogy();
  hetaEmulator->GetXaxis()->SetRangeUser(-6.,6.);
  hetaEmulator->SetLineWidth(3);
  hetaEmulator->Draw();
  hetaUnpacker->SetLineColor(2);
  hetaUnpacker->Draw("same");
  canvas->cd(8);
  //canvas_8->SetLogy();
  hphiEmulator->GetXaxis()->SetRangeUser(-6.,6.);
  hphiEmulator->SetLineWidth(3);
  hphiEmulator->Draw();
  hphiUnpacker->SetLineColor(2);
  hphiUnpacker->Draw("same");

  canvas->SaveAs(Form("PlotsEmulatorVsUnpacker/canvas_%s.pdf",suffix.Data()));

}


