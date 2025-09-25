typedef union {
  struct {
    ULONG                         EpIndex;
    SIDEBANDAUDIO_IO_PARAM_HEADER RequestedSiop;
  };
  LONGLONG Alignment;
} SIDEBANDAUDIO_SIOP_REQUEST_PARAM, *PSIDEBANDAUDIO_SIOP_REQUEST_PARAM;