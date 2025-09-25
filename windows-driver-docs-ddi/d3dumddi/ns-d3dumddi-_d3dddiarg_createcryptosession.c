typedef struct _D3DDDIARG_CREATECRYPTOSESSION {
  [in]     GUID   CryptoType;
           GUID   DecodeProfile;
  [in/out] HANDLE hCryptoSession;
} D3DDDIARG_CREATECRYPTOSESSION;