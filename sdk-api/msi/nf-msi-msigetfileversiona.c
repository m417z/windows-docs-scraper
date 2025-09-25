UINT MsiGetFileVersionA(
  [in]      LPCSTR  szFilePath,
  [out]     LPSTR   lpVersionBuf,
  [in, out] LPDWORD pcchVersionBuf,
  [out]     LPSTR   lpLangBuf,
  [in, out] LPDWORD pcchLangBuf
);