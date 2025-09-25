DWORD FwpmNetEventSubscribe3(
  HANDLE                             engineHandle,
  const FWPM_NET_EVENT_SUBSCRIPTION0 *subscription,
  FWPM_NET_EVENT_CALLBACK3           callback,
  void                               *context,
  HANDLE                             *eventsHandle
);