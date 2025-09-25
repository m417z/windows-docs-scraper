typedef struct _DXGKARG_SETSCHEDULINGLOGBUFFER {
  UINT                       NodeOrdinal;
  UINT                       EngineOrdinal;
  UINT                       NumberOfEntries;
  DXGK_SCHEDULING_LOG_BUFFER *LogBufferCpuVa;
  D3DGPU_VIRTUAL_ADDRESS     LogBufferGpuVa;
  UINT                       InterruptEntry;
} DXGKARG_SETSCHEDULINGLOGBUFFER;