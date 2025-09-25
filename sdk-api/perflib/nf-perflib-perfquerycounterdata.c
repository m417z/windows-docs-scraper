ULONG PerfQueryCounterData(
  [in]            HANDLE            hQuery,
  [out, optional] PPERF_DATA_HEADER pCounterBlock,
                  DWORD             cbCounterBlock,
  [out]           LPDWORD           pcbCounterBlockActual
);