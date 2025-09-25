typedef struct _PEP_QUERY_SOC_SUBSYSTEM_COUNT {
  [in]  ULONG PlatformIdleStateIndex;
  [out] ULONG SubsystemCount;
        ULONG Flags;
} PEP_QUERY_SOC_SUBSYSTEM_COUNT, *PPEP_QUERY_SOC_SUBSYSTEM_COUNT;