NTSYSAPI NTSTATUS RtlIpv4AddressToStringExW(
  [in]      const in_addr *Address,
  [in]      USHORT        Port,
  [out]     PWSTR         AddressString,
  [in, out] PULONG        AddressStringLength
);