typedef struct _D3DKMT_QUERY_PHYSICAL_ADAPTER_PNP_KEY {
  UINT                PhysicalAdapterIndex;
  D3DKMT_PNP_KEY_TYPE PnPKeyType;
  WCHAR               *pDest;
  UINT                *pCchDest;
} D3DKMT_QUERY_PHYSICAL_ADAPTER_PNP_KEY;