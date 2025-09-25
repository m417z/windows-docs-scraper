typedef struct _WLAN_CONNECTION_QOS_INFO {
  WLAN_QOS_CAPABILITIES peerCapabilities;
  BOOL                  bMSCSConfigured;
  BOOL                  bDSCPToUPMappingConfigured;
  ULONG                 ulNumConfiguredSCSStreams;
  ULONG                 ulNumConfiguredDSCPPolicies;
} WLAN_CONNECTION_QOS_INFO, *PWLAN_CONNECTION_QOS_INFO;