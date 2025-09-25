NTSYSAPI NTSTATUS RtlEthernetStringToAddressW(
  [in]  PCWSTR   S,
  [out] LPCWSTR  *Terminator,
  [out] DL_EUI48 *Addr
);