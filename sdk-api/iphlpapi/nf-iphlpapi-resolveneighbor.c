IPHLPAPI_DLL_LINKAGE ULONG ResolveNeighbor(
  [in]      SOCKADDR *NetworkAddress,
  [out]     PVOID    PhysicalAddress,
  [in, out] PULONG   PhysicalAddressLength
);