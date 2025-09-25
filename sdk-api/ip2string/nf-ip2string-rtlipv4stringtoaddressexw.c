NTSYSAPI NTSTATUS RtlIpv4StringToAddressExW(
  [in]  PCWSTR  AddressString,
  [in]  BOOLEAN Strict,
  [out] in_addr *Address,
  [out] PUSHORT Port
);