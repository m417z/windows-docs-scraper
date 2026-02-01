struct RILPOSITIONINFO_V2 {
  DWORD                  cbSize;
  DWORD                  dwSystemType;
  RILPOSITIONINFOGSM     stGSMServingCellInfo;
  RILPOSITIONINFOUMTS    stUMTSServingCellInfo;
  RILPOSITIONINFOTDSCDMA stTDSCDMAServingCellInfo;
  RILPOSITIONINFOLTE     stLTEServingCellInfo;
  DWORD                  dwCntGSMNMR;
  RILGSMNMR              rgNMR[15];
  DWORD                  dwCntUMTSMRL;
  RILUMTSMRL             ruMRL[15];
  DWORD                  dwCntTDSCDMAMRL;
  RILTDSCDMAMRL          rtMRL[15];
  DWORD                  dwCntEUTRAMRL;
  RILEUTRAMRL            reMRL[15];
  DWORD                  dwCntC2KMRL;
  RILC2KMRL              rc2kMRL[12];
};