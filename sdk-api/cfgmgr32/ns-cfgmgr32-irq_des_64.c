typedef struct IRQ_Des_64_s {
  DWORD   IRQD_Count;
  DWORD   IRQD_Type;
#if ...
  USHORT  IRQD_Flags;
  USHORT  IRQD_Group;
#else
  DWORD   IRQD_Flags;
#endif
  ULONG   IRQD_Alloc_Num;
  ULONG64 IRQD_Affinity;
} IRQ_DES_64, *PIRQ_DES_64;