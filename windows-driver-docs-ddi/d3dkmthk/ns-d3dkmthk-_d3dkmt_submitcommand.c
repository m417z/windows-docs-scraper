typedef struct _D3DKMT_SUBMITCOMMAND {
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS Commands;
  UINT                                  CommandLength;
  D3DKMT_SUBMITCOMMANDFLAGS             Flags;
  D3DKMT_ALIGN64 ULONGLONG              PresentHistoryToken;
  UINT                                  BroadcastContextCount;
  D3DKMT_HANDLE                         BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  VOID                                  *pPrivateDriverData;
  UINT                                  PrivateDriverDataSize;
  UINT                                  NumPrimaries;
  D3DKMT_HANDLE                         WrittenPrimaries[D3DDDI_MAX_WRITTEN_PRIMARIES];
  UINT                                  NumHistoryBuffers;
  D3DKMT_HANDLE                         *HistoryBufferArray;
} D3DKMT_SUBMITCOMMAND;