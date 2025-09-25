typedef struct _ROOTHUB_INFO {
  ULONG           Size;
  CONTROLLER_TYPE ControllerType;
  USHORT          NumberOf20Ports;
  USHORT          NumberOf30Ports;
  USHORT          MaxU1ExitLatency;
  USHORT          MaxU2ExitLatency;
} ROOTHUB_INFO, *PROOTHUB_INFO;