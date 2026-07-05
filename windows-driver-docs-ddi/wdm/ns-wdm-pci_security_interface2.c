typedef struct _PCI_SECURITY_INTERFACE2 {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  ULONG                  Flags;
  ULONG                  SupportedScenarios;
  PPCI_SET_ACS2          SetAccessControlServices;
  PPCI_SET_ACS3          SetAccessControlServices3;
} PCI_SECURITY_INTERFACE2, *PPCI_SECURITY_INTERFACE2;