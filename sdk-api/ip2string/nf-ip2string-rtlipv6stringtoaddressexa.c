NTSYSAPI NTSTATUS RtlIpv6StringToAddressExA(
  [in]  PCSTR    AddressString,
  [out] in6_addr *Address,
  [out] PULONG   ScopeId,
  [out] PUSHORT  Port
);