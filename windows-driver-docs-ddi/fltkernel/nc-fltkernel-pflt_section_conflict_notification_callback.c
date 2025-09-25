PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK PfltSectionConflictNotificationCallback;

NTSTATUS PfltSectionConflictNotificationCallback(
  [in] PFLT_INSTANCE Instance,
  [in] PFLT_CONTEXT SectionContext,
  [in] PFLT_CALLBACK_DATA Data
)
{...}