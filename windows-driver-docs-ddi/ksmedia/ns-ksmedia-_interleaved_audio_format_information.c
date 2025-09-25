typedef struct {
  ULONG Size;
  DWORD PrimaryChannelCount;
  DWORD PrimaryChannelStartPosition;
  DWORD PrimaryChannelMask;
  DWORD InterleavedChannelCount;
  DWORD InterleavedChannelStartPosition;
  DWORD InterleavedChannelMask;
} INTERLEAVED_AUDIO_FORMAT_INFORMATION;