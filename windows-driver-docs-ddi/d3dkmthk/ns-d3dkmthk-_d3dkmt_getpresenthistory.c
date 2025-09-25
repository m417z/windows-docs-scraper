typedef struct _D3DKMT_GETPRESENTHISTORY {
  [in]     D3DKMT_HANDLE              hAdapter;
  [in]     UINT                       ProvidedSize;
  [out]    UINT                       WrittenSize;
  [in/out] D3DKMT_PRESENTHISTORYTOKEN *pTokens;
  [out]    UINT                       NumTokens;
} D3DKMT_GETPRESENTHISTORY;