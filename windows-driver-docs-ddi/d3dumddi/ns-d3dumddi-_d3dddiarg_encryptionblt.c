typedef struct _D3DDDIARG_ENCRYPTIONBLT {
  [in]  HANDLE hCryptoSession;
  [in]  HANDLE hSrcResource;
  [in]  UINT   SrcSubResourceIndex;
  [in]  HANDLE hDstResource;
  [in]  UINT   DstSubResourceIndex;
  [in]  UINT   DstResourceSize;
  [out] VOID   *pIV;
} D3DDDIARG_ENCRYPTIONBLT;