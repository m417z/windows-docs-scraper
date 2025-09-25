NTSTATUS ObQueryNameString(
  [in]            PVOID                    Object,
  [out, optional] POBJECT_NAME_INFORMATION ObjectNameInfo,
  [in]            ULONG                    Length,
  [out]           PULONG                   ReturnLength
);