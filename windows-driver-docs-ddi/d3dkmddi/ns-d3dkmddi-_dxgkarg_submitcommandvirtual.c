typedef struct _DXGKARG_SUBMITCOMMANDVIRTUAL {
  HANDLE                         hContext;
  D3DGPU_VIRTUAL_ADDRESS         DmaBufferVirtualAddress;
  UINT                           DmaBufferSize;
  VOID                           *pDmaBufferPrivateData;
  UINT                           DmaBufferPrivateDataSize;
  UINT                           DmaBufferUmdPrivateDataSize;
  UINT                           SubmissionFenceId;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DDDI_FLIPINTERVAL_TYPE       FlipInterval;
  DXGK_SUBMITCOMMANDFLAGS        Flags;
  UINT                           EngineOrdinal;
  UINT                           NodeOrdinal;
} DXGKARG_SUBMITCOMMANDVIRTUAL;