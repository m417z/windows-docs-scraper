typedef struct _PCI_EXPRESS_LINK_QUIESCENT_INTERFACE {
  USHORT                                 Size;
  USHORT                                 Version;
  PVOID                                  Context;
  PINTERFACE_REFERENCE                   InterfaceReference;
  PINTERFACE_DEREFERENCE                 InterfaceDereference;
  PPCI_EXPRESS_ENTER_LINK_QUIESCENT_MODE PciExpressEnterLinkQuiescentMode;
  PPCI_EXPRESS_EXIT_LINK_QUIESCENT_MODE  PciExpressExitLinkQuiescentMode;
} PCI_EXPRESS_LINK_QUIESCENT_INTERFACE, *PPCI_EXPRESS_LINK_QUIESCENT_INTERFACE;