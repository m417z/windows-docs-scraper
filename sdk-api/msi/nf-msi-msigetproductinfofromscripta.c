UINT MsiGetProductInfoFromScriptA(
  [in]      LPCSTR  szScriptFile,
  [out]     LPSTR   lpProductBuf39,
  [out]     LANGID  *plgidLanguage,
  [out]     LPDWORD pdwVersion,
  [out]     LPSTR   lpNameBuf,
  [in, out] LPDWORD pcchNameBuf,
  [out]     LPSTR   lpPackageBuf,
  [in, out] LPDWORD pcchPackageBuf
);