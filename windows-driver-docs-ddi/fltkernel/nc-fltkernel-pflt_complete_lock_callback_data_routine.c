PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE PfltCompleteLockCallbackDataRoutine;

NTSTATUS PfltCompleteLockCallbackDataRoutine(
  [in, optional] PVOID Context,
  [in]           PFLT_CALLBACK_DATA CallbackData
)
{...}