typedef struct RILPOSITIONINFO_V1 {
  DWORD               cbSize;
  DWORD               dwSystemType;
  RILPOSITIONINFOGSM  stGSMServingCellInfo;
  RILPOSITIONINFOUMTS stUMTSServingCellInfo;
  RILPOSITIONINFOLTE  stLTEServingCellInfo;
  DWORD               dwCntGSMNMR;
  RILGSMNMR           rgNMR[15];
  DWORD               dwCntUMTSMRL;
  RILUMTSMRL          ruMRL[15];
  DWORD               dwCntEUTRAMRL;
  RILEUTRAMRL         reMRL[15];
  DWORD               dwCntC2KMRL;
  RILC2KMRL           rc2kMRL[12];
} RILPOSITIONINFO_V1, *LPRILPOSITIONINFO_V1;