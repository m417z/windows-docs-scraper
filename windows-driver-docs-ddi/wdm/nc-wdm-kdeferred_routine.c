KDEFERRED_ROUTINE KdeferredRoutine;

VOID KdeferredRoutine(
  [in]           _KDPC *Dpc,
  [in, optional] PVOID DeferredContext,
  [in, optional] PVOID SystemArgument1,
  [in, optional] PVOID SystemArgument2
)
{...}