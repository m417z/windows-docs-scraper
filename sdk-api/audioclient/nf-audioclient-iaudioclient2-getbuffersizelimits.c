HRESULT GetBufferSizeLimits(
  [in]  const WAVEFORMATEX *pFormat,
  [in]  BOOL               bEventDriven,
  [out] REFERENCE_TIME     *phnsMinBufferDuration,
  [out] REFERENCE_TIME     *phnsMaxBufferDuration
);