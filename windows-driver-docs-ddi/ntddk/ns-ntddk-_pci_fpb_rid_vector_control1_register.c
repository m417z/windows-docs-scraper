typedef union _PCI_FPB_RID_VECTOR_CONTROL1_REGISTER {
  struct {
    ULONG RidDecodeMechanismEnable : 1;
    ULONG Rsvd0 : 3;
    ULONG RidVectorGranularity : 4;
    ULONG Rsvd1 : 11;
    ULONG RidVectorStart : 13;
  } DUMMYSTRUCTNAME;
  ULONG  AsULONG;
} PCI_FPB_RID_VECTOR_CONTROL1_REGISTER, *PPCI_FPB_RID_VECTOR_CONTROL1_REGISTER;