BOOLEAN KeSetCoalescableTimer(
  [in, out]      PKTIMER       Timer,
  [in]           LARGE_INTEGER DueTime,
  [in]           ULONG         Period,
  [in]           ULONG         TolerableDelay,
  [in, optional] PKDPC         Dpc
);