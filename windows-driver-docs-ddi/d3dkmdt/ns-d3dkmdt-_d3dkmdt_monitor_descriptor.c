typedef struct _D3DKMDT_MONITOR_DESCRIPTOR {
  D3DKMDT_MONITOR_DESCRIPTOR_ID       Id;
  D3DKMDT_MONITOR_DESCRIPTOR_TYPE     Type;
  SIZE_T                              DataSize;
  VOID                                *pData;
  D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
} D3DKMDT_MONITOR_DESCRIPTOR;