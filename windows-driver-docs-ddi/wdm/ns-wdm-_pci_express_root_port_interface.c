typedef struct _PCI_EXPRESS_ROOT_PORT_INTERFACE {
  USHORT                                    Size;
  USHORT                                    Version;
  PVOID                                     Context;
  PINTERFACE_REFERENCE                      InterfaceReference;
  PINTERFACE_DEREFERENCE                    InterfaceDereference;
  PPCI_EXPRESS_ROOT_PORT_READ_CONFIG_SPACE  ReadConfigSpace;
  PPCI_EXPRESS_ROOT_PORT_WRITE_CONFIG_SPACE WriteConfigSpace;
} PCI_EXPRESS_ROOT_PORT_INTERFACE, *PPCI_EXPRESS_ROOT_PORT_INTERFACE;