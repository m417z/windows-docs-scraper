typedef struct RILSENDDTMFPARAMS {
  DWORD dwExecutor;
  char  szDTMF[256];
  DWORD dwDigitOnTimeMs;
  DWORD dwDigitOffTimeMs;
} RILSENDDTMFPARAMS, *LPRILSENDDTMFPARAMS;