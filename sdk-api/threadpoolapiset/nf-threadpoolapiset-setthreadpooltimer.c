VOID SetThreadpoolTimer(
  [in, out]      PTP_TIMER pti,
  [in, optional] PFILETIME pftDueTime,
  [in]           DWORD     msPeriod,
  [in]           DWORD     msWindowLength
);