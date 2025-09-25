typedef struct _HTTP_REQUEST_CHANNEL_BIND_STATUS {
  PHTTP_SERVICE_BINDING_BASE ServiceName;
  PUCHAR                     ChannelToken;
  ULONG                      ChannelTokenSize;
  ULONG                      Flags;
} HTTP_REQUEST_CHANNEL_BIND_STATUS, *PHTTP_REQUEST_CHANNEL_BIND_STATUS;