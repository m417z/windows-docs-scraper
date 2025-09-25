DWORD FwpmvSwitchEventSubscribe0(
  [in]           HANDLE                                 engineHandle,
  [in]           const FWPM_VSWITCH_EVENT_SUBSCRIPTION0 *subscription,
  [in]           FWPM_VSWITCH_EVENT_CALLBACK0           callback,
  [in, optional] void                                   *context,
  [out]          HANDLE                                 *subscriptionHandle
);