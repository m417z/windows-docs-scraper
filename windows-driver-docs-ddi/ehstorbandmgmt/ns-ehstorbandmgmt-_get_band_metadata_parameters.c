typedef struct _GET_BAND_METADATA_PARAMETERS {
  ULONG         StructSize;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         MetadataOffset;
  ULONG         MetadataSize;
} GET_BAND_METADATA_PARAMETERS, *PGET_BAND_METADATA_PARAMETERS;