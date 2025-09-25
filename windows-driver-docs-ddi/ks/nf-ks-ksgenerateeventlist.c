KSDDKAPI VOID KsGenerateEventList(
  [in, optional] GUID              *Set,
  [in]           ULONG             EventId,
  [in]           PLIST_ENTRY       EventsList,
  [in]           KSEVENTS_LOCKTYPE EventsFlags,
  [in]           PVOID             EventsLock
);