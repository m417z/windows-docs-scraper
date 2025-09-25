typedef struct _ACX_MICROPHONE_CONFIG {
  ULONG                                     Size;
  ULONG                                     Flags;
  LONG                                      MicrophoneSnrDB;
  LONG                                      MicrophoneSensitivityDB;
  ACXMICARRAYGEOMETRY                       MicArrayGeometry;
  PACX_INTERLEAVED_AUDIO_FORMAT_INFORMATION InterleavedFormat;
} ACX_MICROPHONE_CONFIG, *PACX_MICROPHONE_CONFIG;