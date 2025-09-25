EX_CALLBACK_FUNCTION ExCallbackFunction;

NTSTATUS ExCallbackFunction(
  [in]           PVOID CallbackContext,
  [in, optional] PVOID Argument1,
  [in, optional] PVOID Argument2
)
{...}