typedef struct _MF_SIGNATURE {
  DWORD dwSignVer;
  DWORD cbSign;
  BYTE  rgSign[1];
} MF_SIGNATURE;