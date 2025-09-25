typedef struct _SERIALPERF_STATS {
  ULONG ReceivedCount;
  ULONG TransmittedCount;
  ULONG FrameErrorCount;
  ULONG SerialOverrunErrorCount;
  ULONG BufferOverrunErrorCount;
  ULONG ParityErrorCount;
} SERIALPERF_STATS, *PSERIALPERF_STATS;