typedef struct _PCI_PM_CAPABILITY {
  PCI_CAPABILITIES_HEADER Header;
  union {
    PCI_PMC Capabilities;
    USHORT  AsUSHORT;
  } PMC;
  union {
    PCI_PMCSR ControlStatus;
    USHORT    AsUSHORT;
  } PMCSR;
  union {
    PCI_PMCSR_BSE BridgeSupport;
    UCHAR         AsUCHAR;
  } PMCSR_BSE;
  UCHAR                   Data;
} PCI_PM_CAPABILITY, *PPCI_PM_CAPABILITY;