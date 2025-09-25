DWORD FwpmNetEventSubscribe0(
  [in]           HANDLE                             engineHandle,
  [in]           const FWPM_NET_EVENT_SUBSCRIPTION0 *subscription,
  [in]           FWPM_NET_EVENT_CALLBACK0           callback,
  [in, optional] void                               *context,
  [out]          HANDLE                             *eventsHandle
);