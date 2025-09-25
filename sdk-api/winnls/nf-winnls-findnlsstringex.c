int FindNLSStringEx(
  [in, optional]  LPCWSTR          lpLocaleName,
  [in]            DWORD            dwFindNLSStringFlags,
  [in]            LPCWSTR          lpStringSource,
  [in]            int              cchSource,
  [in]            LPCWSTR          lpStringValue,
  [in]            int              cchValue,
  [out, optional] LPINT            pcchFound,
  [in, optional]  LPNLSVERSIONINFO lpVersionInformation,
  [in, optional]  LPVOID           lpReserved,
  [in, optional]  LPARAM           sortHandle
);