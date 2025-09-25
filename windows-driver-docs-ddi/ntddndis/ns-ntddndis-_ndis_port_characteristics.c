typedef struct _NDIS_PORT_CHARACTERISTICS {
  NDIS_OBJECT_HEADER            Header;
  NDIS_PORT_NUMBER              PortNumber;
  ULONG                         Flags;
  NDIS_PORT_TYPE                Type;
  NDIS_MEDIA_CONNECT_STATE      MediaConnectState;
  ULONG64                       XmitLinkSpeed;
  ULONG64                       RcvLinkSpeed;
  NET_IF_DIRECTION_TYPE         Direction;
  NDIS_PORT_CONTROL_STATE       SendControlState;
  NDIS_PORT_CONTROL_STATE       RcvControlState;
  NDIS_PORT_AUTHORIZATION_STATE SendAuthorizationState;
  NDIS_PORT_AUTHORIZATION_STATE RcvAuthorizationState;
} NDIS_PORT_CHARACTERISTICS, *PNDIS_PORT_CHARACTERISTICS;