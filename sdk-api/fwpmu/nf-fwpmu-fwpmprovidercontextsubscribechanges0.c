DWORD FwpmProviderContextSubscribeChanges0(
  [in]           HANDLE                                    engineHandle,
  [in]           const FWPM_PROVIDER_CONTEXT_SUBSCRIPTION0 *subscription,
  [in]           FWPM_PROVIDER_CONTEXT_CHANGE_CALLBACK0    callback,
  [in, optional] void                                      *context,
  [out]          HANDLE                                    *changeHandle
);