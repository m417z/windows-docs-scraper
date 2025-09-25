typedef struct _PERF_CONFIGURATION_DATA {
  ULONG           Version;
  ULONG           Size;
  ULONG           Flags;
  ULONG           ConcurrentChannels;
  ULONG           FirstRedirectionMessageNumber;
  ULONG           LastRedirectionMessageNumber;
  ULONG           DeviceNode;
  ULONG           Reserved;
  PGROUP_AFFINITY MessageTargets;
} PERF_CONFIGURATION_DATA, *PPERF_CONFIGURATION_DATA;