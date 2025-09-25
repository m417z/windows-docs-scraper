typedef struct _DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT {
        DXGI_DDI_HDEVICE               hDevice;
        D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
        UINT                           DesiredPresentDuration;
        UINT                           ClosestSmallerDuration;
  [out] UINT                           ClosestLargerDuration;
} DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT;