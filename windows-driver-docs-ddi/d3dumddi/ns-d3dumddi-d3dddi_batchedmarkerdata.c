typedef struct _D3DDDI_BATCHEDMARKERDATA {
  HANDLE     hRTCommandListHandle;
  UINT       FirstAPISequenceNumberHigh;
  UINT       CompletedAPISequenceNumberLowSize;
  const UINT *pCompletedAPISequenceNumberLow;
} D3DDDI_BATCHEDMARKERDATA;