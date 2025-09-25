typedef struct D3D12DDI_VIDEO_DECODE_CONVERSION_ARGUMENTS_0041 {
  BOOL                  Enable;
  D3D12DDI_HRESOURCE    hDrvReferenceTexture2D;
  UINT                  ReferenceSubresource;
  DXGI_COLOR_SPACE_TYPE OutputColorSpace;
  DXGI_COLOR_SPACE_TYPE DecodeColorSpace;
  UINT                  OutputWidth;
  UINT                  OutputHeight;
} D3D12DDI_VIDEO_DECODE_CONVERSION_ARGUMENTS_0041;