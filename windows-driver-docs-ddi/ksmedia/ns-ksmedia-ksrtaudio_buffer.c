typedef struct {
  PVOID BufferAddress;
  ULONG ActualBufferSize;
  BOOL  CallMemoryBarrier;
} KSRTAUDIO_BUFFER, *PKSRTAUDIO_BUFFER;