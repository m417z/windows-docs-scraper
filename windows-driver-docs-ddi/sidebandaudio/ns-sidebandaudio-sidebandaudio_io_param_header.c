typedef union {
  struct {
    GUID  ParamSet;
    ULONG TypeId;
    ULONG Size;
  };
  LONGLONG Alignment;
} SIDEBANDAUDIO_IO_PARAM_HEADER, *PSIDEBANDAUDIO_IO_PARAM_HEADER;