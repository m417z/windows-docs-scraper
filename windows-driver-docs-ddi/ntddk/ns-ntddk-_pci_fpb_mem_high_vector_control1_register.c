typedef union _PCI_FPB_MEM_HIGH_VECTOR_CONTROL1_REGISTER {
  struct {
    ULONG MemHighDecodeMechanismEnable : 1;
    ULONG Rsvd0 : 3;
    ULONG MemHighVectorGranularity : 4;
    ULONG Rsvd1 : 20;
    ULONG MemHighVectorStartLower : 4;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_FPB_MEM_HIGH_VECTOR_CONTROL1_REGISTER, *PPCI_FPB_MEM_HIGH_VECTOR_CONTROL1_REGISTER;