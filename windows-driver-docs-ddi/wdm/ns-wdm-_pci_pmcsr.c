typedef struct _PCI_PMCSR {
  USHORT PowerState  :2;
  USHORT Rsvd1  :6;
  USHORT PMEEnable  :1;
  USHORT DataSelect  :4;
  USHORT DataScale  :2;
  USHORT PMEStatus  :1;
} PCI_PMCSR, *PPCI_PMCSR;