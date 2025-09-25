DWORD FwpmFilterSubscribeChanges0(
  [in]           HANDLE                          engineHandle,
  [in]           const FWPM_FILTER_SUBSCRIPTION0 *subscription,
  [in]           FWPM_FILTER_CHANGE_CALLBACK0    callback,
  [in, optional] void                            *context,
  [out]          HANDLE                          *changeHandle
);