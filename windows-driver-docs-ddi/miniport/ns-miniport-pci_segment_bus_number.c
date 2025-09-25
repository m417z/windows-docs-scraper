typedef struct _PCI_SEGMENT_BUS_NUMBER {
  union {
    struct {
      ULONG BusNumber : 8;
      ULONG SegmentNumber : 16;
      ULONG Reserved : 8;
    } bits;
    ULONG AsULONG;
  } u;
} PCI_SEGMENT_BUS_NUMBER, *PPCI_SEGMENT_BUS_NUMBER;