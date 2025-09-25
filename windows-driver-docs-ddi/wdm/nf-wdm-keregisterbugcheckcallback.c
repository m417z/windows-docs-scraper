BOOLEAN KeRegisterBugCheckCallback(
  [out]          PKBUGCHECK_CALLBACK_RECORD  CallbackRecord,
  [in]           PKBUGCHECK_CALLBACK_ROUTINE CallbackRoutine,
  [in, optional] PVOID                       Buffer,
  [in]           ULONG                       Length,
  [in]           PUCHAR                      Component
);