typedef struct _DXGK_SEGMENTFLAGS2 {
  union {
    struct {
      UINT Aperture : 1;
      UINT PopulatedFromSystemMemory : 1;
      UINT SystemMemoryReservedByBios : 1;
      UINT CpuVisible : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} DXGK_SEGMENTFLAGS2;