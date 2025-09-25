typedef struct _STREAM_TIME_REFERENCE {
  STREAM_TIMESTAMP CurrentOnboardClockValue;
  LARGE_INTEGER    OnboardClockFrequency;
  LARGE_INTEGER    CurrentSystemTime;
  ULONG            Reserved[2];
} STREAM_TIME_REFERENCE, *PSTREAM_TIME_REFERENCE;