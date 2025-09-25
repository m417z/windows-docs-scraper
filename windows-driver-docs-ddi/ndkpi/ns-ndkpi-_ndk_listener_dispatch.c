typedef struct _NDK_LISTENER_DISPATCH {
  NDK_FN_CLOSE_OBJECT               NdkCloseListener;
  NDK_FN_QUERY_EXTENSION_INTERFACE  NdkQueryExtension;
  NDK_FN_LISTEN                     NdkListen;
  NDK_FN_GET_LISTENER_LOCAL_ADDRESS NdkGetLocalAddress;
  NDK_FN_CONTROL_CONNECT_EVENTS     NdkControlConnectEvents;
} NDK_LISTENER_DISPATCH;