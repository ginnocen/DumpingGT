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

void PlotResultsEmulatorRCTRegions(int option==1){

  TString inputfileEmulator="OutputEmulator/fileoutput.root";
  TString inputfileUnpacker="OutputUnpacker/fileoutput.root";

  TFile*foutEmulator=new TFile(inputfileEmulator.Data(),"read");
  TFile*foutUnpacker=new TFile(inputfileUnpacker.Data(),"read");

  TH1D *hlegacyregion_etEmulator = (TH1D*)foutEmulator->Get("hlegacyregion_et");
  TH1D *hlegacyregion_gctEtaEmulator= (TH1D*)foutEmulator->Get("hlegacyregion_gctEta");
  TH1D *hlegacyregion_gctPhiEmulator= (TH1D*)foutEmulator->Get("hlegacyregion_gctPhi");
  TH1D *hlegacyregion_crateEmulator= (TH1D*)foutEmulator->Get("hlegacyregion_crate");
  TH1D *hlegacyregion_cardEmulator= (TH1D*)foutEmulator->Get("hlegacyregion_card");
  TH1D *hlegacyregion_indexEmulator= (TH1D*)foutEmulator->Get("hlegacyregion_index");    

  TH1D *hlegacyregion_etUnpacker = (TH1D*)foutUnpacker->Get("hlegacyregion_et");
  TH1D *hlegacyregion_gctEtaUnpacker= (TH1D*)foutUnpacker->Get("hlegacyregion_gctEta");
  TH1D *hlegacyregion_gctPhiUnpacker= (TH1D*)foutUnpacker->Get("hlegacyregion_gctPhi");
  TH1D *hlegacyregion_crateUnpacker= (TH1D*)foutUnpacker->Get("hlegacyregion_crate");
  TH1D *hlegacyregion_cardUnpacker= (TH1D*)foutUnpacker->Get("hlegacyregion_card");
  TH1D *hlegacyregion_indexUnpacker= (TH1D*)foutUnpacker->Get("hlegacyregion_index");    

  TCanvas*canvas=new TCanvas("canvas","canvas",1500,600);  
  canvas->Divide(3,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  hlegacyregion_etEmulator->GetXaxis()->SetRangeUser(0.,50.);
  hlegacyregion_etEmulator->SetLineWidth(3);
  hlegacyregion_etEmulator->Draw();
  hlegacyregion_etUnpacker->SetLineColor(2);
  hlegacyregion_etUnpacker->Draw("same");
  canvas->cd(2);
  //canvas_2->SetLogy();
  hlegacyregion_gctEtaEmulator->GetXaxis()->SetRangeUser(0.,20.);
  hlegacyregion_gctEtaEmulator->SetLineWidth(3);
  hlegacyregion_gctEtaEmulator->Draw();
  hlegacyregion_gctEtaUnpacker->SetLineColor(2);
  hlegacyregion_gctEtaUnpacker->Draw("same");

  canvas->cd(3);
  //canvas_3->SetLogy();
  hlegacyregion_gctPhiEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_gctPhiEmulator->SetLineWidth(3);
  hlegacyregion_gctPhiEmulator->Draw();
  hlegacyregion_gctPhiUnpacker->SetLineColor(2);
  hlegacyregion_gctPhiUnpacker->Draw("same");

  canvas->cd(4);
  //canvas_4->SetLogy();
  hlegacyregion_crateEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_crateEmulator->SetLineWidth(3);
  hlegacyregion_crateEmulator->Draw();
  hlegacyregion_crateUnpacker->SetLineColor(2);
  hlegacyregion_crateUnpacker->Draw("same");

  canvas->cd(5);
  //canvas_5->SetLogy();
  hlegacyregion_cardEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_cardEmulator->SetLineWidth(3);
  hlegacyregion_cardEmulator->Draw();
  hlegacyregion_cardUnpacker->SetLineColor(2);
  hlegacyregion_cardUnpacker->Draw("same");

  canvas->cd(6);
  //canvas_6->SetLogy();
  hlegacyregion_indexEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_indexEmulator->SetLineWidth(3);
  hlegacyregion_indexEmulator->Draw();
  hlegacyregion_indexUnpacker->SetLineColor(2);
  hlegacyregion_indexUnpacker->Draw("same");

  canvas->SaveAs("PlotsEmulatorVsUnpacker/canvas_regions.pdf");

}

void PlotResultsEmulatorRCTEmcands(int option=1){

  TString inputfileEmulator="OutputEmulator/fileoutput.root";
  TString inputfileUnpacker="OutputUnpacker/fileoutput.root";

  TFile*foutEmulator=new TFile(inputfileEmulator.Data(),"read");
  TFile*foutUnpacker=new TFile(inputfileUnpacker.Data(),"read");

  TH1D *hlegacyemcand_rankEmulator = (TH1D*)foutEmulator->Get("hlegacyemcand_rank");
  TH1D *hlegacyemcand_regionEtaEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_regionEta");
  TH1D *hlegacyemcand_regionPhiEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_regionPhi");
  TH1D *hlegacyemcand_crateEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_crate");
  TH1D *hlegacyemcand_cardEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_card");
  TH1D *hlegacyemcand_indexEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_index");  
  TH1D *hlegacyemcand_isoEmulator= (TH1D*)foutEmulator->Get("hlegacyemcand_iso");  

  TH1D *hlegacyemcand_rankUnpacker = (TH1D*)foutUnpacker->Get("hlegacyemcand_rank");
  TH1D *hlegacyemcand_regionEtaUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_regionEta");
  TH1D *hlegacyemcand_regionPhiUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_regionPhi");
  TH1D *hlegacyemcand_crateUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_crate");
  TH1D *hlegacyemcand_cardUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_card");
  TH1D *hlegacyemcand_indexUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_index");  
  TH1D *hlegacyemcand_isoUnpacker= (TH1D*)foutUnpacker->Get("hlegacyemcand_iso");  


  TCanvas*canvas=new TCanvas("canvas","canvas",1800,600);  
  canvas->Divide(4,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  hlegacyemcand_rankEmulator->GetXaxis()->SetRangeUser(0.,50.);
  hlegacyemcand_rankEmulator->SetLineWidth(3);
  hlegacyemcand_rankEmulator->Draw();
  hlegacyemcand_rankUnpacker->SetLineColor(2);
  hlegacyemcand_rankUnpacker->Draw("same");

  canvas->cd(2);
  //canvas_2->SetLogy();
  hlegacyemcand_regionEtaEmulator->GetXaxis()->SetRangeUser(0.,20.);
  hlegacyemcand_regionEtaEmulator->SetLineWidth(3);
  hlegacyemcand_regionEtaEmulator->Draw();
  hlegacyemcand_regionEtaUnpacker->SetLineColor(2);
  hlegacyemcand_regionEtaUnpacker->Draw("same");

  canvas->cd(3);
  //canvas_3->SetLogy();
  hlegacyemcand_regionPhiEmulator->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyemcand_regionPhiEmulator->SetLineWidth(3);
  hlegacyemcand_regionPhiEmulator->Draw();
  hlegacyemcand_regionPhiUnpacker->SetLineColor(2);
  hlegacyemcand_regionPhiUnpacker->Draw("same");

  canvas->cd(4);
  //canvas_4->SetLogy();
  hlegacyemcand_crateEmulator->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_crateEmulator->SetLineWidth(3);
  hlegacyemcand_crateEmulator->Draw();
  hlegacyemcand_crateUnpacker->SetLineColor(2);
  hlegacyemcand_crateUnpacker->Draw("same");

  canvas->cd(5);
  //canvas_5->SetLogy();
  hlegacyemcand_cardEmulator->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_cardEmulator->SetLineWidth(3);
  hlegacyemcand_cardEmulator->Draw();
  hlegacyemcand_cardUnpacker->SetLineColor(2);
  hlegacyemcand_cardUnpacker->Draw("same");

  canvas->cd(6);
  //canvas_5->SetLogy();
  hlegacyemcand_indexEmulator->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_indexEmulator->SetLineWidth(3);
  hlegacyemcand_indexEmulator->Draw();
  hlegacyemcand_indexUnpacker->SetLineColor(2);
  hlegacyemcand_indexUnpacker->Draw("same");

  canvas->cd(7);
  //canvas_5->SetLogy();
  hlegacyemcand_isoEmulator->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_isoEmulator->SetLineWidth(3);
  hlegacyemcand_isoEmulator->Draw();
  hlegacyemcand_isoUnpacker->SetLineColor(2);
  hlegacyemcand_isoUnpacker->Draw("same");


  canvas->SaveAs("PlotsEmulatorVsUnpacker/canvas_emcands.pdf");


}
