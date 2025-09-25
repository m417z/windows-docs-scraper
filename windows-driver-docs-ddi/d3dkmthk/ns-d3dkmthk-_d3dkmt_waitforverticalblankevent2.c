typedef struct _D3DKMT_WAITFORVERTICALBLANKEVENT2 {
  [in] D3DKMT_HANDLE                  hAdapter;
  [in] D3DKMT_HANDLE                  hDevice;
  [in] D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
       UINT                           NumObjects;
       D3DKMT_PTR_TYPE                ObjectHandleArray[D3DKMT_MAX_WAITFORVERTICALBLANK_OBJECTS];
} D3DKMT_WAITFORVERTICALBLANKEVENT2;