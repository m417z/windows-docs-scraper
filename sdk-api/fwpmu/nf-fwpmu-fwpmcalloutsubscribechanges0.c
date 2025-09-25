DWORD FwpmCalloutSubscribeChanges0(
  [in]           HANDLE                           engineHandle,
  [in]           const FWPM_CALLOUT_SUBSCRIPTION0 *subscription,
  [in]           FWPM_CALLOUT_CHANGE_CALLBACK0    callback,
  [in, optional] void                             *context,
  [out]          HANDLE                           *changeHandle
);