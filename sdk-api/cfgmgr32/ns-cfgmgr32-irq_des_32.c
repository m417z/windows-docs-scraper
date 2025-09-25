typedef struct IRQ_Des_32_s {
  DWORD   IRQD_Count;
  DWORD   IRQD_Type;
#if ...
  USHORT  IRQD_Flags;
  USHORT  IRQD_Group;
#else
  DWORD   IRQD_Flags;
#endif
  ULONG   IRQD_Alloc_Num;
  ULONG32 IRQD_Affinity;
} IRQ_DES_32, *PIRQ_DES_32;