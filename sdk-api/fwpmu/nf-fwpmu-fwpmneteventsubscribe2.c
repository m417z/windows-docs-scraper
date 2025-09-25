DWORD FwpmNetEventSubscribe2(
  [in]           HANDLE                             engineHandle,
  [in]           const FWPM_NET_EVENT_SUBSCRIPTION0 *subscription,
  [in]           FWPM_NET_EVENT_CALLBACK2           callback,
  [in, optional] void                               *context,
  [out]          HANDLE                             *eventsHandle
);