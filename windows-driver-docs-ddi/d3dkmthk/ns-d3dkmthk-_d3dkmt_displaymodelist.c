typedef struct _D3DKMT_DISPLAYMODELIST {
  [in]     D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in/out] UINT                           ModeCount;
           D3DKMT_DISPLAYMODE             pModeList[0];
} D3DKMT_DISPLAYMODELIST;