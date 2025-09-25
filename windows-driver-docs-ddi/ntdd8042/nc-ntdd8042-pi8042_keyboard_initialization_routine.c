PI8042_KEYBOARD_INITIALIZATION_ROUTINE Pi8042KeyboardInitializationRoutine;

NTSTATUS Pi8042KeyboardInitializationRoutine(
  [in]  PVOID InitializationContext,
  [in]  PVOID SynchFuncContext,
  [in]  PI8042_SYNCH_READ_PORT ReadPort,
  [in]  PI8042_SYNCH_WRITE_PORT WritePort,
  [out] PBOOLEAN TurnTranslationOn
)
{...}