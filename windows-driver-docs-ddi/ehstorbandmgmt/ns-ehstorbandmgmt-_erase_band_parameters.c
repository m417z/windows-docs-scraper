typedef struct _ERASE_BAND_PARAMETERS {
  ULONG         StructSize;
  ULONG         Flags;
  ULONG         Reserved;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         NewAuthKeyOffset;
} ERASE_BAND_PARAMETERS, *PERASE_BAND_PARAMETERS;