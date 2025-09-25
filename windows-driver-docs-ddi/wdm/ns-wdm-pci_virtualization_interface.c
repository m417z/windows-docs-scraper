typedef struct _PCI_VIRTUALIZATION_INTERFACE {
  USHORT                            Size;
  USHORT                            Version;
  PVOID                             Context;
  PINTERFACE_REFERENCE              InterfaceReference;
  PINTERFACE_DEREFERENCE            InterfaceDereference;
  PSET_VIRTUAL_DEVICE_DATA          SetVirtualFunctionData;
  PGET_VIRTUAL_DEVICE_DATA          GetVirtualFunctionData;
  PGET_VIRTUAL_DEVICE_LOCATION      GetLocation;
  PGET_VIRTUAL_DEVICE_RESOURCES     GetResources;
  PENABLE_VIRTUALIZATION            EnableVirtualization;
  PGET_VIRTUAL_FUNCTION_PROBED_BARS GetVirtualFunctionProbedBars;
} PCI_VIRTUALIZATION_INTERFACE, *PPCI_VIRTUALIZATION_INTERFACE;