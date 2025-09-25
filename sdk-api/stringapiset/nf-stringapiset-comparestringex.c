int CompareStringEx(
  [in, optional] LPCWSTR                          lpLocaleName,
  [in]           DWORD                            dwCmpFlags,
  [in]           _In_NLS_string_(cchCount1)LPCWCH lpString1,
  [in]           int                              cchCount1,
  [in]           _In_NLS_string_(cchCount2)LPCWCH lpString2,
  [in]           int                              cchCount2,
  [in, optional] LPNLSVERSIONINFO                 lpVersionInformation,
  [in, optional] LPVOID                           lpReserved,
  [in, optional] LPARAM                           lParam
);