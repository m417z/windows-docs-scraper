typedef struct _D3DKMT_PRESENT {
  union {
    [in] D3DKMT_HANDLE hDevice;
    [in] D3DKMT_HANDLE hContext;
  };
  [in] HWND                           hWindow;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] D3DKMT_HANDLE                  hSource;
  [in] D3DKMT_HANDLE                  hDestination;
  [in] UINT                           Color;
  [in] RECT                           DstRect;
  [in] RECT                           SrcRect;
  [in] UINT                           SubRectCnt;
  [in] const RECT                     *pSrcSubRects;
  [in] UINT                           PresentCount;
  [in] D3DDDI_FLIPINTERVAL_TYPE       FlipInterval;
  [in] D3DKMT_PRESENTFLAGS            Flags;
  [in] ULONG                          BroadcastContextCount;
       D3DKMT_HANDLE                  BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] HANDLE                         PresentLimitSemaphore;
  [in] D3DKMT_PRESENTHISTORYTOKEN     PresentHistoryToken;
       D3DKMT_PRESENT_RGNS            *pPresentRegions;
  union {
         D3DKMT_HANDLE hAdapter;
         D3DKMT_HANDLE hIndirectContext;
  };
       UINT                           Duration;
       D3DKMT_HANDLE                  *BroadcastSrcAllocation;
       D3DKMT_HANDLE                  *BroadcastDstAllocation;
       UINT                           PrivateDriverDataSize;
       PVOID                          pPrivateDriverData;
       BOOLEAN                        bOptimizeForComposition;
} D3DKMT_PRESENT;