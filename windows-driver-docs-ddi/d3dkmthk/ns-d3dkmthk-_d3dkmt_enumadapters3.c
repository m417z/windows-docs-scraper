typedef struct _D3DKMT_ENUMADAPTERS3 {
  [in]     D3DKMT_ENUMADAPTERS_FILTER Filter;
  [in/out] ULONG                      NumAdapters;
  [out]    D3DKMT_ADAPTERINFO         *pAdapters;
} D3DKMT_ENUMADAPTERS3;