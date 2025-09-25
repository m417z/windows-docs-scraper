VOID FLTAPI FltNotifyFilterChangeDirectory(
  [in, out]      PNOTIFY_SYNC               NotifySync,
  [in, out]      PLIST_ENTRY                NotifyList,
  [in]           PVOID                      FsContext,
  [in]           PSTRING                    FullDirectoryName,
  [in]           BOOLEAN                    WatchTree,
  [in]           BOOLEAN                    IgnoreBuffer,
  [in]           ULONG                      CompletionFilter,
  [in]           PFLT_CALLBACK_DATA         NotifyCallbackData,
  [in, optional] PCHECK_FOR_TRAVERSE_ACCESS TraverseCallback,
  [in, optional] PSECURITY_SUBJECT_CONTEXT  SubjectContext,
  [in, optional] PFILTER_REPORT_CHANGE      FilterCallback
);