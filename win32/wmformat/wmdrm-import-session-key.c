typedef struct WMDRM_IMPORT_SESSION_KEY {
  DWORD dwKeyType;
  DWORD cbKey;
  BYTE  rgbKey[1];
} ;