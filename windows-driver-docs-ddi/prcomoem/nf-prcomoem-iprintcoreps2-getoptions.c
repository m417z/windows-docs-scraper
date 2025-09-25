HRESULT GetOptions(
  [in]  PDEVOBJ pdevobj,
  [in]  DWORD   dwFlags,
  [in]  PCZZSTR pmszFeaturesRequested,
  [in]  DWORD   cbIn,
  [out] PZZSTR  pmszFeatureOptionBuf,
  [in]  DWORD   cbSize,
  [out] PDWORD  pcbNeeded
);