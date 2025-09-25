typedef struct _NFIT_PLATFORM_CAPABILITIES {
  NFIT_STRUCT_HEADER Header;
  UCHAR              HighestValidCapability;
  UCHAR              Reserved[3];
  union {
    ULONG AsUlong;
    struct {
      ULONG CpuCacheFlushOnPowerLoss : 1;
      ULONG MemCtrlrFlushOnPowerLoss : 1;
      ULONG PmemHardwareMirroring : 1;
    } u;
  } Capabilities;
  UCHAR              Reserved1[4];
} NFIT_PLATFORM_CAPABILITIES, *PNFIT_PLATFORM_CAPABILITIES;