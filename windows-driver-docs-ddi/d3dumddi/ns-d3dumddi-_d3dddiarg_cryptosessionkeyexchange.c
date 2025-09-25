typedef struct _D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE {
  [in]     HANDLE hCryptoSession;
  [in/out] UINT   DataSize;
  [in/out] VOID   *pData;
} D3DDDIARG_CRYPTOSESSIONKEYEXCHANGE;