typedef struct _PCI_ATS_INTERFACE {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  PPCI_SET_ATS           SetAddressTranslationServices;
  UCHAR                  InvalidateQueueDepth;
} PCI_ATS_INTERFACE, *PPCI_ATS_INTERFACE;