typedef struct _WHEA_ERROR_SOURCE_OVERRIDE_SETTINGS {
  WHEA_ERROR_SOURCE_TYPE Type;
  ULONG                  MaxRawDataLength;
  ULONG                  NumRecordsToPreallocate;
  ULONG                  MaxSectionsPerRecord;
} WHEA_ERROR_SOURCE_OVERRIDE_SETTINGS, *PWHEA_ERROR_SOURCE_OVERRIDE_SETTINGS;