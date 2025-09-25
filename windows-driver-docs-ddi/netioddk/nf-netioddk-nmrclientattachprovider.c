NTSTATUS NmrClientAttachProvider(
  [in]  HANDLE                 NmrBindingHandle,
  [in]  __drv_aliasesMem PVOID ClientBindingContext,
  [in]  const VOID             *ClientDispatch,
  [out] PVOID                  *ProviderBindingContext,
  [out] const VOID             **ProviderDispatch
);