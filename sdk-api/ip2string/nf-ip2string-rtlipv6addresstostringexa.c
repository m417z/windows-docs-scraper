NTSYSAPI NTSTATUS RtlIpv6AddressToStringExA(
  [in]      const in6_addr *Address,
  [in]      ULONG          ScopeId,
  [in]      USHORT         Port,
  [out]     PSTR           AddressString,
  [in, out] PULONG         AddressStringLength
);