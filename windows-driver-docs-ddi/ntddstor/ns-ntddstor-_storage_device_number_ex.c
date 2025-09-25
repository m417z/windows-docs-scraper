typedef struct _STORAGE_DEVICE_NUMBER_EX {
  ULONG       Version;
  ULONG       Size;
  ULONG       Flags;
  DEVICE_TYPE DeviceType;
  ULONG       DeviceNumber;
  GUID        DeviceGuid;
  ULONG       PartitionNumber;
} STORAGE_DEVICE_NUMBER_EX, *PSTORAGE_DEVICE_NUMBER_EX;