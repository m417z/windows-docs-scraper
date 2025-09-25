typedef struct _NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                      Header;
  ULONG                                   Flags;
  NDIS_CHIMNEY_OFFLOAD_TYPE               OffloadType;
  TCP_OFFLOAD_SEND_COMPLETE_HANDLER       TcpOffloadSendCompleteHandler;
  TCP_OFFLOAD_RECV_COMPLETE_HANDLER       TcpOffloadReceiveCompleteHandler;
  TCP_OFFLOAD_DISCONNECT_COMPLETE_HANDLER TcpOffloadDisconnectCompleteHandler;
  TCP_OFFLOAD_FORWARD_COMPLETE_HANDLER    TcpOffloadForwardCompleteHandler;
  TCP_OFFLOAD_EVENT_HANDLER               TcpOffloadEventHandler;
  TCP_OFFLOAD_RECEIVE_INDICATE_HANDLER    TcpOffloadReceiveIndicateHandler;
} NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS, *PNDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS;