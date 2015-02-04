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

  TString inputfile;
  if(option==1) inputfile="OutputEmulator/fileoutput.root";
  if(option==2) inputfile="OutputUnpacker/fileoutput.root";

  TFile*fout=new TFile(inputfile.Data(),"read");

  TH1D *hlegacyregion_et = (TH1D*)fout->Get("hlegacyregion_et");
  TH1D *hlegacyregion_gctEta= (TH1D*)fout->Get("hlegacyregion_gctEta");
  TH1D *hlegacyregion_gctPhi= (TH1D*)fout->Get("hlegacyregion_gctPhi");
  TH1D *hlegacyregion_crate= (TH1D*)fout->Get("hlegacyregion_crate");
  TH1D *hlegacyregion_card= (TH1D*)fout->Get("hlegacyregion_card");
  TH1D *hlegacyregion_index= (TH1D*)fout->Get("hlegacyregion_index");    

  TCanvas*canvas=new TCanvas("canvas","canvas",1500,600);  
  canvas->Divide(3,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  hlegacyregion_et->GetXaxis()->SetRangeUser(0.,50.);
  hlegacyregion_et->Draw();
  canvas->cd(2);
  //canvas_2->SetLogy();
  hlegacyregion_gctEta->GetXaxis()->SetRangeUser(0.,20.);
  hlegacyregion_gctEta->Draw();
  canvas->cd(3);
  //canvas_3->SetLogy();
  hlegacyregion_gctPhi->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_gctPhi->Draw();
  canvas->cd(4);
  //canvas_4->SetLogy();
  hlegacyregion_crate->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_crate->Draw();
  canvas->cd(5);
  //canvas_5->SetLogy();
  hlegacyregion_card->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_card->Draw();
  canvas->cd(6);
  //canvas_6->SetLogy();
  hlegacyregion_index->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyregion_index->Draw();


  if(option==1) canvas->SaveAs("PlotsEmulator/canvas_RCTRegions.pdf");
  if(option==2) canvas->SaveAs("PlotsUnpacker/canvas_RCTRegions.pdf");

}

void PlotResultsEmulatorRCTEmcands(int option=1){

  TString inputfile;
  if(option==1) inputfile="OutputEmulator/fileoutput.root";
  if(option==2) inputfile="OutputUnpacker/fileoutput.root";

  TFile*fout=new TFile(inputfile.Data(),"read");

  TH1D *hlegacyemcand_rank = (TH1D*)fout->Get("hlegacyemcand_rank");
  TH1D *hlegacyemcand_regionEta= (TH1D*)fout->Get("hlegacyemcand_regionEta");
  TH1D *hlegacyemcand_regionPhi= (TH1D*)fout->Get("hlegacyemcand_regionPhi");
  TH1D *hlegacyemcand_crate= (TH1D*)fout->Get("hlegacyemcand_crate");
  TH1D *hlegacyemcand_card= (TH1D*)fout->Get("hlegacyemcand_card");
  TH1D *hlegacyemcand_index= (TH1D*)fout->Get("hlegacyemcand_index");  
  TH1D *hlegacyemcand_iso= (TH1D*)fout->Get("hlegacyemcand_iso");  


  TCanvas*canvas=new TCanvas("canvas","canvas",1800,600);  
  canvas->Divide(4,2);

  canvas->cd(1);
  //canvas_1->SetLogy();
  hlegacyemcand_rank->GetXaxis()->SetRangeUser(0.,50.);
  hlegacyemcand_rank->Draw();
  canvas->cd(2);
  //canvas_2->SetLogy();
  hlegacyemcand_regionEta->GetXaxis()->SetRangeUser(0.,20.);
  hlegacyemcand_regionEta->Draw();
  canvas->cd(3);
  //canvas_3->SetLogy();
  hlegacyemcand_regionPhi->GetXaxis()->SetRangeUser(0.,30.);
  hlegacyemcand_regionPhi->Draw();
  canvas->cd(4);
  //canvas_4->SetLogy();
  hlegacyemcand_crate->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_crate->Draw();
  canvas->cd(5);
  //canvas_5->SetLogy();
  hlegacyemcand_card->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_card->Draw();
  canvas->cd(6);
  //canvas_5->SetLogy();
  hlegacyemcand_index->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_index->Draw();
  canvas->cd(7);
  //canvas_5->SetLogy();
  hlegacyemcand_iso->GetXaxis()->SetRangeUser(0.,4.);
  hlegacyemcand_iso->Draw();

  if(option==1) canvas->SaveAs("PlotsEmulator/canvas_emcands.pdf");
  if(option==2) canvas->SaveAs("PlotsUnpacker/canvas_emcands.pdf");


}
