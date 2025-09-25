typedef struct _ads_vlv {
  DWORD  dwBeforeCount;
  DWORD  dwAfterCount;
  DWORD  dwOffset;
  DWORD  dwContentCount;
  LPWSTR pszTarget;
  DWORD  dwContextIDLength;
  LPBYTE lpContextID;
} ADS_VLV, *PADS_VLV;