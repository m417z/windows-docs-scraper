typedef struct _PEP_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME {
  [in]  ULONG            PlatformIdleStateIndex;
  [in]  PVOID            SubsystemHandle;
  [in]  PCUNICODE_STRING SubsystemName;
  [out] ULONG64          BlockingTime;
        ULONG            Flags;
} PEP_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME, *PPEP_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME;