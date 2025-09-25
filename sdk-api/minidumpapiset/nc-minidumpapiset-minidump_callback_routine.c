MINIDUMP_CALLBACK_ROUTINE MinidumpCallbackRoutine;

BOOL MinidumpCallbackRoutine(
  [in]      PVOID CallbackParam,
  [in]      PMINIDUMP_CALLBACK_INPUT CallbackInput,
  [in, out] PMINIDUMP_CALLBACK_OUTPUT CallbackOutput
)
{...}