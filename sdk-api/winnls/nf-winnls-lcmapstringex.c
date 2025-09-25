int LCMapStringEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwMapFlags,
  [in]            LPCWSTR          lpSrcStr,
  [in]            int              cchSrc,
  [out, optional] LPWSTR           lpDestStr,
  [in]            int              cchDest,
  [in, optional]  LPNLSVERSIONINFO lpVersionInformation,
  [in, optional]  LPVOID           lpReserved,
  [in, optional]  LPARAM           sortHandle
);