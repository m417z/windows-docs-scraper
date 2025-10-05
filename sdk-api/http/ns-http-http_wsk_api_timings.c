typedef struct _HTTP_WSK_API_TIMINGS {
  ULONGLONG ConnectCount;
  ULONGLONG ConnectSum;
  ULONGLONG DisconnectCount;
  ULONGLONG DisconnectSum;
  ULONGLONG SendCount;
  ULONGLONG SendSum;
  ULONGLONG ReceiveCount;
  ULONGLONG ReceiveSum;
  ULONGLONG ReleaseCount;
  ULONGLONG ReleaseSum;
  ULONGLONG ControlSocketCount;
  ULONGLONG ControlSocketSum;
} HTTP_WSK_API_TIMINGS, *PHTTP_WSK_API_TIMINGS;