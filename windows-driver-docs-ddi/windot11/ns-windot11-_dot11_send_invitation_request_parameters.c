typedef struct _DOT11_SEND_INVITATION_REQUEST_PARAMETERS {
  NDIS_OBJECT_HEADER              Header;
  DOT11_DIALOG_TOKEN              DialogToken;
  DOT11_MAC_ADDRESS               PeerDeviceAddress;
  ULONG                           uSendTimeout;
  DOT11_WFD_CONFIGURATION_TIMEOUT MinimumConfigTimeout;
  DOT11_WFD_INVITATION_FLAGS      InvitationFlags;
  DOT11_MAC_ADDRESS               GroupBSSID;
  BOOLEAN                         bUseGroupBSSID;
  DOT11_WFD_CHANNEL               OperatingChannel;
  BOOLEAN                         bUseSpecifiedOperatingChannel;
  DOT11_WFD_GROUP_ID              GroupID;
  BOOLEAN                         bLocalGO;
  ULONG                           uIEsOffset;
  ULONG                           uIEsLength;
} DOT11_SEND_INVITATION_REQUEST_PARAMETERS, *PDOT11_SEND_INVITATION_REQUEST_PARAMETERS;