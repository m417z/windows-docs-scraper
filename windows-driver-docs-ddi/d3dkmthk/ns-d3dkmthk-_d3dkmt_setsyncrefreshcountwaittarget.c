typedef struct _D3DKMT_SETSYNCREFRESHCOUNTWAITTARGET {
  [in]      D3DKMT_HANDLE                  hAdapter;
  [in, opt] D3DKMT_HANDLE                  hDevice;
  [in]      D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]      UINT                           TargetSyncRefreshCount;
} D3DKMT_SETSYNCREFRESHCOUNTWAITTARGET;