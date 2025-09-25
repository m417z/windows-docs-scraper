DWORD ClusWorkersTerminate(
  [in, out] PCLUS_WORKER *ClusWorkers,
  [in]      size_t const ClusWorkersCount,
  [in]      DWORD        TimeoutInMilliseconds,
  [in]      BOOL         WaitOnly
);