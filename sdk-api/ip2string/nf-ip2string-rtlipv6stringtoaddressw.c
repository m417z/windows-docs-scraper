NTSYSAPI NTSTATUS RtlIpv6StringToAddressW(
  [in]  PCWSTR   S,
  [out] PCWSTR   *Terminator,
  [out] in6_addr *Addr
);