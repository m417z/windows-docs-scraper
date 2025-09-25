typedef struct _DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT {
  ULONG                        Version;
  ULONG                        Flags;
  ULONG                        TotalNumberOfRanges;
  ULONG                        NumberOfRangesReturned;
  DEVICE_STORAGE_ADDRESS_RANGE Ranges[ANYSIZE_ARRAY];
} DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT, *PDEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT;