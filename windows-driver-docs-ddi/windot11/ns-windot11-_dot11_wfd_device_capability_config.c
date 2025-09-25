typedef struct _DOT11_WFD_DEVICE_CAPABILITY_CONFIG {
  NDIS_OBJECT_HEADER Header;
  BOOLEAN            bServiceDiscoveryEnabled;
  BOOLEAN            bClientDiscoverabilityEnabled;
  BOOLEAN            bConcurrentOperationSupported;
  BOOLEAN            bInfrastructureManagementEnabled;
  BOOLEAN            bDeviceLimitReached;
  BOOLEAN            bInvitationProcedureEnabled;
  ULONG              WPSVersionsEnabled;
} DOT11_WFD_DEVICE_CAPABILITY_CONFIG, *PDOT11_WFD_DEVICE_CAPABILITY_CONFIG;