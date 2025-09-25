typedef struct _DXGKARG_SUBMITCOMMAND {
  union {
    HANDLE hDevice;
    HANDLE hContext;
  };
  UINT                           DmaBufferSegmentId;
  PHYSICAL_ADDRESS               DmaBufferPhysicalAddress;
  UINT                           DmaBufferSize;
  UINT                           DmaBufferSubmissionStartOffset;
  UINT                           DmaBufferSubmissionEndOffset;
  VOID                           *pDmaBufferPrivateData;
  UINT                           DmaBufferPrivateDataSize;
  UINT                           DmaBufferPrivateDataSubmissionStartOffset;
  UINT                           DmaBufferPrivateDataSubmissionEndOffset;
  UINT                           SubmissionFenceId;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DDDI_FLIPINTERVAL_TYPE       FlipInterval;
  DXGK_SUBMITCOMMANDFLAGS        Flags;
  UINT                           EngineOrdinal;
  D3DGPU_VIRTUAL_ADDRESS         DmaBufferVirtualAddress;
  UINT                           NodeOrdinal;
} DXGKARG_SUBMITCOMMAND;