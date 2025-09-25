VOID SeOpenObjectForDeleteAuditAlarm(
  [in]           PUNICODE_STRING      ObjectTypeName,
  [in, optional] PVOID                Object,
  [in, optional] PUNICODE_STRING      AbsoluteObjectName,
  [in]           PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in]           PACCESS_STATE        AccessState,
  [in]           BOOLEAN              ObjectCreated,
  [in]           BOOLEAN              AccessGranted,
  [in]           KPROCESSOR_MODE      AccessMode,
  [out]          PBOOLEAN             GenerateOnClose
);