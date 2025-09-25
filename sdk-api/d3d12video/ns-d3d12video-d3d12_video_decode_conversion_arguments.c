typedef struct D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS {
  BOOL                  Enable;
  ID3D12Resource        *pReferenceTexture2D;
  UINT                  ReferenceSubresource;
  DXGI_COLOR_SPACE_TYPE OutputColorSpace;
  DXGI_COLOR_SPACE_TYPE DecodeColorSpace;
} D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS;