typedef struct _PCI_DEVICE_PRESENT_INTERFACE {
  USHORT                    Size;
  USHORT                    Version;
  PVOID                     Context;
  PINTERFACE_REFERENCE      InterfaceReference;
  PINTERFACE_DEREFERENCE    InterfaceDereference;
  PPCI_IS_DEVICE_PRESENT    IsDevicePresent;
  PPCI_IS_DEVICE_PRESENT_EX IsDevicePresentEx;
} PCI_DEVICE_PRESENT_INTERFACE, *PPCI_DEVICE_PRESENT_INTERFACE;