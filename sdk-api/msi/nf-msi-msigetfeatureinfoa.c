UINT MsiGetFeatureInfoA(
  [in]                MSIHANDLE hProduct,
  [in]                LPCSTR    szFeature,
  [out, optional]     LPDWORD   lpAttributes,
  [out, optional]     LPSTR     lpTitleBuf,
  [in, out, optional] LPDWORD   pcchTitleBuf,
  [out, optional]     LPSTR     lpHelpBuf,
  [in, out, optional] LPDWORD   pcchHelpBuf
);