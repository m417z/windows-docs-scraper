NPI_CLIENT_ATTACH_PROVIDER_FN NpiClientAttachProviderFn;

NTSTATUS NpiClientAttachProviderFn(
  [in] HANDLE NmrBindingHandle,
  [in] PVOID ClientContext,
  [in] PNPI_REGISTRATION_INSTANCE ProviderRegistrationInstance
)
{...}