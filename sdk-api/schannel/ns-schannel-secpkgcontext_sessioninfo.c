typedef struct _SecPkgContext_SessionInfo {
  DWORD dwFlags;
  DWORD cbSessionId;
  BYTE  rgbSessionId[32];
} SecPkgContext_SessionInfo, *PSecPkgContext_SessionInfo;