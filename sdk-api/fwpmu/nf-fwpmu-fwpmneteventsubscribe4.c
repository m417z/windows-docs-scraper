DWORD FwpmNetEventSubscribe4(
  HANDLE                             engineHandle,
  const FWPM_NET_EVENT_SUBSCRIPTION0 *subscription,
  FWPM_NET_EVENT_CALLBACK4           callback,
  void                               *context,
  HANDLE                             *eventsHandle
);