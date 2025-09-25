typedef union _NPEM_CAPABILITY_STANDARD {
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
    ULONG Rsvd : 20;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} NPEM_CAPABILITY_STANDARD, *PNPEM_CAPABILITY_STANDARD;