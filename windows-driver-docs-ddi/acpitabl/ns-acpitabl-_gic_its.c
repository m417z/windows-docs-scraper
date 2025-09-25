typedef struct _GIC_ITS {
  UCHAR     Type;
  UCHAR     Length;
  USHORT    Reserved1;
  ULONG     Identifier;
  ULONGLONG PhysicalAddress;
  ULONG     Reserved2;
} GIC_ITS;