HRESULT IsOutputFormatSupported(
  [in]  const WAVEFORMATEX *pInputFormat,
  [in]  const WAVEFORMATEX *pRequestedOutputFormat,
  [out] WAVEFORMATEX       **ppSupportedOutputFormat
);