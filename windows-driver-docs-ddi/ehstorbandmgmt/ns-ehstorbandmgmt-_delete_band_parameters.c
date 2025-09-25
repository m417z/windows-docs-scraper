typedef struct _DELETE_BAND_PARAMETERS {
  ULONG         StructSize;
  ULONG         Flags;
  ULONG         Reserved;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         AuthKeyOffset;
} DELETE_BAND_PARAMETERS, *PDELETE_BAND_PARAMETERS;