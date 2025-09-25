HRESULT CreateImageSourceFromDxgi(
  IDXGISurface                        **surfaces,
  UINT32                              surfaceCount,
  DXGI_COLOR_SPACE_TYPE               colorSpace,
  D2D1_IMAGE_SOURCE_FROM_DXGI_OPTIONS options,
  ID2D1ImageSource                    **imageSource
);