NETIOAPI_API CreateSortedAddressPairs(
  _In_opt_ const PSOCKADDR_IN6      SourceAddressList,
  _In_           ULONG              SourceAddressCount,
  _In_     const PSOCKADDR_IN6      DestinationAddressList,
  _In_           ULONG              DestinationAddressCount,
  _In_           ULONG              AddressSortOptions,
  _In_           PSOCKADDR_IN6_PAIR *SortedAddressPairList,
  _Out_          ULONG              *SortedAddressPairCount
);