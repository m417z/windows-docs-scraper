typedef struct _DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS {
  NDIS_OBJECT_HEADER         Header;
  DOT11_MAC_ADDRESS          PeerDeviceAddress;
  DOT11_DIALOG_TOKEN         DialogToken;
  PVOID                      ResponseContext;
  ULONG                      uSendTimeout;
  DOT11_WFD_STATUS_CODE      Status;
  DOT11_WFD_GROUP_CAPABILITY GroupCapability;
  DOT11_WFD_GROUP_ID         GroupID;
  BOOLEAN                    bUseGroupID;
  ULONG                      uIEsOffset;
  ULONG                      uIEsLength;
} DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS, *PDOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS;