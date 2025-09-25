NTSYSAPI NTSTATUS RtlEthernetStringToAddressA(
  [in]  PCSTR    S,
  [out] PCSTR    *Terminator,
  [out] DL_EUI48 *Addr
);