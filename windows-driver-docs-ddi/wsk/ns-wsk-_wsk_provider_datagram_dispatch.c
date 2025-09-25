typedef struct _WSK_PROVIDER_DATAGRAM_DISPATCH {
  WSK_PROVIDER_BASIC_DISPATCH              Basic;
  PFN_WSK_BIND                             WskBind;
  PFN_WSK_SEND_TO                          WskSendTo;
  PFN_WSK_RECEIVE_FROM                     WskReceiveFrom;
  PFN_WSK_RELEASE_DATAGRAM_INDICATION_LIST WskRelease;
  PFN_WSK_GET_LOCAL_ADDRESS                WskGetLocalAddress;
  PFN_WSK_SEND_MESSAGES                    WskSendMessages;
} WSK_PROVIDER_DATAGRAM_DISPATCH, *PWSK_PROVIDER_DATAGRAM_DISPATCH;