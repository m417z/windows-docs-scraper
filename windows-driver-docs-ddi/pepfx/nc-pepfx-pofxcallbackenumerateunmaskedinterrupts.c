POFXCALLBACKENUMERATEUNMASKEDINTERRUPTS Pofxcallbackenumerateunmaskedinterrupts;

NTSTATUS Pofxcallbackenumerateunmaskedinterrupts(
  [in, optional] POHANDLE PluginHandle,
  [in, optional] ULONG EnumerateFlags,
  [in]           PPO_ENUMERATE_INTERRUPT_SOURCE_CALLBACK Callback,
  [in]           PVOID CallbackContext,
  [in, out]      PPEP_UNMASKED_INTERRUPT_INFORMATION InterruptInformation
)
{...}