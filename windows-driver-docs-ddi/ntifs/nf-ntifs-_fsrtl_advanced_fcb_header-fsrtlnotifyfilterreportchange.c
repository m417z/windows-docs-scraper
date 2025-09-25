VOID FsRtlNotifyFilterReportChange(
  [in]           PNOTIFY_SYNC NotifySync,
  [in]           PLIST_ENTRY  NotifyList,
  [in]           PSTRING      FullTargetName,
  [in]           USHORT       TargetNameOffset,
  [in, optional] PSTRING      StreamName,
  [in, optional] PSTRING      NormalizedParentName,
  [in]           ULONG        FilterMatch,
  [in]           ULONG        Action,
  [in, optional] PVOID        TargetContext,
  [in, optional] PVOID        FilterContext
);