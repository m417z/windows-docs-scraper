typedef union {
  struct {
    ULONG         EpIndex;
    PKSDATAFORMAT Format;
    ULONG         SiopCount;
  };
  LONGLONG Alignment;
} SIDEBANDAUDIO_STREAM_OPEN_PARAMS, *PSIDEBANDAUDIO_STREAM_OPEN_PARAMS;