NTSTATUS FwpsvSwitchEventsSubscribe0(
  const GUID                              *providerGuid,
  void                                    *notifyContext,
  UINT32                                  flags,
  void                                    *reserved,
  const FWPS_VSWITCH_EVENT_DISPATCH_TABLE *eventDispatchTable,
  UINT32                                  *subscriptionId
);