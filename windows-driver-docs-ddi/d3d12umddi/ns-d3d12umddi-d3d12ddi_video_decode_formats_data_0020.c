typedef struct D3D12DDI_VIDEO_DECODE_FORMATS_DATA_0020 {
  UINT                                     NodeIndex;
  D3D12DDI_VIDEO_DECODE_CONFIGURATION_0020 Configuration;
  UINT                                     FormatCount;
  DXGI_FORMAT                              *pOutputFormats;
} D3D12DDI_VIDEO_DECODE_FORMATS_DATA_0020;