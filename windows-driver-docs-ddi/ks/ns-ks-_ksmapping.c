typedef struct _KSMAPPING {
  PHYSICAL_ADDRESS PhysicalAddress;
  ULONG            ByteCount;
  ULONG            Alignment;
} KSMAPPING, *PKSMAPPING;