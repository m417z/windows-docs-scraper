typedef struct {
  ULONG   PacketNumber;
  DWORD   Flags;
  ULONG64 PerformanceCounterValue;
  BOOL    MoreData;
} KSRTAUDIO_GETREADPACKET_INFO, *PKSRTAUDIO_GETREADPACKET_INFO;