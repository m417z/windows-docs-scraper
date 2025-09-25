typedef struct {
  USHORT Identifier;
  USHORT ENDGID;
  ULONG  Reserved1;
  ULONG  Random4KBReadTypical;
  ULONG  OptimalWriteSize;
  UCHAR  TotalCapacity[16];
  UCHAR  UnallocatedCapacity[16];
  UCHAR  Reserved2[80];
} NVME_SET_ATTRIBUTES_ENTRY, *PNVME_SET_ATTRIBUTES_ENTRY;