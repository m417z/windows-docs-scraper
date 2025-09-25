BOOLEAN KeRegisterBugCheckReasonCallback(
  [out] PKBUGCHECK_REASON_CALLBACK_RECORD  CallbackRecord,
  [in]  PKBUGCHECK_REASON_CALLBACK_ROUTINE CallbackRoutine,
  [in]  KBUGCHECK_CALLBACK_REASON          Reason,
  [in]  PUCHAR                             Component
);