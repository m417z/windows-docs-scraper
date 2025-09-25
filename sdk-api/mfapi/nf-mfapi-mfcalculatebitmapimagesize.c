HRESULT MFCalculateBitmapImageSize(
  [in]  const BITMAPINFOHEADER *pBMIH,
  [in]  UINT32                 cbBufSize,
  [out] UINT32                 *pcbImageSize,
  [out] BOOL                   *pbKnown
);