HRESULT OnProcessSample(
  [in] REFGUID    guidMajorMediaType,
  [in] DWORD      dwSampleFlags,
  [in] LONGLONG   llSampleTime,
  [in] LONGLONG   llSampleDuration,
  [in] const BYTE *pSampleBuffer,
  [in] DWORD      dwSampleSize
);