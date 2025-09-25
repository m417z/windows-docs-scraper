typedef enum _KBUGCHECK_CALLBACK_REASON {
  KbCallbackInvalid,
  KbCallbackReserved1,
  KbCallbackSecondaryDumpData,
  KbCallbackDumpIo,
  KbCallbackAddPages,
  KbCallbackSecondaryMultiPartDumpData,
  KbCallbackRemovePages,
  KbCallbackTriageDumpData,
  KbCallbackReserved2,
  KbCallbackReserved3
} KBUGCHECK_CALLBACK_REASON;