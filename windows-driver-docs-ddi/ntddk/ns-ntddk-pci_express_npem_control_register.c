typedef union _PCI_EXPRESS_NPEM_CONTROL_REGISTER {
  struct {
    ULONG Enable : 1;
    ULONG InitiateReset : 1;
    ULONG OkControl : 1;
    ULONG LocateControl : 1;
    ULONG FailControl : 1;
    ULONG RebuildControl : 1;
    ULONG PFAControl : 1;
    ULONG HotSpareControl : 1;
    ULONG InACriticalArrayControl : 1;
    ULONG InAFailedArrayControl : 1;
    ULONG InvalidDeviceTypeControl : 1;
    ULONG DisabledControl : 1;
    ULONG Rsvd : 12;
    ULONG EnclosureSpecificControls : 8;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_NPEM_CONTROL_REGISTER, *PPCI_EXPRESS_NPEM_CONTROL_REGISTER;