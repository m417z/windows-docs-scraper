typedef struct _SERIAL_HANDFLOW {
  ULONG ControlHandShake;
  ULONG FlowReplace;
  LONG  XonLimit;
  LONG  XoffLimit;
} SERIAL_HANDFLOW, *PSERIAL_HANDFLOW;