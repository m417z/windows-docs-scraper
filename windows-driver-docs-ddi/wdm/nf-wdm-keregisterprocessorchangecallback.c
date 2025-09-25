PVOID KeRegisterProcessorChangeCallback(
  [in]           PPROCESSOR_CALLBACK_FUNCTION CallbackFunction,
  [in, optional] PVOID                        CallbackContext,
  [in]           ULONG                        Flags
);