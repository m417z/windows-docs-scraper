IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API ConvertInterfaceLuidToAlias(
  [in]  const NET_LUID *InterfaceLuid,
  [out] PWSTR          InterfaceAlias,
  [in]  SIZE_T         Length
);