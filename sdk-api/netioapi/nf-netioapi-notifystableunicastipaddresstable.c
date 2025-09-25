IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API NotifyStableUnicastIpAddressTable(
  [in]      ADDRESS_FAMILY                           Family,
  [in, out] PMIB_UNICASTIPADDRESS_TABLE              *Table,
  [in]      PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK CallerCallback,
  [in]      PVOID                                    CallerContext,
  [in, out] HANDLE                                   *NotificationHandle
);