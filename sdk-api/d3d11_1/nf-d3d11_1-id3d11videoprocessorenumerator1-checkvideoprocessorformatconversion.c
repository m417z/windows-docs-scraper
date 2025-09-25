HRESULT CheckVideoProcessorFormatConversion(
  [in]  DXGI_FORMAT           InputFormat,
  [in]  DXGI_COLOR_SPACE_TYPE InputColorSpace,
  [in]  DXGI_FORMAT           OutputFormat,
  [in]  DXGI_COLOR_SPACE_TYPE OutputColorSpace,
  [out] BOOL                  *pSupported
);