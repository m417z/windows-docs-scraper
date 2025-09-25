KSDDKAPI NTSTATUS KsGetImageNameAndResourceId(
  [in]  HANDLE          RegKey,
  [out] PUNICODE_STRING ImageName,
  [out] PULONG_PTR      ResourceId,
  [out] PULONG          ValueType
);