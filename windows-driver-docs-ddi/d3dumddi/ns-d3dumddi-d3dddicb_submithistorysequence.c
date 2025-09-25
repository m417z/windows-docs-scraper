typedef struct _D3DDDICB_SUBMITHISTORYSEQUENCE {
  HANDLE               hHwQueue;
  UINT64               HwQueueProgressFenceId;
  UINT                 NumHistoryBuffers;
  const VOID           **HistoryBufferAddresses;
  const UINT           *HistoryBufferSizes;
  UINT                 PrecisionBits;
  D3DDDI_MARKERLOGTYPE MarkerLogType;
  UINT                 RenderCBSequence;
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
  UINT                 TimestampArrayStride;
  D3DKMT_HANDLE        HistorySequenceCompletionSyncObject;
  UINT64               HistorySequenceCompletionFenceValue;
} D3DDDICB_SUBMITHISTORYSEQUENCE;