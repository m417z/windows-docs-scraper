typedef struct _USBDEVICE_ENABLE_FAILURE_FLAGS {
  ULONG InsufficientHardwareResourcesForDefaultEndpoint : 1;
  ULONG InsufficientHardwareResourcesForDevice : 1;
  ULONG Reserved : 30;
} USBDEVICE_ENABLE_FAILURE_FLAGS;