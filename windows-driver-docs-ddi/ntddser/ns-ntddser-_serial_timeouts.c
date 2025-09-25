typedef struct _SERIAL_TIMEOUTS {
  ULONG ReadIntervalTimeout;
  ULONG ReadTotalTimeoutMultiplier;
  ULONG ReadTotalTimeoutConstant;
  ULONG WriteTotalTimeoutMultiplier;
  ULONG WriteTotalTimeoutConstant;
} SERIAL_TIMEOUTS, *PSERIAL_TIMEOUTS;