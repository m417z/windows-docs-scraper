typedef union _PCI_EXPRESS_NPEM_CAPABILITY_REGISTER {
  struct {
    ULONG Capable : 1;
    ULONG ResetCapable : 1;
    ULONG OkCapable : 1;
    ULONG LocateCapable : 1;
    ULONG FailCapable : 1;
    ULONG RebuildCapable : 1;
    ULONG PFACapable : 1;
    ULONG HotSpareCapable : 1;
    ULONG InACriticalArrayCapable : 1;
    ULONG InAFailedArrayCapable : 1;
    ULONG InvalidDeviceTypeCapable : 1;
    ULONG DisabledCapable : 1;
    ULONG Rsvd : 12;
    ULONG EnclosureSpecificCapabilities : 8;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_EXPRESS_NPEM_CAPABILITY_REGISTER, *PPCI_EXPRESS_NPEM_CAPABILITY_REGISTER;