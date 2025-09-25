NTSYSAPI NTSTATUS RtlIpv6AddressToStringExW(
  [in]      const in6_addr *Address,
  [in]      ULONG          ScopeId,
  [in]      USHORT         Port,
  [out]     PWSTR          AddressString,
  [in, out] PULONG         AddressStringLength
);