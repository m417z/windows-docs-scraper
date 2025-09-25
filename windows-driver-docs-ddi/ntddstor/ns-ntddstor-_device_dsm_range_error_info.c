typedef struct _DEVICE_DSM_RANGE_ERROR_INFO {
  ULONG                           Version;
  ULONG                           Flags;
  ULONG                           TotalNumberOfRanges;
  ULONG                           NumberOfRangesReturned;
  DEVICE_STORAGE_RANGE_ATTRIBUTES Ranges[ANYSIZE_ARRAY];
} DEVICE_DSM_RANGE_ERROR_INFO, *PDEVICE_DSM_RANGE_ERROR_INFO, DEVICE_DSM_RANGE_ERROR_OUTPUT, *PDEVICE_DSM_RANGE_ERROR_OUTPUT;