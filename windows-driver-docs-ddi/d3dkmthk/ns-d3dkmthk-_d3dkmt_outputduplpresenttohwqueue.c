typedef struct _D3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE {
  D3DKMT_HANDLE                  hSource;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  ULONG                          BroadcastHwQueueCount;
  D3DKMT_HANDLE                  *hHwQueues;
  D3DKMT_PRESENT_RGNS            PresentRegions;
  D3DKMT_OUTPUTDUPLPRESENTFLAGS  Flags;
  D3DKMT_HANDLE                  hIndirectHwQueue;
} D3DKMT_OUTPUTDUPLPRESENTTOHWQUEUE;