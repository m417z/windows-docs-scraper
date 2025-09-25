typedef struct _PCC_REDUCED_1_SUBSPACE {
  PCC_SUBSPACE_HEADER Header;
  ULONG               PlatformInterruptGsiv;
  union {
    struct {
      UCHAR PlatformInterruptPolarity : 1;
      UCHAR PlatformInterruptMode : 1;
      UCHAR Reserved1 : 6;
    };
    UCHAR PlatformInterruptFlags;
  };
  UCHAR               Reserved2;
  PHYSICAL_ADDRESS    BaseAddress;
  ULONGLONG           Length;
  GEN_ADDR            DoorbellRegister;
  ULONGLONG           DoorbellPreserve;
  ULONGLONG           DoorbellWrite;
  ULONG               NominalLatency;
  ULONG               MaximumPeriodicAccessRate;
  USHORT              MinimumRequestTurnaroundTime;
} PCC_REDUCED_1_SUBSPACE, *PPCC_REDUCED_1_SUBSPACE;