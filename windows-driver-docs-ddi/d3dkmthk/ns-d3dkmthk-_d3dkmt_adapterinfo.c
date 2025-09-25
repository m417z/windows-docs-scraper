typedef struct _D3DKMT_ADAPTERINFO {
  D3DKMT_HANDLE hAdapter;
  LUID          AdapterLuid;
  ULONG         NumOfSources;
  BOOL          bPrecisePresentRegionsPreferred;
} D3DKMT_ADAPTERINFO;