typedef struct _HID_MINIDRIVER_REGISTRATION {
  ULONG           Revision;
  PDRIVER_OBJECT  DriverObject;
  PUNICODE_STRING RegistryPath;
  ULONG           DeviceExtensionSize;
  BOOLEAN         DevicesArePolled;
  UCHAR           Reserved[3];
} HID_MINIDRIVER_REGISTRATION, *PHID_MINIDRIVER_REGISTRATION;