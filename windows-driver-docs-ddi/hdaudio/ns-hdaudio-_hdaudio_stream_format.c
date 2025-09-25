typedef struct _HDAUDIO_STREAM_FORMAT {
  ULONG  SampleRate;
  USHORT ValidBitsPerSample;
  USHORT ContainerSize;
  USHORT NumberOfChannels;
} HDAUDIO_STREAM_FORMAT, *PHDAUDIO_STREAM_FORMAT;