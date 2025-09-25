NTSYSAPI NTSTATUS RtlIpv4AddressToStringExA(
  [in]      const in_addr *Address,
  [in]      USHORT        Port,
  [out]     PSTR          AddressString,
  [in, out] PULONG        AddressStringLength
);