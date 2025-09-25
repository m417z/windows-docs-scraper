NTSTATUS EntropyRegisterCallback(
  ENTROPY_SOURCE_HANDLE             hEntropySource,
  PENTROPY_SOURCE_CALLBACK_FUNCTION pCallbackFunction,
  PVOID                             context
);