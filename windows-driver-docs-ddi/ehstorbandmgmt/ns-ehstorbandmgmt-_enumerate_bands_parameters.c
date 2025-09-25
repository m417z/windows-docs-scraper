typedef struct _ENUMERATE_BANDS_PARAMETERS {
  ULONG         StructSize;
  ULONG         Flags;
  ULONG         Reserved;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  LARGE_INTEGER BandSize;
} ENUMERATE_BANDS_PARAMETERS, *PENUMERATE_BANDS_PARAMETERS;