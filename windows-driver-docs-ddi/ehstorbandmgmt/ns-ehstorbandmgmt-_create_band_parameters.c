typedef struct _CREATE_BAND_PARAMETERS {
  ULONG StructSize;
  ULONG Flags;
  ULONG BandLocationInfoOffset;
  ULONG BandSecurityInfoOffset;
  ULONG AuthKeyOffset;
} CREATE_BAND_PARAMETERS, *PCREATE_BAND_PARAMETERS;