typedef struct _DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG {
  NDIS_OBJECT_HEADER Header;
  BOOLEAN            bPersistentGroupEnabled;
  BOOLEAN            bIntraBSSDistributionSupported;
  BOOLEAN            bCrossConnectionSupported;
  BOOLEAN            bPersistentReconnectSupported;
  BOOLEAN            bGroupFormationEnabled;
  ULONG              uMaximumGroupLimit;
}  DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG, *PDOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG;