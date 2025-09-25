HRESULT MFCombineSamples(
  IMFSample *pSample,
  IMFSample *pSampleToAdd,
  DWORD     dwMaxMergedDurationInMS,
  BOOL      *pMerged
);