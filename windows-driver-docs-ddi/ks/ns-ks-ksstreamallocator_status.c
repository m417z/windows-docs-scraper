typedef struct {
  KSALLOCATOR_FRAMING Framing;
  ULONG               AllocatedFrames;
  ULONG               Reserved;
} KSSTREAMALLOCATOR_STATUS, *PKSSTREAMALLOCATOR_STATUS;