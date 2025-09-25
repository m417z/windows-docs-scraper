typedef struct _WS_CUSTOM_LISTENER_CALLBACKS {
  WS_CREATE_LISTENER_CALLBACK             createListenerCallback;
  WS_FREE_LISTENER_CALLBACK               freeListenerCallback;
  WS_RESET_LISTENER_CALLBACK              resetListenerCallback;
  WS_OPEN_LISTENER_CALLBACK               openListenerCallback;
  WS_CLOSE_LISTENER_CALLBACK              closeListenerCallback;
  WS_ABORT_LISTENER_CALLBACK              abortListenerCallback;
  WS_GET_LISTENER_PROPERTY_CALLBACK       getListenerPropertyCallback;
  WS_SET_LISTENER_PROPERTY_CALLBACK       setListenerPropertyCallback;
  WS_CREATE_CHANNEL_FOR_LISTENER_CALLBACK createChannelForListenerCallback;
  WS_ACCEPT_CHANNEL_CALLBACK              acceptChannelCallback;
} WS_CUSTOM_LISTENER_CALLBACKS;