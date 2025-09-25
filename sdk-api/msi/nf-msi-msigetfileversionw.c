UINT MsiGetFileVersionW(
  [in]      LPCWSTR szFilePath,
  [out]     LPWSTR  lpVersionBuf,
  [in, out] LPDWORD pcchVersionBuf,
  [out]     LPWSTR  lpLangBuf,
  [in, out] LPDWORD pcchLangBuf
);