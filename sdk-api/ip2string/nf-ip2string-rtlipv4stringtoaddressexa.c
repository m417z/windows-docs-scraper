NTSYSAPI NTSTATUS RtlIpv4StringToAddressExA(
  [in]  PCSTR   AddressString,
  [in]  BOOLEAN Strict,
  [out] in_addr *Address,
  [out] PUSHORT Port
);