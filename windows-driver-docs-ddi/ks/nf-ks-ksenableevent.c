KSDDKAPI NTSTATUS KsEnableEvent(
  [in]           PIRP              Irp,
  [in]           ULONG             EventSetsCount,
  [in]           const KSEVENT_SET *EventSet,
  [in, out]      PLIST_ENTRY       EventsList,
  [in, optional] KSEVENTS_LOCKTYPE EventsFlags,
  [in, optional] PVOID             EventsLock
);