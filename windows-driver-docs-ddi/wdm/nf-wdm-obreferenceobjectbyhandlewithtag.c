NTSTATUS ObReferenceObjectByHandleWithTag(
  [in]            HANDLE                     Handle,
  [in]            ACCESS_MASK                DesiredAccess,
  [in, optional]  POBJECT_TYPE               ObjectType,
  [in]            KPROCESSOR_MODE            AccessMode,
  [in]            ULONG                      Tag,
  [out]           PVOID                      *Object,
  [out, optional] POBJECT_HANDLE_INFORMATION HandleInformation
);