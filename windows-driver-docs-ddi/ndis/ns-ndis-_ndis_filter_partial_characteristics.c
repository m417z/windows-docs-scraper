typedef struct _NDIS_FILTER_PARTIAL_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                            Header;
  ULONG                                         Flags;
  FILTER_SEND_NET_BUFFER_LISTS_HANDLER          SendNetBufferListsHandler;
  FILTER_SEND_NET_BUFFER_LISTS_COMPLETE_HANDLER SendNetBufferListsCompleteHandler;
  FILTER_CANCEL_SEND_HANDLER                    CancelSendNetBufferListsHandler;
  FILTER_RECEIVE_NET_BUFFER_LISTS_HANDLER       ReceiveNetBufferListsHandler;
  FILTER_RETURN_NET_BUFFER_LISTS_HANDLER        ReturnNetBufferListsHandler;
} NDIS_FILTER_PARTIAL_CHARACTERISTICS, *PNDIS_FILTER_PARTIAL_CHARACTERISTICS;