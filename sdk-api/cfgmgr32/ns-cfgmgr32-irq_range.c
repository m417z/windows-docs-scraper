typedef struct IRQ_Range_s {
  ULONG  IRQR_Min;
  ULONG  IRQR_Max;
#if ...
  USHORT IRQR_Flags;
  USHORT IRQR_Rsvdz;
#else
  ULONG  IRQR_Flags;
#endif
} IRQ_RANGE, *PIRQ_RANGE;