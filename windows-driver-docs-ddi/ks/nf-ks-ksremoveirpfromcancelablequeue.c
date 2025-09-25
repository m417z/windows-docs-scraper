KSDDKAPI PIRP KsRemoveIrpFromCancelableQueue(
  [in, out] PLIST_ENTRY             QueueHead,
  [in]      PKSPIN_LOCK             SpinLock,
  [in]      KSLIST_ENTRY_LOCATION   ListLocation,
  [in]      KSIRP_REMOVAL_OPERATION RemovalOperation
);