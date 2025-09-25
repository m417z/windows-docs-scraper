typedef union _PCI_EXPRESS_DPC_RP_PIO_STATUS_REGISTER {
  struct {
    ULONG CfgURCpl : 1;
    ULONG CfgCACpl : 1;
    ULONG CfgCTO : 1;
    ULONG Reserved1 : 5;
    ULONG IoURCpl : 1;
    ULONG IoCACpl : 1;
    ULONG IoCTO : 1;
    ULONG Reserved2 : 5;
    ULONG MemURCpl : 1;
    ULONG MemCACpl : 1;
    ULONG MemCTO : 1;
    ULONG Reserved3 : 12;
    ULONG Reserved4 : 1;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_DPC_RP_PIO_STATUS_REGISTER, *PPCI_EXPRESS_DPC_RP_PIO_STATUS_REGISTER;