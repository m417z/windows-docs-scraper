DWORD NlsDllCodePageTranslation(
  [in]      DWORD    CodePage,
  [in]      DWORD    dwFlags,
  [in, out] LPSTR    lpMultiByteStr,
  [in]      int      cchMultiByte,
  [in, out] LPWSTR   lpWideCharStr,
  [in]      int      cchWideChar,
  [in]      LPCPINFO lpCPInfo
);