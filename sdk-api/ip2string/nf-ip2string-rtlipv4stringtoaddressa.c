NTSYSAPI NTSTATUS RtlIpv4StringToAddressA(
  [in]  PCSTR   S,
  [in]  BOOLEAN Strict,
  [out] PCSTR   *Terminator,
  [out] in_addr *Addr
);