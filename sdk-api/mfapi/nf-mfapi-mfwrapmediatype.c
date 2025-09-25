HRESULT MFWrapMediaType(
  IMFMediaType *pOrig,
  REFGUID      MajorType,
  REFGUID      SubType,
  IMFMediaType **ppWrap
);