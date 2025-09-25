VOID FsRtlNotifyFullChangeDirectory(
  [in]           PNOTIFY_SYNC               NotifySync,
  [in]           PLIST_ENTRY                NotifyList,
  [in]           PVOID                      FsContext,
  [in]           PSTRING                    FullDirectoryName,
  [in]           BOOLEAN                    WatchTree,
  [in]           BOOLEAN                    IgnoreBuffer,
  [in]           ULONG                      CompletionFilter,
  [in, optional] PIRP                       NotifyIrp,
  [in, optional] PCHECK_FOR_TRAVERSE_ACCESS TraverseCallback,
  [in, optional] PSECURITY_SUBJECT_CONTEXT  SubjectContext
);