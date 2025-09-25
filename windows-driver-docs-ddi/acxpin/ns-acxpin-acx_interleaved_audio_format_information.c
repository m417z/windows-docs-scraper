typedef struct _ACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION {
  ULONG Size;
  ULONG PrimaryChannelCount;
  ULONG PrimaryChannelStartPosition;
  ULONG PrimaryChannelMask;
  ULONG InterleavedChannelCount;
  ULONG InterleavedChannelStartPosition;
  ULONG InterleavedChannelMask;
} ACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION, *PACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION;