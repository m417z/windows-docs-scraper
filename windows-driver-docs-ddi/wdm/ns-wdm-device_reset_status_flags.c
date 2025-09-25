typedef union _DEVICE_RESET_STATUS_FLAGS {
  struct {
    ULONGLONG KeepStackReset : 1;
    ULONGLONG RecoveringFromBusError : 1;
    ULONGLONG Reserved : 62;
  } u;
  ULONGLONG AsUlonglong;
} DEVICE_RESET_STATUS_FLAGS, *PDEVICE_RESET_STATUS_FLAGS;