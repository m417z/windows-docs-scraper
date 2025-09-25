typedef struct _DOT4_DRIVER_CMD {
  CHANNEL_HANDLE hChannelHandle;
  ULONG          ulSize;
  ULONG          ulOffset;
  ULONG          ulTimeout;
} DOT4_DRIVER_CMD, *PDOT4_DRIVER_CMD;