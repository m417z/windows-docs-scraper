typedef struct _DOT11_SEND_INVITATION_RESPONSE_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  DOT11_MAC_ADDRESS               ReceiverDeviceAddress;
  DOT11_DIALOG_TOKEN              DialogToken;
  PVOID                           RequestContext;
  ULONG                           uSendTimeout;
  DOT11_WFD_STATUS_CODE           Status;
  DOT11_WFD_CONFIGURATION_TIMEOUT MinimumConfigTimeout;
  DOT11_MAC_ADDRESS               GroupBSSID;
  BOOLEAN                         bUseGroupBSSID;
  DOT11_WFD_CHANNEL               OperatingChannel;
  BOOLEAN                         bUseSpecifiedOperatingChannel;
  ULONG                           uIEsOffset;
  ULONG                           uIEsLength;
} DOT11_SEND_INVITATION_RESPONSE_PARAMETERS, *PDOT11_SEND_INVITATION_RESPONSE_PARAMETERS;