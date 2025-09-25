typedef struct _SecPkgContext_ConnectionInfo {
  DWORD  dwProtocol;
  ALG_ID aiCipher;
  DWORD  dwCipherStrength;
  ALG_ID aiHash;
  DWORD  dwHashStrength;
  ALG_ID aiExch;
  DWORD  dwExchStrength;
} SecPkgContext_ConnectionInfo, *PSecPkgContext_ConnectionInfo;