KSDDKAPI NTSTATUS KsMoveIrpsOnCancelableQueue(
  [in, out]      PLIST_ENTRY           SourceList,
  [in]           PKSPIN_LOCK           SourceLock,
  [in, out]      PLIST_ENTRY           DestinationList,
  [in, optional] PKSPIN_LOCK           DestinationLock,
  [in]           KSLIST_ENTRY_LOCATION ListLocation,
  [in]           PFNKSIRPLISTCALLBACK  ListCallback,
  [in]           PVOID                 Context
);