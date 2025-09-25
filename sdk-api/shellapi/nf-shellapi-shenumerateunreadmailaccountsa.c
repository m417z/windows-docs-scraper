HRESULT SHEnumerateUnreadMailAccountsA(
  [in, optional] HKEY  hKeyUser,
                 DWORD dwIndex,
  [out]          LPSTR pszMailAddress,
                 int   cchMailAddress
);