PPO_ENUMERATE_INTERRUPT_SOURCE_CALLBACK PpoEnumerateInterruptSourceCallback;

BOOLEAN PpoEnumerateInterruptSourceCallback(
  [in] PVOID CallbackContext,
  [in] PPEP_UNMASKED_INTERRUPT_INFORMATION InterruptInformation
)
{...}