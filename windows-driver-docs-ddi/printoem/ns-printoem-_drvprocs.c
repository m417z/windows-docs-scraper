typedef struct _DRVPROCS {
  PFN_DrvWriteSpoolBuf       DrvWriteSpoolBuf;
  PFN_DrvXMoveTo             DrvXMoveTo;
  PFN_DrvYMoveTo             DrvYMoveTo;
  PFN_DrvGetDriverSetting    DrvGetDriverSetting;
  PFN_DrvGetStandardVariable BGetStandardVariable;
  PFN_DrvUnidriverTextOut    DrvUnidriverTextOut;
  PFN_DrvWriteAbortBuf       DrvWriteAbortBuf;
} DRVPROCS, *PDRVPROCS;