typedef struct _D3DKMT_SUBMITCOMMANDTOHWQUEUE {
  D3DKMT_HANDLE                         hHwQueue;
  D3DKMT_ALIGN64 UINT64                 HwQueueProgressFenceId;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS CommandBuffer;
  UINT                                  CommandLength;
  UINT                                  PrivateDriverDataSize;
  VOID                                  *pPrivateDriverData;
  UINT                                  NumPrimaries;
  D3DKMT_HANDLE const                   *WrittenPrimaries;
} D3DKMT_SUBMITCOMMANDTOHWQUEUE;