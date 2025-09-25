typedef struct _D3DKMT_GETVERTICALBLANKEVENT {
  [in]      D3DKMT_HANDLE                  hAdapter;
  [in]      D3DKMT_HANDLE                  hDevice;
  [in]      D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in, out] D3DKMT_PTR_TYPE                *phEvent;
} D3DKMT_GETVERTICALBLANKEVENT;