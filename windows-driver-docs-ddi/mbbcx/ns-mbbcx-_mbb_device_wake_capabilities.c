typedef struct _MBB_DEVICE_WAKE_CAPABILITIES {
  ULONG   Size;
  BOOLEAN RegisterState;
  BOOLEAN SmsReceive;
  BOOLEAN UssdReceive;
  BOOLEAN PacketState;
  BOOLEAN UiccChange;
} MBB_DEVICE_WAKE_CAPABILITIES;