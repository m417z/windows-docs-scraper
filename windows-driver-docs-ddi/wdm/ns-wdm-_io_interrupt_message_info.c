typedef struct _IO_INTERRUPT_MESSAGE_INFO {
  KIRQL                           UnifiedIrql;
  ULONG                           MessageCount;
  IO_INTERRUPT_MESSAGE_INFO_ENTRY MessageInfo[1];
} IO_INTERRUPT_MESSAGE_INFO, *PIO_INTERRUPT_MESSAGE_INFO;