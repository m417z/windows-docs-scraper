typedef struct _D3DDDICB_SUBMITCOMMAND {
  D3DGPU_VIRTUAL_ADDRESS      Commands;
  UINT                        CommandLength;
  D3DDDICB_SUBMITCOMMANDFLAGS Flags;
  UINT                        BroadcastContextCount;
  HANDLE                      BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  VOID                        *pPrivateDriverData;
  UINT                        PrivateDriverDataSize;
  UINT                        NumPrimaries;
  D3DKMT_HANDLE               WrittenPrimaries[D3DDDI_MAX_WRITTEN_PRIMARIES];
  D3DDDI_MARKERLOGTYPE        MarkerLogType;
  UINT                        RenderCBSequence;
  union {
    struct {
      UINT FirstAPISequenceNumberHigh;
      UINT CompletedAPISequenceNumberLow0Size;
      UINT CompletedAPISequenceNumberLow1Size;
      UINT BegunAPISequenceNumberLow0Size;
      UINT BegunAPISequenceNumberLow1Size;
    };
    UINT BatchedMarkerDataCount;
  };
  union {
    struct {
      const UINT *pCompletedAPISequenceNumberLow0;
      const UINT *pCompletedAPISequenceNumberLow1;
      const UINT *pBegunAPISequenceNumberLow0;
      const UINT *pBegunAPISequenceNumberLow1;
    };
    const D3DDDI_BATCHEDMARKERDATA *pBatchedMarkerData;
  };
  UINT                        Reserved;
  UINT                        NumHistoryBuffers;
  D3DKMT_HANDLE               *HistoryBufferArray;
  HANDLE                      hSyncToken;
  void                        *pReserved;
} D3DDDICB_SUBMITCOMMAND;