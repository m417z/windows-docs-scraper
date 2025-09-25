typedef struct _D3DDDIARG_QUERYAUTHENICATEDCHANNEL {
  [in]     UINT       InputSize;
  [in]     const VOID *pInputData;
  [in]     UINT       OutputSize;
  [in/out] VOID       *pOutputData;
} D3DDDIARG_QUERYAUTHENTICATEDCHANNEL;