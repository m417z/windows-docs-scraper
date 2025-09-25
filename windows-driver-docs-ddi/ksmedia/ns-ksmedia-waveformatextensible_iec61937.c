typedef struct {
  WAVEFORMATEXTENSIBLE FormatExt;
  DWORD                dwEncodedSamplesPerSec;
  DWORD                dwEncodedChannelCount;
  DWORD                dwAverageBytesPerSec;
} WAVEFORMATEXTENSIBLE_IEC61937, *PWAVEFORMATEXTENSIBLE_IEC61937;