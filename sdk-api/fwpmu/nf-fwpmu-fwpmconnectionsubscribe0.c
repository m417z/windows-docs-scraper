DWORD FwpmConnectionSubscribe0(
  [in]           HANDLE                              engineHandle,
  [in]           const FWPM_CONNECTION_SUBSCRIPTION0 *subscription,
  [in]           FWPM_CONNECTION_CALLBACK0           callback,
  [in, optional] void                                *context,
  [out]          HANDLE                              *eventsHandle
);