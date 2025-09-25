IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API CreateSortedAddressPairs(
  [in, optional] const PSOCKADDR_IN6 SourceAddressList,
  [in]           ULONG               SourceAddressCount,
  [in]           const PSOCKADDR_IN6 DestinationAddressList,
  [in]           ULONG               DestinationAddressCount,
  [in]           ULONG               AddressSortOptions,
  [out]          PSOCKADDR_IN6_PAIR  *SortedAddressPairList,
  [out]          ULONG               *SortedAddressPairCount
);