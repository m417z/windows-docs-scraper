HRESULT GetSharedModeEnginePeriod(
  [in]  const WAVEFORMATEX *pFormat,
  [out] UINT32             *pDefaultPeriodInFrames,
  [out] UINT32             *pFundamentalPeriodInFrames,
  [out] UINT32             *pMinPeriodInFrames,
  [out] UINT32             *pMaxPeriodInFrames
);