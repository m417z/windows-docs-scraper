ULONG PerfQueryCounterInfo(
  [in]            HANDLE                   hQuery,
  [out, optional] PPERF_COUNTER_IDENTIFIER pCounters,
                  DWORD                    cbCounters,
  [out]           LPDWORD                  pcbCountersActual
);