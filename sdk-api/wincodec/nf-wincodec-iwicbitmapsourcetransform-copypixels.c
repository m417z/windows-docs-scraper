HRESULT CopyPixels(
  [in]  const WICRect             *prc,
  [in]  UINT                      uiWidth,
  [in]  UINT                      uiHeight,
  [in]  WICPixelFormatGUID        *pguidDstFormat,
  [in]  WICBitmapTransformOptions dstTransform,
  [in]  UINT                      nStride,
  [in]  UINT                      cbBufferSize,
  [out] BYTE                      *pbBuffer
);