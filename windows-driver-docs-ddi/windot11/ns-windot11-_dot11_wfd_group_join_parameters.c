typedef struct _DOT11_WFD_GROUP_JOIN_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  DOT11_WFD_CHANNEL  GOOperatingChannel;
  ULONG              GOConfigTime;
  BOOLEAN            bInGroupFormation;
  BOOLEAN            bWaitForWPSReady;
} DOT11_WFD_GROUP_JOIN_PARAMETERS, *PDOT11_WFD_GROUP_JOIN_PARAMETERS;