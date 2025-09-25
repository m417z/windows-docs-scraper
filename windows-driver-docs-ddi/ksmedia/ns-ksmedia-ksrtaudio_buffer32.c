typedef struct {
  ULONG BufferAddress;
  ULONG ActualBufferSize;
  BOOL  CallMemoryBarrier;
} KSRTAUDIO_BUFFER32, *PKSRTAUDIO_BUFFER32;