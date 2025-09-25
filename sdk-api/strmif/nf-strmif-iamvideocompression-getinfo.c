HRESULT GetInfo(
  [out]     LPWSTR pszVersion,
  [in, out] int    *pcbVersion,
  [out]     LPWSTR pszDescription,
  [in, out] int    *pcbDescription,
  [out]     long   *pDefaultKeyFrameRate,
  [out]     long   *pDefaultPFramesPerKey,
  [out]     double *pDefaultQuality,
  [out]     long   *pCapabilities
);