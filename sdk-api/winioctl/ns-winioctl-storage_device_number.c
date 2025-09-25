typedef struct _STORAGE_DEVICE_NUMBER {
  DEVICE_TYPE DeviceType;
  DWORD       DeviceNumber;
  DWORD       PartitionNumber;
} STORAGE_DEVICE_NUMBER, *PSTORAGE_DEVICE_NUMBER;