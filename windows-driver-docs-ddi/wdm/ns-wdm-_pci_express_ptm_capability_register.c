typedef union _PCI_EXPRESS_PTM_CAPABILITY_REGISTER {
  struct {
    ULONG RequesterCapable : 1;
    ULONG ResponderCapable : 1;
    ULONG RootCapable : 1;
    ULONG Rsvd : 5;
    ULONG LocalGranularity : 8;
    ULONG Rsvd2 : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_PTM_CAPABILITY_REGISTER, *PPCI_EXPRESS_PTM_CAPABILITY_REGISTER;