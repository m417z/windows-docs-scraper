typedef struct _REGISTER_COMPOSITE_DEVICE {
  USHORT                        Version;
  USHORT                        Size;
  USBDI_HANDLE                  Reserved;
  COMPOSITE_DEVICE_CAPABILITIES CapabilityFlags;
  ULONG                         FunctionCount;
} REGISTER_COMPOSITE_DEVICE, *PREGISTER_COMPOSITE_DEVICE;