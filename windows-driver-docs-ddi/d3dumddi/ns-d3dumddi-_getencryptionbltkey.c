typedef struct _GETENCRYPTIONBLTKEY {
  [in] HANDLE hCryptoSession;
  [in] VOID   *pReadBackKey;
  [in] UINT   KeySize;
} D3DDDIARG_GETENCRYPTIONBLTKEY;