struct RILPOSITIONINFO_V2 {
  DWORD                  cbSize;
  DWORD                  dwSystemType;
  RILPOSITIONINFOGSM     stGSMServingCellInfo;
  RILPOSITIONINFOUMTS    stUMTSServingCellInfo;
  RILPOSITIONINFOTDSCDMA stTDSCDMAServingCellInfo;
  RILPOSITIONINFOLTE     stLTEServingCellInfo;
  DWORD                  dwCntGSMNMR;
  RILGSMNMR              rgNMR[MAX_GSMPOS_COUNT_OF_NMR];
  DWORD                  dwCntUMTSMRL;
  ruMRL                  RILUMTSMRL[MAX_UMTSPOS_COUNT_OF_MRL];
  DWORD                  dwCntTDSCDMAMRL;
  rtMRL                  RILTDSCDMAMRL[MAX_TDSCDMAPOS_COUNT_OF_MRL];
  DWORD                  dwCntEUTRAMRL;
  RILEUTRAMRL            reMRL[MAX_EUTRAPOS_COUNT_OF_MRL];
  DWORD                  dwCntC2KMRL;
  RILC2KMRL              rc2kMRL[MAX_C2KPOS_COUNT_OF_MRL];
};