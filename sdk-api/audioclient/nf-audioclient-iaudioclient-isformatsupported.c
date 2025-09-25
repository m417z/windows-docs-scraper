HRESULT IsFormatSupported(
  [in]  AUDCLNT_SHAREMODE  ShareMode,
  [in]  const WAVEFORMATEX *pFormat,
  [out] WAVEFORMATEX       **ppClosestMatch
);