typedef struct _MS_SMHBA_PROTOCOLSTATISTICS {
  LONGLONG SecondsSinceLastReset;
  LONGLONG InputRequests;
  LONGLONG OutputRequests;
  LONGLONG ControlRequests;
  LONGLONG InputMegabytes;
  LONGLONG OutputMegabytes;
} MS_SMHBA_PROTOCOLSTATISTICS, *PMS_SMHBA_PROTOCOLSTATISTICS;