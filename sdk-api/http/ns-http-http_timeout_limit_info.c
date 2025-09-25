typedef struct _HTTP_TIMEOUT_LIMIT_INFO {
  HTTP_PROPERTY_FLAGS Flags;
  USHORT              EntityBody;
  USHORT              DrainEntityBody;
  USHORT              RequestQueue;
  USHORT              IdleConnection;
  USHORT              HeaderWait;
  ULONG               MinSendRate;
} HTTP_TIMEOUT_LIMIT_INFO, *PHTTP_TIMEOUT_LIMIT_INFO;