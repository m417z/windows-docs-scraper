typedef struct _DEVICE_RESET_INTERFACE_STANDARD {
  USHORT                                   Size;
  USHORT                                   Version;
  PVOID                                    Context;
  PINTERFACE_REFERENCE                     InterfaceReference;
  PINTERFACE_DEREFERENCE                   InterfaceDereference;
  PDEVICE_RESET_HANDLER                    DeviceReset;
  ULONG                                    SupportedResetTypes;
  PVOID                                    Reserved;
  PDEVICE_QUERY_BUS_SPECIFIC_RESET_HANDLER QueryBusSpecificResetInfo;
  PDEVICE_BUS_SPECIFIC_RESET_HANDLER       DeviceBusSpecificReset;
  PGET_DEVICE_RESET_STATUS                 GetDeviceResetStatus;
} DEVICE_RESET_INTERFACE_STANDARD, *PDEVICE_RESET_INTERFACE_STANDARD;