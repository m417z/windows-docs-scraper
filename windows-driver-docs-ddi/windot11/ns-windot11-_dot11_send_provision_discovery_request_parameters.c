typedef struct _DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER         Header;
  DOT11_DIALOG_TOKEN         DialogToken;
  DOT11_MAC_ADDRESS          PeerDeviceAddress;
  ULONG                      uSendTimeout;
  DOT11_WFD_GROUP_CAPABILITY GroupCapability;
  DOT11_WFD_GROUP_ID         GroupID;
  BOOLEAN                    bUseGroupID;
  ULONG                      uIEsOffset;
  ULONG                      uIEsLength;
} DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS, *PDOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS;