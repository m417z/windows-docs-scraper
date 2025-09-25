typedef union _PCI_EXPRESS_AER_CAPABILITIES {
  struct {
    ULONG FirstErrorPointer  :5;
    ULONG ECRCGenerationCapable  :1;
    ULONG ECRCGenerationEnable  :1;
    ULONG ECRCCheckCapable  :1;
    ULONG ECRCCheckEnable  :1;
    ULONG Reserved  :23;
  };
  ULONG  AsULONG;
} PCI_EXPRESS_AER_CAPABILITIES, *PPCI_EXPRESS_AER_CAPABILITIES;