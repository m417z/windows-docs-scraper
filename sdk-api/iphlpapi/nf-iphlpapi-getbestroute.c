IPHLPAPI_DLL_LINKAGE DWORD GetBestRoute(
  [in]  DWORD             dwDestAddr,
  [in]  DWORD             dwSourceAddr,
  [out] PMIB_IPFORWARDROW pBestRoute
);