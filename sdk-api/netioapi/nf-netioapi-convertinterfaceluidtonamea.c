IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API ConvertInterfaceLuidToNameA(
  [in]  const NET_LUID *InterfaceLuid,
  [out] PSTR           InterfaceName,
  [in]  SIZE_T         Length
);