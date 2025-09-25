DWORD FwpmProviderSubscribeChanges0(
  [in]           HANDLE                            engineHandle,
  [in, optional] const FWPM_PROVIDER_SUBSCRIPTION0 *subscription,
  [in]           FWPM_PROVIDER_CHANGE_CALLBACK0    callback,
  [in, optional] void                              *context,
  [out]          HANDLE                            *changeHandle
);