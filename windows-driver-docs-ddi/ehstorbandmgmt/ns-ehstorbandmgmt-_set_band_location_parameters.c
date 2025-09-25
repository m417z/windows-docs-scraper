typedef struct _SET_BAND_LOCATION_PARAMETERS {
  ULONG         StructSize;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         AuthKeyOffset;
  ULONG         BandLocationInfoOffset;
} SET_BAND_LOCATION_PARAMETERS, *PSET_BAND_LOCATION_PARAMETERS;