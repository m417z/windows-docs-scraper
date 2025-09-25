UINT MsiGetFeatureInfoW(
  [in]                MSIHANDLE hProduct,
  [in]                LPCWSTR   szFeature,
  [out, optional]     LPDWORD   lpAttributes,
  [out, optional]     LPWSTR    lpTitleBuf,
  [in, out, optional] LPDWORD   pcchTitleBuf,
  [out, optional]     LPWSTR    lpHelpBuf,
  [in, out, optional] LPDWORD   pcchHelpBuf
);