typedef struct _WDF_INTERRUPT_INFO {
  ULONG                  Size;
  ULONG64                Reserved1;
  KAFFINITY              TargetProcessorSet;
  ULONG                  Reserved2;
  ULONG                  MessageNumber;
  ULONG                  Vector;
  KIRQL                  Irql;
  KINTERRUPT_MODE        Mode;
  WDF_INTERRUPT_POLARITY Polarity;
  BOOLEAN                MessageSignaled;
  UCHAR                  ShareDisposition;
  USHORT                 Group;
} WDF_INTERRUPT_INFO, *PWDF_INTERRUPT_INFO;