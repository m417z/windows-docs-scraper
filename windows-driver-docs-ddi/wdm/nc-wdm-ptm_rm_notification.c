PTM_RM_NOTIFICATION PtmRmNotification;

NTSTATUS PtmRmNotification(
  [in]      PKENLISTMENT EnlistmentObject,
  [in]      PVOID RMContext,
  [in]      PVOID TransactionContext,
  [in]      ULONG TransactionNotification,
  [in, out] PLARGE_INTEGER TmVirtualClock,
  [in]      ULONG ArgumentLength,
  [in]      PVOID Argument
)
{...}