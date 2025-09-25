PFNKSSETTIMER Pfnkssettimer;

BOOLEAN Pfnkssettimer(
  [in] PVOID Context,
  [in] PKTIMER Timer,
  [in] LARGE_INTEGER DueTime,
  [in] PKDPC Dpc
)
{...}