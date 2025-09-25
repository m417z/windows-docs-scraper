typedef struct _DXGK_START_INFO {
  ULONG RequiredDmaQueueEntry;
  GUID  AdapterGuid;
  LUID  AdapterLuid;
} DXGK_START_INFO, *PDXGK_START_INFO;