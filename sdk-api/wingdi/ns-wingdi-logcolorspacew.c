typedef struct tagLOGCOLORSPACEW {
  DWORD         lcsSignature;
  DWORD         lcsVersion;
  DWORD         lcsSize;
  LCSCSTYPE     lcsCSType;
  LCSGAMUTMATCH lcsIntent;
  CIEXYZTRIPLE  lcsEndpoints;
  DWORD         lcsGammaRed;
  DWORD         lcsGammaGreen;
  DWORD         lcsGammaBlue;
  WCHAR         lcsFilename[MAX_PATH];
} LOGCOLORSPACEW, *LPLOGCOLORSPACEW;