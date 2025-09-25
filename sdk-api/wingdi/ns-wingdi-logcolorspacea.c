typedef struct tagLOGCOLORSPACEA {
  DWORD         lcsSignature;
  DWORD         lcsVersion;
  DWORD         lcsSize;
  LCSCSTYPE     lcsCSType;
  LCSGAMUTMATCH lcsIntent;
  CIEXYZTRIPLE  lcsEndpoints;
  DWORD         lcsGammaRed;
  DWORD         lcsGammaGreen;
  DWORD         lcsGammaBlue;
  CHAR          lcsFilename[MAX_PATH];
} LOGCOLORSPACEA, *LPLOGCOLORSPACEA;