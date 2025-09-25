typedef struct _D3DDDIARG_STARTSESSIONKEYREFRESH {
  [in]     HANDLE hCryptoSession;
  [out]    VOID   *pRandomNumber;
  [in/out] UINT   RandomNumberSize;
} D3DDDIARG_STARTSESSIONKEYREFRESH;