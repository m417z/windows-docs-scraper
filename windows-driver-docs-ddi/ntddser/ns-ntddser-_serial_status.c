typedef struct _SERIAL_STATUS {
  ULONG   Errors;
  ULONG   HoldReasons;
  ULONG   AmountInInQueue;
  ULONG   AmountInOutQueue;
  BOOLEAN EofReceived;
  BOOLEAN WaitForImmediate;
} SERIAL_STATUS, *PSERIAL_STATUS;