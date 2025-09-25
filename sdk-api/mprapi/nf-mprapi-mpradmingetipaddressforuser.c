DWORD MprAdminGetIpAddressForUser(
  [in]      WCHAR *lpwszUserName,
  [in]      WCHAR *lpwszPortName,
  [in, out] DWORD *lpdwIpAddress,
  [out]     BOOL  *bNotifyRelease
);