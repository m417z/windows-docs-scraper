HRESULT MFCreateMediaBufferFromMediaType(
  [in]  IMFMediaType   *pMediaType,
  [in]  LONGLONG       llDuration,
  [in]  DWORD          dwMinLength,
  [in]  DWORD          dwMinAlignment,
  [out] IMFMediaBuffer **ppBuffer
);