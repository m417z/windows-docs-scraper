NTSTATUS FLTAPI FltCreateCommunicationPort(
  PFLT_FILTER            Filter,
  PFLT_PORT              *ServerPort,
  POBJECT_ATTRIBUTES     ObjectAttributes,
  PVOID                  ServerPortCookie,
  PFLT_CONNECT_NOTIFY    ConnectNotifyCallback,
  PFLT_DISCONNECT_NOTIFY DisconnectNotifyCallback,
  PFLT_MESSAGE_NOTIFY    MessageNotifyCallback,
  LONG                   MaxConnections
);