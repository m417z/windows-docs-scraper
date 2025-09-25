typedef struct _REFS_SMR_VOLUME_GC_PARAMETERS {
  ULONG                     Version;
  ULONG                     Flags;
  REFS_SMR_VOLUME_GC_ACTION Action;
  REFS_SMR_VOLUME_GC_METHOD Method;
  ULONG                     IoGranularity;
  ULONG                     CompressionFormat;
  ULONGLONG                 Unused[8];
} REFS_SMR_VOLUME_GC_PARAMETERS, *PREFS_SMR_VOLUME_GC_PARAMETERS;