typedef struct _VPCI_INTERFACE_STANDARD {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PVPCI_WRITE_BLOCK      WriteVfConfigBlock;
  PVPCI_READ_BLOCK       ReadVfConfigBlock;
  UINT32                 SerialNumber;
} VPCI_INTERFACE_STANDARD, *PVPCI_INTERFACE_STANDARD;