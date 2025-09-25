typedef struct _D3DKMT_HYBRID_LIST {
           D3DKMT_GPU_PREFERENCE_QUERY_STATE State;
  [in,opt] LUID                              AdapterLuid;
           BOOL                              bUserPreferenceQuery;
           D3DKMT_GPU_PREFERENCE_QUERY_TYPE  QueryType;
} D3DKMT_HYBRID_LIST;