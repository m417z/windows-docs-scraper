typedef struct _BAND_LOCATION_INFO {
  ULONG         StructSize;
  ULONG         Reserved;
  LARGE_INTEGER BandStart;
  LARGE_INTEGER BandSize;
  BYTE          Metadata[32];
} BAND_LOCATION_INFO, *PBAND_LOCATION_INFO;