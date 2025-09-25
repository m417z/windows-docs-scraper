typedef struct _NDIS_PROTOCOL_CO_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                        Header;
  ULONG                                     Flags;
  CO_STATUS_HANDLER_EX                      CoStatusHandlerEx;
  CO_AF_REGISTER_NOTIFY_HANDLER             CoAfRegisterNotifyHandler;
  CO_RECEIVE_NET_BUFFER_LISTS_HANDLER       CoReceiveNetBufferListsHandler;
  CO_SEND_NET_BUFFER_LISTS_COMPLETE_HANDLER CoSendNetBufferListsCompleteHandler;
} NDIS_PROTOCOL_CO_CHARACTERISTICS, *PNDIS_PROTOCOL_CO_CHARACTERISTICS;