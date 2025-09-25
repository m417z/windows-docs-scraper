typedef struct _D3DDDIARG_GETPITCH {
  [in]  HANDLE hCryptoSession;
  [in]  HANDLE hResource;
  [in]  UINT   SubResourceIndex;
  [out] UINT   Pitch;
} D3DDDIARG_GETPITCH;