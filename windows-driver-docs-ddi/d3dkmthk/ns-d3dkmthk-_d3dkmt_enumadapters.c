typedef struct _D3DKMT_ENUMADAPTERS {
  [in] ULONG              NumAdapters;
       D3DKMT_ADAPTERINFO Adapters[MAX_ENUM_ADAPTERS];
} D3DKMT_ENUMADAPTERS;