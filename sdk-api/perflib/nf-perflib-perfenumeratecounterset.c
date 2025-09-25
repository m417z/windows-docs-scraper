ULONG PerfEnumerateCounterSet(
  [in, optional]  LPCWSTR szMachine,
  [out, optional] LPGUID  pCounterSetIds,
                  DWORD   cCounterSetIds,
  [out]           LPDWORD pcCounterSetIdsActual
);