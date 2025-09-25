HRESULT SHEnumerateUnreadMailAccountsW(
  [in, optional] HKEY   hKeyUser,
                 DWORD  dwIndex,
  [out]          LPWSTR pszMailAddress,
                 int    cchMailAddress
);