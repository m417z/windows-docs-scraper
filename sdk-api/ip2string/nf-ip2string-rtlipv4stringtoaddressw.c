NTSYSAPI NTSTATUS RtlIpv4StringToAddressW(
  [in]  PCWSTR  S,
  [in]  BOOLEAN Strict,
  [out] LPCWSTR *Terminator,
  [out] in_addr *Addr
);