typedef struct tagEMRCREATECOLORSPACEW {
  EMR            emr;
  DWORD          ihCS;
  LOGCOLORSPACEW lcs;
  DWORD          dwFlags;
  DWORD          cbData;
  BYTE           Data[1];
} EMRCREATECOLORSPACEW, *PEMRCREATECOLORSPACEW;