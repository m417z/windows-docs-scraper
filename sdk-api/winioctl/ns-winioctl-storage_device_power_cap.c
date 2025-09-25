typedef struct _STORAGE_DEVICE_POWER_CAP {
  DWORD                          Version;
  DWORD                          Size;
  STORAGE_DEVICE_POWER_CAP_UNITS Units;
  DWORDLONG                      MaxPower;
} STORAGE_DEVICE_POWER_CAP, *PSTORAGE_DEVICE_POWER_CAP;