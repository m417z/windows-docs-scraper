typedef struct _WS_CUSTOM_CHANNEL_CALLBACKS {
  WS_CREATE_CHANNEL_CALLBACK           createChannelCallback;
  WS_FREE_CHANNEL_CALLBACK             freeChannelCallback;
  WS_RESET_CHANNEL_CALLBACK            resetChannelCallback;
  WS_OPEN_CHANNEL_CALLBACK             openChannelCallback;
  WS_CLOSE_CHANNEL_CALLBACK            closeChannelCallback;
  WS_ABORT_CHANNEL_CALLBACK            abortChannelCallback;
  WS_GET_CHANNEL_PROPERTY_CALLBACK     getChannelPropertyCallback;
  WS_SET_CHANNEL_PROPERTY_CALLBACK     setChannelPropertyCallback;
  WS_WRITE_MESSAGE_START_CALLBACK      writeMessageStartCallback;
  WS_WRITE_MESSAGE_END_CALLBACK        writeMessageEndCallback;
  WS_READ_MESSAGE_START_CALLBACK       readMessageStartCallback;
  WS_READ_MESSAGE_END_CALLBACK         readMessageEndCallback;
  WS_ABANDON_MESSAGE_CALLBACK          abandonMessageCallback;
  WS_SHUTDOWN_SESSION_CHANNEL_CALLBACK shutdownSessionChannelCallback;
} WS_CUSTOM_CHANNEL_CALLBACKS;