IPHLPAPI_DLL_LINKAGE BOOL GetRTTAndHopCount(
  [in]  IPAddr DestIpAddress,
  [out] PULONG HopCount,
  [in]  ULONG  MaxHops,
  [out] PULONG RTT
);