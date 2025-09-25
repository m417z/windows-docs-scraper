NTSYSAPI NTSTATUS RtlIpv6StringToAddressExW(
  [in]  PCWSTR   AddressString,
  [out] in6_addr *Address,
  [out] PULONG   ScopeId,
  [out] PUSHORT  Port
);