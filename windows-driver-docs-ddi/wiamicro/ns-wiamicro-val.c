typedef struct VAL {
  LONG      lVal;
  double    dblVal;
  GUID      *pGuid;
  PSCANINFO pScanInfo;
  HGLOBAL   handle;
  WCHAR     **ppButtonNames;
  HANDLE    *pHandle;
  LONG      lReserved;
  CHAR      szVal[MAX_ANSI_CHAR];
} VAL, *PVAL;