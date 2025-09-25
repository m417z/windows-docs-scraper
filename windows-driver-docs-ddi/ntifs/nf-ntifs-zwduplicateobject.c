NTSYSAPI NTSTATUS ZwDuplicateObject(
  [in]            HANDLE      SourceProcessHandle,
  [in]            HANDLE      SourceHandle,
  [in, optional]  HANDLE      TargetProcessHandle,
  [out, optional] PHANDLE     TargetHandle,
  [in]            ACCESS_MASK DesiredAccess,
  [in]            ULONG       HandleAttributes,
  [in]            ULONG       Options
);