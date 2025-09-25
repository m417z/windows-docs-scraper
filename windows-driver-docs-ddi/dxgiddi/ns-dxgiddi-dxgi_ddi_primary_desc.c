typedef struct DXGI_DDI_PRIMARY_DESC {
  [in]  UINT                           Flags;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  DXGI_DDI_MODE_DESC             ModeDesc;
  [out] UINT                           DriverFlags;
} DXGI_DDI_PRIMARY_DESC;