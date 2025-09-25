typedef struct _USBC_DEVICE_CONFIGURATION_INTERFACE_V1 {
  USHORT                     Size;
  USHORT                     Version;
  PVOID                      Context;
  PINTERFACE_REFERENCE       InterfaceReference;
  PINTERFACE_DEREFERENCE     InterfaceDereference;
  USBC_START_DEVICE_CALLBACK StartDeviceCallback;
  USBC_PDO_ENABLE_CALLBACK   PdoEnableCallback;
  PVOID                      Reserved[7];
} USBC_DEVICE_CONFIGURATION_INTERFACE_V1, *PUSBC_DEVICE_CONFIGURATION_INTERFACE_V1;