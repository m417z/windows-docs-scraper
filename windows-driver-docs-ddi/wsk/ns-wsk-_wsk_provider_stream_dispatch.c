typedef struct _WSK_PROVIDER_STREAM_DISPATCH {
  WSK_PROVIDER_BASIC_DISPATCH          Basic;
  PFN_WSK_BIND                         WskBind;
  PFN_WSK_ACCEPT                       WskAccept;
  PFN_WSK_CONNECT                      WskConnect;
  PFN_WSK_LISTEN                       WskListen;
  PFN_WSK_SEND                         WskSend;
  PFN_WSK_RECEIVE                      WskReceive;
  PFN_WSK_DISCONNECT                   WskDisconnect;
  PFN_WSK_RELEASE_DATA_INDICATION_LIST WskRelease;
  PFN_WSK_GET_LOCAL_ADDRESS            WskGetLocalAddress;
  PFN_WSK_GET_REMOTE_ADDRESS           WskGetRemoteAddress;
  PFN_WSK_CONNECT_EX                   WskConnectEx;
  PFN_WSK_SEND_EX                      WskSendEx;
  PFN_WSK_RECEIVE_EX                   WskReceiveEx;
} WSK_PROVIDER_STREAM_DISPATCH, *PWSK_PROVIDER_STREAM_DISPATCH;