KSDDKAPI NTSTATUS KsDisableEvent(
  [in]      PIRP              Irp,
  [in, out] PLIST_ENTRY       EventsList,
  [in]      KSEVENTS_LOCKTYPE EventsFlags,
  [in]      PVOID             EventsLock
);