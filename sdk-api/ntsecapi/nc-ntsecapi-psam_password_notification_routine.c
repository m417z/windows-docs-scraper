PSAM_PASSWORD_NOTIFICATION_ROUTINE PsamPasswordNotificationRoutine;

NTSTATUS PsamPasswordNotificationRoutine(
  [in] PUNICODE_STRING UserName,
  [in] ULONG RelativeId,
  [in] PUNICODE_STRING NewPassword
)
{...}