typedef union _DEVICE_BUS_SPECIFIC_RESET_TYPE {
  struct {
    ULONGLONG FunctionLevelDeviceReset : 1;
    ULONGLONG PlatformLevelDeviceReset : 1;
    ULONGLONG SecondaryBusReset : 1;
    ULONGLONG PowerControllerReset : 1;
    ULONGLONG NoOpReset : 1;
    ULONGLONG Reserved : 59;
  } Pci;
  struct {
    ULONGLONG FunctionLevelDeviceReset : 1;
    ULONGLONG PlatformLevelDeviceReset : 1;
    ULONGLONG Reserved : 62;
  } Acpi;
  ULONGLONG AsULONGLONG;
} DEVICE_BUS_SPECIFIC_RESET_TYPE, *PDEVICE_BUS_SPECIFIC_RESET_TYPE;