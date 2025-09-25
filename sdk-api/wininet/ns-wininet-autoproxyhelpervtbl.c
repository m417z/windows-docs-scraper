typedef struct AutoProxyHelperVtbl {
  BOOL( )(LPSTR lpszHost)  *IsResolvable;
  DWORD( )(LPSTR lpszIPAddress,LPDWORD lpdwIPAddressSize) *GetIPAddress;
  DWORD( )(LPSTR lpszHostName,LPSTR lpszIPAddress,LPDWORD lpdwIPAddressSize) *ResolveHostName;
  BOOL( )(LPSTR lpszIPAddress,LPSTR lpszDest,LPSTR lpszMask)  *IsInNet;
  BOOL( )(LPSTR lpszHost)  *IsResolvableEx;
  DWORD( )(LPSTR lpszIPAddress,LPDWORD lpdwIPAddressSize) *GetIPAddressEx;
  DWORD( )(LPSTR lpszHostName,LPSTR lpszIPAddress,LPDWORD lpdwIPAddressSize) *ResolveHostNameEx;
  BOOL( )(LPSTR lpszIPAddress,LPSTR lpszIPPrefix)  *IsInNetEx;
  DWORD( )(LPSTR lpszIPAddressList,LPSTR lpszIPSortedList,LPDWORD lpdwIPSortedListSize) *SortIpList;
} AutoProxyHelperVtbl;