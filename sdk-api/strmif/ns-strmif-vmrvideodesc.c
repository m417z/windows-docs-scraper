typedef struct _VMRVideoDesc {
  DWORD        dwSize;
  DWORD        dwSampleWidth;
  DWORD        dwSampleHeight;
  BOOL         SingleFieldPerSample;
  DWORD        dwFourCC;
  VMRFrequency InputSampleFreq;
  VMRFrequency OutputFrameFreq;
} VMRVideoDesc;