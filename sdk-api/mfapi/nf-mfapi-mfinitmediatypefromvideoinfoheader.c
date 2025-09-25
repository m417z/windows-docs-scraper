HRESULT MFInitMediaTypeFromVideoInfoHeader(
  IMFMediaType          *pMFType,
  const VIDEOINFOHEADER *pVIH,
  UINT32                cbBufSize,
  const GUID            *pSubtype
);