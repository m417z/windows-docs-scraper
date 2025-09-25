typedef struct _KERNEL_CET_CONTEXT {
  ULONG64 Ssp;
  ULONG64 Rip;
  USHORT  SegCs;
  union {
    USHORT AllFlags;
    struct {
      USHORT UseWrss : 1;
      USHORT PopShadowStackOne : 1;
      USHORT Unused : 14;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  USHORT  Fill[2];
} KERNEL_CET_CONTEXT, *PKERNEL_CET_CONTEXT;