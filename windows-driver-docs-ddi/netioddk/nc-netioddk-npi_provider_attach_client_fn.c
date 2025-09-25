NPI_PROVIDER_ATTACH_CLIENT_FN NpiProviderAttachClientFn;

NTSTATUS NpiProviderAttachClientFn(
  [in]  HANDLE NmrBindingHandle,
  [in]  PVOID ProviderContext,
  [in]  PNPI_REGISTRATION_INSTANCE ClientRegistrationInstance,
  [in]  PVOID ClientBindingContext,
  [in]  const VOID *ClientDispatch,
  [out] PVOID *ProviderBindingContext,
  [out] const VOID **ProviderDispatch
)
{...}