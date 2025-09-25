typedef struct _MSiSCSI_DiscoveryConfig {
  BOOLEAN          PerformiSNSDiscovery;
  BOOLEAN          PerformSLPDiscovery;
  BOOLEAN          AutomaticiSNSDiscovery;
  WCHAR            InitiatorName[256 + 1];
  ISCSI_IP_Address iSNSServer;
} MSiSCSI_DiscoveryConfig, *PMSiSCSI_DiscoveryConfig;