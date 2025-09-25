KSDDKAPI NTSTATUS KsEnableEventWithAllocator(
  [in]           PIRP              Irp,
  [in]           ULONG             EventSetsCount,
  [in]           const KSEVENT_SET *EventSet,
  [in, out]      PLIST_ENTRY       EventsList,
  [in, optional] KSEVENTS_LOCKTYPE EventsFlags,
  [in, optional] PVOID             EventsLock,
  [in, optional] PFNKSALLOCATOR    Allocator,
  [in, optional] ULONG             EventItemSize
);