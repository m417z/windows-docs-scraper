PLIST_ENTRY KeRemoveQueue(
  [in, out]      PRKQUEUE        Queue,
  [in]           KPROCESSOR_MODE WaitMode,
  [in, optional] PLARGE_INTEGER  Timeout
);