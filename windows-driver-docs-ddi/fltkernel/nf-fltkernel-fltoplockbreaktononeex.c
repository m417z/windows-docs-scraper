FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockBreakToNoneEx(
  [in]           POPLOCK                                 Oplock,
  [in]           PFLT_CALLBACK_DATA                      CallbackData,
  [in]           ULONG                                   Flags,
  [in, optional] PVOID                                   Context,
  [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE        WaitCompletionRoutine,
  [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);