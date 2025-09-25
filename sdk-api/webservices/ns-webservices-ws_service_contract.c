typedef struct _WS_SERVICE_CONTRACT {
  const WS_CONTRACT_DESCRIPTION       *contractDescription;
  WS_SERVICE_MESSAGE_RECEIVE_CALLBACK defaultMessageHandlerCallback;
  const void                          *methodTable;
} WS_SERVICE_CONTRACT;