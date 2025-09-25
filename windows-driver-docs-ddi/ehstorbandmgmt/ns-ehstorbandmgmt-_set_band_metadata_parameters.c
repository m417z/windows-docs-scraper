typedef struct _SET_BAND_METADATA_PARAMETERS {
  ULONG         StructSize;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         MetadataOffset;
  ULONG         MetadataSize;
  ULONG         BufferOffset;
  ULONG         AuthKeyOffset;
} SET_BAND_METADATA_PARAMETERS, *PSET_BAND_METADATA_PARAMETERS;