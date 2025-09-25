typedef struct _SCHANNEL_CRED {
  DWORD          dwVersion;
  DWORD          cCreds;
  PCCERT_CONTEXT *paCred;
  HCERTSTORE     hRootStore;
  DWORD          cMappers;
  _HMAPPER       **aphMappers;
  struct         _HMAPPER;
  DWORD          cSupportedAlgs;
  ALG_ID         *palgSupportedAlgs;
  DWORD          grbitEnabledProtocols;
  DWORD          dwMinimumCipherStrength;
  DWORD          dwMaximumCipherStrength;
  DWORD          dwSessionLifespan;
  DWORD          dwFlags;
  DWORD          dwCredFormat;
} SCHANNEL_CRED, *PSCHANNEL_CRED;