typedef struct _NDIS_PORT_STATE {
  NDIS_OBJECT_HEADER            Header;
  NDIS_MEDIA_CONNECT_STATE      MediaConnectState;
  ULONG64                       XmitLinkSpeed;
  ULONG64                       RcvLinkSpeed;
  NET_IF_DIRECTION_TYPE         Direction;
  NDIS_PORT_CONTROL_STATE       SendControlState;
  NDIS_PORT_CONTROL_STATE       RcvControlState;
  NDIS_PORT_AUTHORIZATION_STATE SendAuthorizationState;
  NDIS_PORT_AUTHORIZATION_STATE RcvAuthorizationState;
  ULONG                         Flags;
} NDIS_PORT_STATE, *PNDIS_PORT_STATE;