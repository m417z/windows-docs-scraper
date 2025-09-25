typedef struct _SET_BAND_SECURITY_PARAMETERS {
  ULONG         StructSize;
  ULONG         Flags;
  ULONG         Reserved;
  ULONG         BandId;
  LARGE_INTEGER BandStart;
  ULONG         CurrentAuthKeyOffset;
  ULONG         NewAuthKeyOffset;
  ULONG         BandSecurityInfoOffset;
} SET_BAND_SECURITY_PARAMETERS, *PSET_BAND_SECURITY_PARAMETERS;