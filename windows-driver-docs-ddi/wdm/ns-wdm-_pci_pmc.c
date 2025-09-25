typedef struct _PCI_PMC {
  UCHAR              Version  :3;
  UCHAR              PMEClock  :1;
  UCHAR              Rsvd1  :1;
  UCHAR              DeviceSpecificInitialization  :1;
  UCHAR              Rsvd2  :2;
  struct _PM_SUPPORT {
    UCHAR Rsvd2  :1;
    UCHAR D1  :1;
    UCHAR D2  :1;
    UCHAR PMED0  :1;
    UCHAR PMED1  :1;
    UCHAR PMED2  :1;
    UCHAR PMED3Hot  :1;
    UCHAR PMED3Cold  :1;
  } Support;
} PCI_PMC, *PPCI_PMC;