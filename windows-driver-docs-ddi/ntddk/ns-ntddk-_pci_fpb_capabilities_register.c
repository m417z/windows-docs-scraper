typedef union _PCI_FPB_CAPABILITIES_REGISTER {
  struct {
    ULONG RidDecodeMechanismSupported : 1;
    ULONG MemLowDecodeMechanismSupported : 1;
    ULONG MemHighDecodeMechanismSupported : 1;
    ULONG NumSecDev : 5;
    ULONG RidVectorSizeSupported : 3;
    ULONG Rsvd0 : 5;
    ULONG MemLowVectorSizeSupported : 3;
    ULONG Rsvd1 : 5;
    ULONG MemHighVectorSizeSupported : 3;
    ULONG Rsvd2 : 5;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_FPB_CAPABILITIES_REGISTER, *PPCI_FPB_CAPABILITIES_REGISTER;