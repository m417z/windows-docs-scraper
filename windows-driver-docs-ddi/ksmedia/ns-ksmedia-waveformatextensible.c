typedef struct {
  WAVEFORMATEX Format;
  union {
    WORD wValidBitsPerSample;
    WORD wSamplesPerBlock;
    WORD wReserved;
  } Samples;
  DWORD        dwChannelMask;
  GUID         SubFormat;
} WAVEFORMATEXTENSIBLE, *PWAVEFORMATEXTENSIBLE;