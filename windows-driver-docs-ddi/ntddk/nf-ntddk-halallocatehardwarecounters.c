NTHALAPI NTSTATUS HalAllocateHardwareCounters(
        PGROUP_AFFINITY                 GroupAffinty,
  [in]  ULONG                           GroupCount,
  [in]  PPHYSICAL_COUNTER_RESOURCE_LIST ResourceList,
  [out] PHANDLE                         CounterSetHandle
);