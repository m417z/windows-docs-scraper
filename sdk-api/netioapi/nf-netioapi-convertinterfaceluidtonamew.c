IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API ConvertInterfaceLuidToNameW(
  [in]  const NET_LUID *InterfaceLuid,
  [out] PWSTR          InterfaceName,
  [in]  SIZE_T         Length
);