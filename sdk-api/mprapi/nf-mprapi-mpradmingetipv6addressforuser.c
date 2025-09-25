DWORD MprAdminGetIpv6AddressForUser(
  [in]      WCHAR    *lpwszUserName,
  [in]      WCHAR    *lpwszPortName,
  [in, out] IN6_ADDR *lpdwIpv6Address,
  [out]     BOOL     *bNotifyRelease
);