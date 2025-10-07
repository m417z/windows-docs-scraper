NETIOAPI_API NotifyStableUnicastIpAddressTable(
  _In_    ADDRESS_FAMILY                           Family,
  _Out_   PMIB_UNICASTIPADDRESS_TABLE              *Table,
  _In_    PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK CallerCallback,
  _In_    PVOID                                    CallerContext,
  _Inout_ HANDLE                                   *NotificationHandle
);