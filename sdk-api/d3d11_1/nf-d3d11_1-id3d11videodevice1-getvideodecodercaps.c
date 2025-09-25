HRESULT GetVideoDecoderCaps(
  [in]  const GUID          *pDecoderProfile,
  [in]  UINT                SampleWidth,
  [in]  UINT                SampleHeight,
  [in]  const DXGI_RATIONAL *pFrameRate,
  [in]  UINT                BitRate,
  [in]  const GUID          *pCryptoType,
  [out] UINT                *pDecoderCaps
);