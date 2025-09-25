DWORD PXEAPI PxeDhcpv6GetVendorOptionValue(
  [in]            PVOID pPacket,
  [in]            ULONG uPacketLen,
  [in]            DWORD dwEnterpriseNumber,
  [in]            WORD  wOption,
  [in]            ULONG uInstance,
  [out, optional] PWORD pwOptionLen,
  [out, optional] PVOID *ppOptionValue
);