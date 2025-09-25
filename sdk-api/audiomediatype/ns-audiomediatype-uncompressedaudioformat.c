typedef struct _UNCOMPRESSEDAUDIOFORMAT {
  GUID  guidFormatType;
  DWORD dwSamplesPerFrame;
  DWORD dwBytesPerSampleContainer;
  DWORD dwValidBitsPerSample;
  FLOAT fFramesPerSecond;
  DWORD dwChannelMask;
} UNCOMPRESSEDAUDIOFORMAT;