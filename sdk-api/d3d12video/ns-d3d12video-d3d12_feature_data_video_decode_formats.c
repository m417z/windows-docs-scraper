typedef struct D3D12_FEATURE_DATA_VIDEO_DECODE_FORMATS {
  UINT                             NodeIndex;
  D3D12_VIDEO_DECODE_CONFIGURATION Configuration;
  UINT                             FormatCount;
  DXGI_FORMAT                      *pOutputFormats;
} D3D12_FEATURE_DATA_VIDEO_DECODE_FORMATS;