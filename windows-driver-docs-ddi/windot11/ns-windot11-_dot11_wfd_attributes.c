typedef struct _DOT11_WFD_ATTRIBUTES {
  NDIS_OBJECT_HEADER              Header;
  ULONG                           uNumConcurrentGORole;
  ULONG                           uNumConcurrentClientRole;
  ULONG                           WPSVersionsSupported;
  BOOLEAN                         bServiceDiscoverySupported;
  BOOLEAN                         bClientDiscoverabilitySupported;
  BOOLEAN                         bInfrastructureManagementSupported;
  ULONG                           uMaxSecondaryDeviceTypeListSize;
  DOT11_MAC_ADDRESS               DeviceAddress;
  ULONG                           uInterfaceAddressListCount;
  PDOT11_MAC_ADDRESS              pInterfaceAddressList;
  ULONG                           uNumSupportedCountryOrRegionStrings;
  PDOT11_COUNTRY_OR_REGION_STRING pSupportedCountryOrRegionStrings;
  ULONG                           uDiscoveryFilterListSize;
  ULONG                           uGORoleClientTableSize;
} DOT11_WFD_ATTRIBUTES, *PDOT11_WFD_ATTRIBUTES;