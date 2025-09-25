UINT MsiGetProductInfoFromScriptW(
  [in]      LPCWSTR szScriptFile,
  [out]     LPWSTR  lpProductBuf39,
  [out]     LANGID  *plgidLanguage,
  [out]     LPDWORD pdwVersion,
  [out]     LPWSTR  lpNameBuf,
  [in, out] LPDWORD pcchNameBuf,
  [out]     LPWSTR  lpPackageBuf,
  [in, out] LPDWORD pcchPackageBuf
);