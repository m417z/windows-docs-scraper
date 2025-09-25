typedef struct _D3DDDICB_SUBMITCOMMANDTOHWQUEUE {
  [in] HANDLE                               hHwQueue;
       UINT64                               HwQueueProgressFenceId;
       D3DGPU_VIRTUAL_ADDRESS               Commands;
       UINT                                 CommandLength;
       D3DDDICB_SUBMITCOMMANDTOHWQUEUEFLAGS Flags;
       UINT                                 PrivateDriverDataSize;
       VOID                                 *pPrivateDriverData;
       UINT                                 NumPrimaries;
       const D3DKMT_HANDLE                  *WrittenPrimaries;
} D3DDDICB_SUBMITCOMMANDTOHWQUEUE;