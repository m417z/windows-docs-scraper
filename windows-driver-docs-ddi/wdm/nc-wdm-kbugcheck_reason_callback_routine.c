KBUGCHECK_REASON_CALLBACK_ROUTINE KbugcheckReasonCallbackRoutine;

VOID KbugcheckReasonCallbackRoutine(
  [in]      KBUGCHECK_CALLBACK_REASON Reason,
  [in]      _KBUGCHECK_REASON_CALLBACK_RECORD *Record,
  [in, out] PVOID ReasonSpecificData,
  [in]      ULONG ReasonSpecificDataLength
)
{...}