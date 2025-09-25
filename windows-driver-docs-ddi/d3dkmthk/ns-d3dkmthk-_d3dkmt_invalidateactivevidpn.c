typedef struct _D3DKMT_INVALIDATEACTIVEVIDPN {
  [in] D3DKMT_HANDLE hAdapter;
  [in] VOID          *pPrivateDriverData;
  [in] UINT          PrivateDriverDataSize;
} D3DKMT_INVALIDATEACTIVEVIDPN;