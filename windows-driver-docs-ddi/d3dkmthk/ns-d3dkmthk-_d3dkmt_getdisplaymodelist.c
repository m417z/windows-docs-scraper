typedef struct _D3DKMT_GETDISPLAYMODELIST {
  D3DKMT_HANDLE                  hAdapter;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  D3DKMT_DISPLAYMODE             *pModeList;
  UINT                           ModeCount;
} D3DKMT_GETDISPLAYMODELIST;