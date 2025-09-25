NTSTATUS CmCallbackGetKeyObjectID(
  [in]            PLARGE_INTEGER   Cookie,
  [in]            PVOID            Object,
  [out, optional] PULONG_PTR       ObjectID,
  [out, optional] PCUNICODE_STRING *ObjectName
);