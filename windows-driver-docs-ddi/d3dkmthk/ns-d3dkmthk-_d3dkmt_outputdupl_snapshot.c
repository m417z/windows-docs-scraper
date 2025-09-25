typedef struct _D3DKMT_OUTPUTDUPL_SNAPSHOT {
  UINT                          Size;
  UINT                          SessionProcessCount;
  UINT                          SessionActiveConnectionsCount;
  UINT                          NumVidPnSources;
  UINT                          NumOutputDuplContexts;
  UINT                          Padding;
  OUTPUTDUPL_CONTEXT_DEBUG_INFO OutputDuplDebugInfos[0];
} D3DKMT_OUTPUTDUPL_SNAPSHOT;