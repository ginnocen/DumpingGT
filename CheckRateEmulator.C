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

const int Njets = 8;
const int Negammas = 8;
const int Ntaus = 4;
const int Netsums = 4;
const int Nregions = 396;
const int Nemcands = 144;

void CheckRateEmulator(int option=1){

  TString l1_input;
  if (option==1) l1_input= "/afs/cern.ch/user/g/ginnocen/CMSSW_7_3_0_pre2/src/Analyzers/L1UpgradeAnalyzer/test/prova.root";
  if (option==2) l1_input = "/afs/cern.ch/work/r/richard/public/CMSSW_7_4_0_pre5-84-g59d4752-L1UpgradeAnalyzer.root";
  TFile *lFile = TFile::Open(l1_input.Data());
  TTree *l1Tree = (TTree*)lFile->Get("L1UpgradeAnalyzer/L1UpgradeTree");


  TH1F*hwPt_jets=new TH1F("hwPt_jets","hwPt_jets",300,0,300);
  TH1F*hwEta_jets=new TH1F("hwEta_jets","hwEta_jets",300,0,300);
  TH1F*hwPhi_jets=new TH1F("hwPhi_jets","hwPhi_jets",300,0,300);
  TH1F*hwQual_jets=new TH1F("hwQual_jets","hwQual_jets",300,0,300);
  TH1F*hwIso_jets=new TH1F("hwIso_jets","hwIso_jets",300,0,300);
  TH1F*hpt_jets=new TH1F("hpt_jets","hpt_jets",300,0,300);
  TH1F*heta_jets=new TH1F("heta_jets","heta_jets",20,-10,10);
  TH1F*hphi_jets=new TH1F("hphi_jets","hphi_jets",20,-10,10);

  TH1F*hwPt_egammas=new TH1F("hwPt_egammas","hwPt_egammas",300,0,300);
  TH1F*hwEta_egammas=new TH1F("hwEta_egammas","hwEta_egammas",300,0,300);
  TH1F*hwPhi_egammas=new TH1F("hwPhi_egammas","hwPhi_egammas",300,0,300);
  TH1F*hwQual_egammas=new TH1F("hwQual_egammas","hwQual_egammas",300,0,300);
  TH1F*hwIso_egammas=new TH1F("hwIso_egammas","hwIso_egammas",300,0,300);
  TH1F*hpt_egammas=new TH1F("hpt_egammas","hpt_egammas",300,0,300);
  TH1F*heta_egammas=new TH1F("heta_egammas","heta_egammas",20,-10,10);
  TH1F*hphi_egammas=new TH1F("hphi_egammas","hphi_egammas",20,-10,10);

  TH1F*hwPt_taus=new TH1F("hwPt_taus","hwPt_taus",300,0,300);
  TH1F*hwEta_taus=new TH1F("hwEta_taus","hwEta_taus",300,0,300);
  TH1F*hwPhi_taus=new TH1F("hwPhi_taus","hwPhi_taus",300,0,300);
  TH1F*hwQual_taus=new TH1F("hwQual_taus","hwQual_taus",300,0,300);
  TH1F*hwIso_taus=new TH1F("hwIso_taus","hwIso_taus",300,0,300);
  TH1F*hpt_taus=new TH1F("hpt_taus","hpt_taus",300,0,300);
  TH1F*heta_taus=new TH1F("heta_taus","heta_taus",20,-10,10);
  TH1F*hphi_taus=new TH1F("hphi_taus","hphi_taus",20,-10,10);

  TH1F*hwPt_etsums=new TH1F("hwPt_etsums","hwPt_etsums",300,0,300);
  TH1F*hwEta_etsums=new TH1F("hwEta_etsums","hwEta_etsums",300,0,300);
  TH1F*hwPhi_etsums=new TH1F("hwPhi_etsums","hwPhi_etsums",300,0,300);
  TH1F*hwQual_etsums=new TH1F("hwQual_etsums","hwQual_etsums",300,0,300);
  TH1F*hwIso_etsums=new TH1F("hwIso_etsums","hwIso_etsums",300,0,300);
  TH1F*hpt_etsums=new TH1F("hpt_etsums","hpt_etsums",300,0,300);
  TH1F*heta_etsums=new TH1F("heta_etsums","heta_etsums",20,-10,10);
  TH1F*hphi_etsums=new TH1F("hphi_etsums","hphi_etsums",20,-10,10);

  TH1F*hlegacyregion_et=new TH1F("hlegacyregion_et","hlegacyregion_et",300,0,300);
  TH1F*hlegacyregion_gctEta=new TH1F("hlegacyregion_gctEta","hlegacyregion_gctEta",300,0,300);
  TH1F*hlegacyregion_gctPhi=new TH1F("hlegacyregion_gctPhi","hlegacyregion_gctPhi",300,0,300);
  TH1F*hlegacyregion_crate=new TH1F("hlegacyregion_crate","hlegacyregion_crate",300,0,300);
  TH1F*hlegacyregion_card=new TH1F("hlegacyregion_card","hlegacyregion_card",300,0,300);
  TH1F*hlegacyregion_index=new TH1F("hlegacyregion_index","hlegacyregion_index",300,0,300);

  TH1F*hlegacyemcand_rank=new TH1F("hlegacyemcand_rank","hlegacyemcand_rank",300,0,300);
  TH1F*hlegacyemcand_regionEta=new TH1F("hlegacyemcand_regionEta","hlegacyemcand_regionEta",300,0,300);
  TH1F*hlegacyemcand_regionPhi=new TH1F("hlegacyemcand_regionPhi","hlegacyemcand_regionPhi",300,0,300);
  TH1F*hlegacyemcand_crate=new TH1F("hlegacyemcand_crate","hlegacyemcand_crate",300,0,300);
  TH1F*hlegacyemcand_card=new TH1F("hlegacyemcand_card","hlegacyemcand_card",300,0,300);
  TH1F*hlegacyemcand_index=new TH1F("hlegacyemcand_index","hlegacyemcand_index",300,0,300);
  TH1F*hlegacyemcand_iso=new TH1F("hlegacyemcand_iso","hlegacyemcand_iso",300,0,300);

  TH1F*hlegacyemcandiso_rank=new TH1F("hlegacyemcandiso_rank","hlegacyemcandiso_rank",300,0,300);
  TH1F*hlegacyemcandiso_regionEta=new TH1F("hlegacyemcandiso_regionEta","hlegacyemcandiso_regionEta",300,0,300);
  TH1F*hlegacyemcandiso_regionPhi=new TH1F("hlegacyemcandiso_regionPhi","hlegacyemcandiso_regionPhi",300,0,300);
  TH1F*hlegacyemcandiso_crate=new TH1F("hlegacyemcandiso_crate","hlegacyemcandiso_crate",300,0,300);
  TH1F*hlegacyemcandiso_card=new TH1F("hlegacyemcandiso_card","hlegacyemcandiso_card",300,0,300);
  TH1F*hlegacyemcandiso_index=new TH1F("hlegacyemcandiso_index","hlegacyemcandiso_index",300,0,300);
  TH1F*hlegacyemcandiso_iso=new TH1F("hlegacyemcandiso_iso","hlegacyemcandiso_iso",300,0,300);


  TH1F*hlegacyemcandnoniso_rank=new TH1F("hlegacyemcandnoniso_rank","hlegacyemcandnoniso_rank",300,0,300);
  TH1F*hlegacyemcandnoniso_regionEta=new TH1F("hlegacyemcandnoniso_regionEta","hlegacyemcandnoniso_regionEta",300,0,300);
  TH1F*hlegacyemcandnoniso_regionPhi=new TH1F("hlegacyemcandnoniso_regionPhi","hlegacyemcandnoniso_regionPhi",300,0,300);
  TH1F*hlegacyemcandnoniso_crate=new TH1F("hlegacyemcandnoniso_crate","hlegacyemcandnoniso_crate",300,0,300);
  TH1F*hlegacyemcandnoniso_card=new TH1F("hlegacyemcandnoniso_card","hlegacyemcandnoniso_card",300,0,300);
  TH1F*hlegacyemcandnoniso_index=new TH1F("hlegacyemcandnoniso_index","hlegacyemcandnoniso_index",300,0,300);
  TH1F*hlegacyemcandnoniso_iso=new TH1F("hlegacyemcandnoniso_iso","hlegacyemcandnoniso_iso",300,0,300);


  Int_t l1_event, l1_run;
  Int_t l1_num;

  Int_t jet_hwPt[Njets];
  Int_t jet_hwPhi[Njets];
  Int_t jet_hwEta[Njets];
  Int_t jet_hwQual[Njets];
  Int_t jet_hwIso[Njets];
  Double_t jet_pt[Njets];
  Double_t jet_eta[Njets];
  Double_t jet_phi[Njets];

  Int_t egamma_hwPt[Negammas];
  Int_t egamma_hwPhi[Negammas];
  Int_t egamma_hwEta[Negammas];
  Int_t egamma_hwQual[Negammas];
  Int_t egamma_hwIso[Negammas];
  Double_t egamma_pt[Negammas];
  Double_t egamma_eta[Negammas];
  Double_t egamma_phi[Negammas];

  Int_t tau_hwPt[Ntaus];
  Int_t tau_hwPhi[Ntaus];
  Int_t tau_hwEta[Ntaus];
  Int_t tau_hwQual[Ntaus];
  Int_t tau_hwIso[Ntaus];
  Double_t tau_pt[Ntaus];
  Double_t tau_eta[Ntaus];
  Double_t tau_phi[Ntaus];

  Int_t etsum_hwPt[Netsums];
  Int_t etsum_hwPhi[Netsums];
  Int_t etsum_hwEta[Netsums];
  Int_t etsum_hwQual[Netsums];
  Int_t etsum_hwIso[Netsums];
  Int_t etsum_type[Netsums];
  Double_t etsum_pt[Netsums];
  Double_t etsum_eta[Netsums];
  Double_t etsum_phi[Netsums];


  Int_t legacyregion_et[Nregions];
  Int_t legacyregion_gctEta[Nregions];
  Int_t legacyregion_gctPhi[Nregions];
  Int_t legacyregion_crate[Nregions];
  Int_t legacyregion_card[Nregions];
  Int_t legacyregion_index[Nregions];

  Int_t legacyemcand_rank[Nemcands];
  Int_t legacyemcand_regionEta[Nemcands];
  Int_t legacyemcand_regionPhi[Nemcands];
  Int_t legacyemcand_crate[Nemcands];
  Int_t legacyemcand_card[Nemcands];
  Int_t legacyemcand_index[Nemcands];
  Int_t legacyemcand_iso[Nemcands];



  l1Tree->SetBranchAddress("event",&l1_event);
  l1Tree->SetBranchAddress("run",&l1_run);

  l1Tree->SetBranchAddress("jet_hwPt",jet_hwPt);
  l1Tree->SetBranchAddress("jet_hwPhi",jet_hwPhi);
  l1Tree->SetBranchAddress("jet_hwEta",jet_hwEta);
  l1Tree->SetBranchAddress("jet_hwQual",jet_hwQual);
  l1Tree->SetBranchAddress("jet_hwIso",jet_hwIso);
  l1Tree->SetBranchAddress("jet_pt",jet_pt);
  l1Tree->SetBranchAddress("jet_eta",jet_eta);
  l1Tree->SetBranchAddress("jet_phi",jet_phi);

  l1Tree->SetBranchAddress("tau_hwPt",tau_hwPt);
  l1Tree->SetBranchAddress("tau_hwPhi",tau_hwPhi);
  l1Tree->SetBranchAddress("tau_hwEta",tau_hwEta);
  l1Tree->SetBranchAddress("tau_hwQual",tau_hwQual);
  l1Tree->SetBranchAddress("tau_hwIso",tau_hwIso);
  l1Tree->SetBranchAddress("tau_pt",tau_pt);
  l1Tree->SetBranchAddress("tau_eta",tau_eta);
  l1Tree->SetBranchAddress("tau_phi",tau_phi);

  l1Tree->SetBranchAddress("egamma_hwPt",egamma_hwPt);
  l1Tree->SetBranchAddress("egamma_hwPhi",egamma_hwPhi);
  l1Tree->SetBranchAddress("egamma_hwEta",egamma_hwEta);
  l1Tree->SetBranchAddress("egamma_hwQual",egamma_hwQual);
  l1Tree->SetBranchAddress("egamma_hwIso",egamma_hwIso);
  l1Tree->SetBranchAddress("egamma_pt",egamma_pt);
  l1Tree->SetBranchAddress("egamma_eta",egamma_eta);
  l1Tree->SetBranchAddress("egamma_phi",egamma_phi);

  l1Tree->SetBranchAddress("etsum_hwPt",etsum_hwPt);
  l1Tree->SetBranchAddress("etsum_hwPhi",etsum_hwPhi);
  l1Tree->SetBranchAddress("etsum_hwEta",etsum_hwEta);
  l1Tree->SetBranchAddress("etsum_hwQual",etsum_hwQual);
  l1Tree->SetBranchAddress("etsum_hwIso",etsum_hwIso);
  l1Tree->SetBranchAddress("etsum_type",etsum_type);
  l1Tree->SetBranchAddress("etsum_pt",etsum_pt);
  l1Tree->SetBranchAddress("etsum_eta",etsum_eta);
  l1Tree->SetBranchAddress("etsum_phi",etsum_phi);



  l1Tree->SetBranchAddress("legacyregion_et",legacyregion_et);
  l1Tree->SetBranchAddress("legacyregion_gctEta",legacyregion_gctEta);
  l1Tree->SetBranchAddress("legacyregion_gctPhi",legacyregion_gctPhi);
  l1Tree->SetBranchAddress("legacyregion_crate",legacyregion_crate);
  l1Tree->SetBranchAddress("legacyregion_card",legacyregion_card);
  l1Tree->SetBranchAddress("legacyregion_index",legacyregion_index);

  l1Tree->SetBranchAddress("legacyemcand_rank",legacyemcand_rank);
  l1Tree->SetBranchAddress("legacyemcand_regionEta",legacyemcand_regionEta);
  l1Tree->SetBranchAddress("legacyemcand_regionPhi",legacyemcand_regionPhi);
  l1Tree->SetBranchAddress("legacyemcand_crate",legacyemcand_crate);
  l1Tree->SetBranchAddress("legacyemcand_card",legacyemcand_card);
  l1Tree->SetBranchAddress("legacyemcand_index",legacyemcand_index);
  l1Tree->SetBranchAddress("legacyemcand_iso",legacyemcand_iso);

  int isjetsabove16=0;
  int isjetsabove32=0;
  int isjetsabove52=0;
  int isjetsabove68=0;
  int isjetsabove92=0;
  int isjetsabove128=0;

  int isegammasabove5=0;
  int isegammasabove10=0;
  int isegammasabove20=0;
  int isegammasabove25=0;
  int isegammasabove30=0;
  int isegammasabove35=0;
  int isegammasabove40=0;

  int isisoegammasabove18=0;
  int isisoegammasabove20=0;
  int isisoegammasabove22=0;
  int isisoegammasabove25=0;
  int isisoegammasabove28=0;
  int isisoegammasabove30=0;


  int istausabove16=0;
  int istausabove32=0;
  int istausabove52=0;
  int istausabove68=0;
  int istausabove92=0;
  int istausabove128=0;

  int isetsumsabove16=0;
  int isetsumsabove32=0;
  int isetsumsabove52=0;
  int isetsumsabove68=0;
  int isetsumsabove92=0;
  int isetsumsabove128=0;


  Long64_t l_entries = l1Tree->GetEntries();
  std::cout<<"number of events="<<l_entries<<std::endl;

  for(Long64_t j = 0; j < l_entries; ++j){
    l1Tree->GetEntry(j);

    int counter_jetsabove16=0;
    int counter_jetsabove32=0;
    int counter_jetsabove52=0;
    int counter_jetsabove68=0;
    int counter_jetsabove92=0;
    int counter_jetsabove128=0;

    int counter_egammasabove5=0;
    int counter_egammasabove10=0;
    int counter_egammasabove20=0;
    int counter_egammasabove25=0;
    int counter_egammasabove30=0;
    int counter_egammasabove35=0;
    int counter_egammasabove40=0;

    int counter_isoegammasabove18=0;
    int counter_isoegammasabove20=0;
    int counter_isoegammasabove22=0;
    int counter_isoegammasabove25=0;
    int counter_isoegammasabove28=0;
    int counter_isoegammasabove30=0;

    int counter_tausabove16=0;
    int counter_tausabove32=0;
    int counter_tausabove52=0;
    int counter_tausabove68=0;
    int counter_tausabove92=0;
    int counter_tausabove128=0;

    int counter_etsumsabove16=0;
    int counter_etsumsabove32=0;
    int counter_etsumsabove52=0;
    int counter_etsumsabove68=0;
    int counter_etsumsabove92=0;
    int counter_etsumsabove128=0;


    for (int i=0;i<8;i++){


      if((jet_hwPt[i]*4)>16.)  counter_jetsabove16++;
      if((jet_hwPt[i]*4)>32.)  counter_jetsabove32++;
      if((jet_hwPt[i]*4)>52.)  counter_jetsabove52++;
      if((jet_hwPt[i]*4)>68.)  counter_jetsabove68++;
      if((jet_hwPt[i]*4)>92.)  counter_jetsabove92++;
      if((jet_hwPt[i]*4)>128.) counter_jetsabove128++;

      hwPt_jets->Fill((jet_hwPt[i]));
      hwEta_jets->Fill((jet_hwEta[i]));
      hwPhi_jets->Fill((jet_hwPhi[i]));
      hwQual_jets->Fill((jet_hwQual[i]));
      hwIso_jets->Fill((jet_hwIso[i]));
      hpt_jets->Fill((jet_pt[i]));
      heta_jets->Fill((jet_eta[i]));
      hphi_jets->Fill((jet_phi[i]));

      if((egamma_hwPt[i]*4)>5.)  counter_egammasabove5++;
      if((egamma_hwPt[i]*4)>10.)  counter_egammasabove10++;
      if((egamma_hwPt[i]*4)>20.)  counter_egammasabove20++;
      if((egamma_hwPt[i]*4)>25.)  counter_egammasabove25++;
      if((egamma_hwPt[i]*4)>30.)  counter_egammasabove30++;
      if((egamma_hwPt[i]*4)>35.) counter_egammasabove35++;
      if((egamma_hwPt[i]*4)>40.) counter_egammasabove40++;


      if((egamma_hwPt[i]*4)>18. && egamma_hwIso[i]==1)  counter_isoegammasabove18++;
      if((egamma_hwPt[i]*4)>20. && egamma_hwIso[i]==1)  counter_isoegammasabove20++;
      if((egamma_hwPt[i]*4)>22. && egamma_hwIso[i]==1)  counter_isoegammasabove22++;
      if((egamma_hwPt[i]*4)>25. && egamma_hwIso[i]==1)  counter_isoegammasabove25++;
      if((egamma_hwPt[i]*4)>28. && egamma_hwIso[i]==1)  counter_isoegammasabove28++;
      if((egamma_hwPt[i]*4)>30. && egamma_hwIso[i]==1)  counter_isoegammasabove30++;


      hwPt_egammas->Fill((egamma_hwPt[i]));
      hwEta_egammas->Fill((egamma_hwEta[i]));
      hwPhi_egammas->Fill((egamma_hwPhi[i]));
      hwQual_egammas->Fill((egamma_hwQual[i]));
      hwIso_egammas->Fill((egamma_hwIso[i]));
      hpt_egammas->Fill((egamma_pt[i]));
      heta_egammas->Fill((egamma_eta[i]));
      hphi_egammas->Fill((egamma_phi[i]));      
    }

    for (int i=0;i<4;i++){

      if((tau_hwPt[i]*4)>16.)  counter_tausabove16++;
      if((tau_hwPt[i]*4)>32.)  counter_tausabove32++;
      if((tau_hwPt[i]*4)>52.)  counter_tausabove52++;
      if((tau_hwPt[i]*4)>68.)  counter_tausabove68++;
      if((tau_hwPt[i]*4)>92.)  counter_tausabove92++;
      if((tau_hwPt[i]*4)>128.) counter_tausabove128++;

      hwPt_taus->Fill((tau_hwPt[i]));
      hwEta_taus->Fill((tau_hwEta[i]));
      hwPhi_taus->Fill((tau_hwPhi[i]));
      hwQual_taus->Fill((tau_hwQual[i]));
      hwIso_taus->Fill((tau_hwIso[i]));
      hpt_taus->Fill((tau_pt[i]));
      heta_taus->Fill((tau_eta[i]));
      hphi_taus->Fill((tau_phi[i]));

      if((etsum_hwPt[i]*4)>16.)  counter_etsumsabove16++;
      if((etsum_hwPt[i]*4)>32.)  counter_etsumsabove32++;
      if((etsum_hwPt[i]*4)>52.)  counter_etsumsabove52++;
      if((etsum_hwPt[i]*4)>68.)  counter_etsumsabove68++;
      if((etsum_hwPt[i]*4)>92.)  counter_etsumsabove92++;
      if((etsum_hwPt[i]*4)>128.) counter_etsumsabove128++;

      //if(etsum_type[i]!=3){
      hwPt_etsums->Fill((etsum_hwPt[i]));
      hwEta_etsums->Fill((etsum_hwEta[i]));
      hwPhi_etsums->Fill((etsum_hwPhi[i]));
      hwQual_etsums->Fill((etsum_hwQual[i]));
      hwIso_etsums->Fill((etsum_hwIso[i]));
      hpt_etsums->Fill((etsum_pt[i]));
      heta_etsums->Fill((etsum_eta[i]));
      hphi_etsums->Fill((etsum_phi[i]));
      //}

    }



    for (int i=0;i<Nregions;i++){

      hlegacyregion_et->Fill((legacyregion_et[i]));
      hlegacyregion_gctEta->Fill((legacyregion_gctEta[i]));
      hlegacyregion_gctPhi->Fill((legacyregion_gctPhi[i]));
      hlegacyregion_crate->Fill((legacyregion_crate[i]));
      hlegacyregion_card->Fill((legacyregion_card[i]));
      hlegacyregion_index->Fill((legacyregion_index[i]));

    }

    for (int i=0;i<Nemcands;i++){

      hlegacyemcand_rank->Fill((legacyemcand_rank[i]));
      hlegacyemcand_regionEta->Fill((legacyemcand_regionEta[i]));
      hlegacyemcand_regionPhi->Fill((legacyemcand_regionPhi[i]));
      hlegacyemcand_crate->Fill((legacyemcand_crate[i]));
      hlegacyemcand_card->Fill((legacyemcand_card[i]));
      hlegacyemcand_index->Fill((legacyemcand_index[i]));
      hlegacyemcand_iso->Fill((legacyemcand_iso[i]));

     if(legacyemcand_iso[i]==1){
      hlegacyemcandiso_rank->Fill((legacyemcand_rank[i]));
      hlegacyemcandiso_regionEta->Fill((legacyemcand_regionEta[i]));
      hlegacyemcandiso_regionPhi->Fill((legacyemcand_regionPhi[i]));
      hlegacyemcandiso_crate->Fill((legacyemcand_crate[i]));
      hlegacyemcandiso_card->Fill((legacyemcand_card[i]));
      hlegacyemcandiso_index->Fill((legacyemcand_index[i]));
      hlegacyemcandiso_iso->Fill((legacyemcand_iso[i]));
     }
     
     if(legacyemcand_iso[i]==0){
      hlegacyemcandnoniso_rank->Fill((legacyemcand_rank[i]));
      hlegacyemcandnoniso_regionEta->Fill((legacyemcand_regionEta[i]));
      hlegacyemcandnoniso_regionPhi->Fill((legacyemcand_regionPhi[i]));
      hlegacyemcandnoniso_crate->Fill((legacyemcand_crate[i]));
      hlegacyemcandnoniso_card->Fill((legacyemcand_card[i]));
      hlegacyemcandnoniso_index->Fill((legacyemcand_index[i]));
      hlegacyemcandnoniso_iso->Fill((legacyemcand_iso[i]));
     }



    }



    if(counter_jetsabove16>0)isjetsabove16++;
    if(counter_jetsabove32>0)isjetsabove32++;
    if(counter_jetsabove52>0)isjetsabove52++;
    if(counter_jetsabove68>0)isjetsabove68++;
    if(counter_jetsabove92>0)isjetsabove92++;
    if(counter_jetsabove128>0)isjetsabove128++;

    if(counter_egammasabove5>0)isegammasabove5++;
    if(counter_egammasabove10>0)isegammasabove10++;
    if(counter_egammasabove20>0)isegammasabove20++;
    if(counter_egammasabove25>0)isegammasabove25++;
    if(counter_egammasabove30>0)isegammasabove30++;
    if(counter_egammasabove35>0)isegammasabove35++;
    if(counter_egammasabove40>0)isegammasabove40++;

    if(counter_isoegammasabove18>0) isisoegammasabove18++;
    if(counter_isoegammasabove20>0) isisoegammasabove20++;
    if(counter_isoegammasabove22>0) isisoegammasabove22++;
    if(counter_isoegammasabove25>0) isisoegammasabove25++;
    if(counter_isoegammasabove28>0) isisoegammasabove28++;
    if(counter_isoegammasabove30>0) isisoegammasabove30++;

    if(counter_tausabove16>0)istausabove16++;
    if(counter_tausabove32>0)istausabove32++;
    if(counter_tausabove52>0)istausabove52++;
    if(counter_tausabove68>0)istausabove68++;
    if(counter_tausabove92>0)istausabove92++;
    if(counter_tausabove128>0)istausabove128++;

    if(counter_etsumsabove16>0)isetsumsabove16++;
    if(counter_etsumsabove32>0)isetsumsabove32++;
    if(counter_etsumsabove52>0)isetsumsabove52++;
    if(counter_etsumsabove68>0)isetsumsabove68++;
    if(counter_etsumsabove92>0)isetsumsabove92++;
    if(counter_etsumsabove128>0)isetsumsabove128++;

  }

  cout<<"--------------- jets --------------"<<endl;
  cout<<"number of events with a jet above 16="<<isjetsabove16<<endl;
  cout<<"number of events with a jet above 32="<<isjetsabove32<<endl;
  cout<<"number of events with a jet above 52="<<isjetsabove52<<endl;
  cout<<"number of events with a jet above 68="<<isjetsabove68<<endl;
  cout<<"number of events with a jet above 92="<<isjetsabove92<<endl;
  cout<<"number of events with a jet above 128="<<isjetsabove128<<endl;


  cout<<"--------------- egammas --------------"<<endl;
  cout<<"number of events with a egamma above 5="<<isegammasabove5<<endl;
  cout<<"number of events with a egamma above 10="<<isegammasabove10<<endl;
  cout<<"number of events with a egamma above 20="<<isegammasabove20<<endl;
  cout<<"number of events with a egamma above 25="<<isegammasabove25<<endl;
  cout<<"number of events with a egamma above 30="<<isegammasabove30<<endl;
  cout<<"number of events with a egamma above 35="<<isegammasabove35<<endl;
  cout<<"number of events with a egamma above 40="<<isegammasabove40<<endl;

  cout<<"--------------- iso egammas --------------"<<endl;
  cout<<"number of events with a egamma above 18="<<isisoegammasabove18<<endl;
  cout<<"number of events with a egamma above 20="<<isisoegammasabove20<<endl;
  cout<<"number of events with a egamma above 22="<<isisoegammasabove22<<endl;
  cout<<"number of events with a egamma above 25="<<isisoegammasabove25<<endl;
  cout<<"number of events with a egamma above 28="<<isisoegammasabove28<<endl;
  cout<<"number of events with a egamma above 30="<<isisoegammasabove30<<endl;


  cout<<"--------------- taus --------------"<<endl;
  cout<<"number of events with a tau above 16="<<istausabove16<<endl;
  cout<<"number of events with a tau above 32="<<istausabove32<<endl;
  cout<<"number of events with a tau above 52="<<istausabove52<<endl;
  cout<<"number of events with a tau above 68="<<istausabove68<<endl;
  cout<<"number of events with a tau above 92="<<istausabove92<<endl;
  cout<<"number of events with a tau above 128="<<istausabove128<<endl;
  cout<<"--------------- etsums --------------"<<endl;
  cout<<"number of events with a etsum above 16="<<isetsumsabove16<<endl;
  cout<<"number of events with a etsum above 32="<<isetsumsabove32<<endl;
  cout<<"number of events with a etsum above 52="<<isetsumsabove52<<endl;
  cout<<"number of events with a etsum above 68="<<isetsumsabove68<<endl;
  cout<<"number of events with a etsum above 92="<<isetsumsabove92<<endl;
  cout<<"number of events with a etsum above 128="<<isetsumsabove128<<endl;


  TString fileout;
  if(option==1) fileout="OutputUnpacker/fileoutput.root";
  if(option==2) fileout="OutputEmulator/fileoutput.root";

  TFile*fout=new TFile(fileout.Data(),"recreate");
  fout->cd();

  hwPt_jets->Write();
  hwEta_jets->Write();
  hwPhi_jets->Write();
  hwQual_jets->Write();
  hwIso_jets->Write();
  hpt_jets->Write();
  heta_jets->Write();
  hphi_jets->Write();

  hwPt_egammas->Write();
  hwEta_egammas->Write();
  hwPhi_egammas->Write();
  hwQual_egammas->Write();
  hwIso_egammas->Write();
  hpt_egammas->Write();
  heta_egammas->Write();
  hphi_egammas->Write();

  hwPt_taus->Write();
  hwEta_taus->Write();
  hwPhi_taus->Write();
  hwQual_taus->Write();
  hwIso_taus->Write();
  hpt_taus->Write();
  heta_taus->Write();
  hphi_taus->Write();

  hwPt_etsums->Write();
  hwEta_etsums->Write();
  hwPhi_etsums->Write();
  hwQual_etsums->Write();
  hwIso_etsums->Write();
  hpt_etsums->Write();
  heta_etsums->Write();
  hphi_etsums->Write();

  hlegacyregion_et->Write();
  hlegacyregion_gctEta->Write();
  hlegacyregion_gctPhi->Write();
  hlegacyregion_crate->Write();
  hlegacyregion_card->Write();
  hlegacyregion_index->Write();

  hlegacyemcand_rank->Write();
  hlegacyemcand_regionEta->Write();
  hlegacyemcand_regionPhi->Write();
  hlegacyemcand_crate->Write();
  hlegacyemcand_card->Write();
  hlegacyemcand_index->Write();
  hlegacyemcand_iso->Write();
  
  hlegacyemcandiso_rank->Write();
  hlegacyemcandiso_regionEta->Write();
  hlegacyemcandiso_regionPhi->Write();
  hlegacyemcandiso_crate->Write();
  hlegacyemcandiso_card->Write();
  hlegacyemcandiso_index->Write();
  hlegacyemcandiso_iso->Write();

  hlegacyemcandnoniso_rank->Write();
  hlegacyemcandnoniso_regionEta->Write();
  hlegacyemcandnoniso_regionPhi->Write();
  hlegacyemcandnoniso_crate->Write();
  hlegacyemcandnoniso_card->Write();
  hlegacyemcandnoniso_index->Write();
  hlegacyemcandnoniso_iso->Write();


  fout->Close();
  delete fout;

}


