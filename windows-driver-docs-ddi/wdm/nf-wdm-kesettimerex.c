BOOLEAN KeSetTimerEx(
  [in, out]      PKTIMER       Timer,
  [in]           LARGE_INTEGER DueTime,
  [in]           LONG          Period,
  [in, optional] PKDPC         Dpc
);