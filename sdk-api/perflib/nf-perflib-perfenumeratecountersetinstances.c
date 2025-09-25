ULONG PerfEnumerateCounterSetInstances(
  [in, optional]  LPCWSTR               szMachine,
  [in]            LPCGUID               pCounterSetId,
  [out, optional] PPERF_INSTANCE_HEADER pInstances,
                  DWORD                 cbInstances,
  [out]           LPDWORD               pcbInstancesActual
);