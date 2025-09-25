KSDDKAPI VOID KsFreeEventList(
  [in]      PFILE_OBJECT      FileObject,
  [in, out] PLIST_ENTRY       EventsList,
  [in]      KSEVENTS_LOCKTYPE EventsFlags,
  [in]      PVOID             EventsLock
);