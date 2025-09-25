typedef struct _DXGKARG_VALIDATESUBMITCOMMAND {
  D3DGPU_VIRTUAL_ADDRESS          Commands;
  UINT                            CommandLength;
  DXGK_VALIDATESUBMITCOMMANDFLAGS Flags;
  UINT                            ContextCount;
  HANDLE                          Context[D3DDDI_MAX_BROADCAST_CONTEXT];
  VOID                            *pPrivateDriverData;
  UINT                            PrivateDriverDataSize;
  UINT                            UmdPrivateDataSize;
  UINT64                          HwQueueProgressFenceId;
} DXGKARG_VALIDATESUBMITCOMMAND;