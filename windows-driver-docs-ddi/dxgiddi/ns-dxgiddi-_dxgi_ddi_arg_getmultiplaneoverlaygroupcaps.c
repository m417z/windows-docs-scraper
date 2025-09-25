typedef struct _DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS {
  [in]  DXGI_DDI_HDEVICE                       hDevice;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID         VidPnSourceId;
  [in]  UINT                                   GroupIndex;
  [out] DXGI_DDI_MULTIPLANE_OVERLAY_GROUP_CAPS MultiplaneOverlayGroupCaps;
} DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS;