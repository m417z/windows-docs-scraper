HRESULT CanConvert(
  [in]  const WICPixelFormatGUID *pSrcPixelFormats,
        UINT                     cSrcPlanes,
  [in]  REFWICPixelFormatGUID    dstPixelFormat,
  [out] BOOL                     *pfCanConvert
);