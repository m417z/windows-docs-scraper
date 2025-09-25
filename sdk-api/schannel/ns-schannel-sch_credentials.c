typedef struct _SCH_CREDENTIALS {
  DWORD           dwVersion;
  DWORD           dwCredFormat;
  DWORD           cCreds;
  PCCERT_CONTEXT  *paCred;
  HCERTSTORE      hRootStore;
  DWORD           cMappers;
  _HMAPPER        **aphMappers;
  struct          _HMAPPER;
  DWORD           dwSessionLifespan;
  DWORD           dwFlags;
  DWORD           cTlsParameters;
  PTLS_PARAMETERS pTlsParameters;
} SCH_CREDENTIALS, *PSCH_CREDENTIALS;