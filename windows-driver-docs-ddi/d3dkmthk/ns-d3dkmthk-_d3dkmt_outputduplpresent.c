typedef struct _D3DKMT_OUTPUTDUPLPRESENT {
  [in] D3DKMT_HANDLE                  hContext;
  [in] D3DKMT_HANDLE                  hSource;
       D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in] ULONG                          BroadcastContextCount;
       D3DKMT_HANDLE                  BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] D3DKMT_PRESENT_RGNS            PresentRegions;
  [in] D3DKMT_OUTPUTDUPLPRESENTFLAGS  Flags;
       D3DKMT_HANDLE                  hIndirectContext;
} D3DKMT_OUTPUTDUPLPRESENT;