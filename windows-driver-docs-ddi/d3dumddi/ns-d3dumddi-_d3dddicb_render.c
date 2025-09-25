typedef struct _D3DDDICB_RENDER {
  UINT                     CommandLength;
  UINT                     CommandOffset;
  UINT                     NumAllocations;
  UINT                     NumPatchLocations;
  VOID                     *pNewCommandBuffer;
  UINT                     NewCommandBufferSize;
  D3DDDI_ALLOCATIONLIST    *pNewAllocationList;
  UINT                     NewAllocationListSize;
  D3DDDI_PATCHLOCATIONLIST *pNewPatchLocationList;
  UINT                     NewPatchLocationListSize;
  D3DDDICB_RENDERFLAGS     Flags;
  HANDLE                   hContext;
  UINT                     BroadcastContextCount;
  HANDLE                   BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  ULONG                    QueuedBufferCount;
  D3DGPU_VIRTUAL_ADDRESS   NewCommandBuffer;
  VOID                     *pPrivateDriverData;
  UINT                     PrivateDriverDataSize;
  D3DDDI_MARKERLOGTYPE     MarkerLogType;
  UINT                     RenderCBSequence;
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
} D3DDDICB_RENDER;