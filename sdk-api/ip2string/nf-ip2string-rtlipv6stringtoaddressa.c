NTSYSAPI NTSTATUS RtlIpv6StringToAddressA(
  [in]  PCSTR    S,
  [out] PCSTR    *Terminator,
  [out] in6_addr *Addr
);