typedef union _PCI_FPB_MEM_LOW_VECTOR_CONTROL_REGISTER {
  struct {
    ULONG MemLowDecodeMechanismEnable : 1;
    ULONG Rsvd0 : 3;
    ULONG MemLowVectorGranularity : 4;
    ULONG Rsvd1 : 12;
    ULONG MemLowVectorStart : 12;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_FPB_MEM_LOW_VECTOR_CONTROL_REGISTER, *PPCI_FPB_MEM_LOW_VECTOR_CONTROL_REGISTER;