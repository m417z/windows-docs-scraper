typedef struct _PCI_MSIX_TABLE_CONFIG_INTERFACE {
  USHORT                     Size;
  USHORT                     Version;
  PVOID                      Context;
  PINTERFACE_REFERENCE       InterfaceReference;
  PINTERFACE_DEREFERENCE     InterfaceDereference;
  PPCI_MSIX_SET_ENTRY        SetTableEntry;
  PPCI_MSIX_MASKUNMASK_ENTRY MaskTableEntry;
  PPCI_MSIX_MASKUNMASK_ENTRY UnmaskTableEntry;
  PPCI_MSIX_GET_ENTRY        GetTableEntry;
  PPCI_MSIX_GET_TABLE_SIZE   GetTableSize;
} PCI_MSIX_TABLE_CONFIG_INTERFACE, *PPCI_MSIX_TABLE_CONFIG_INTERFACE;