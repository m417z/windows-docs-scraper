typedef struct _NDK_CONNECTOR_DISPATCH {
  NDK_FN_CLOSE_OBJECT                 NdkCloseConnector;
  NDK_FN_QUERY_EXTENSION_INTERFACE    NdkQueryExtension;
  NDK_FN_CONNECT                      NdkConnect;
  NDK_FN_CONNECT_WITH_SHARED_ENDPOINT NdkConnectWithSharedEndpoint;
  NDK_FN_COMPLETE_CONNECT             NdkCompleteConnect;
  NDK_FN_ACCEPT                       NdkAccept;
  NDK_FN_REJECT                       NdkReject;
  NDK_FN_GET_CONNECTION_DATA          NdkGetConnectionData;
  NDK_FN_GET_LOCAL_ADDRESS            NdkGetLocalAddress;
  NDK_FN_GET_PEER_ADDRESS             NdkGetPeerAddress;
  NDK_FN_DISCONNECT                   NdkDisconnect;
  NDK_FN_COMPLETE_CONNECT_EX          NdkCompleteConnectEx;
  NDK_FN_ACCEPT_EX                    NdkAcceptEx;
} NDK_CONNECTOR_DISPATCH;