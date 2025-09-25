typedef struct _STORAGE_DEVICE_POWER_CAP {
  ULONG                          Version;
  ULONG                          Size;
  STORAGE_DEVICE_POWER_CAP_UNITS Units;
  ULONGLONG                      MaxPower;
} STORAGE_DEVICE_POWER_CAP, *PSTORAGE_DEVICE_POWER_CAP;