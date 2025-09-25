NTSYSCALLAPI NTSTATUS ZwCreateResourceManager(
  [out]          PHANDLE            ResourceManagerHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             TmHandle,
  [in, optional] LPGUID             ResourceManagerGuid,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] ULONG              CreateOptions,
  [in, optional] PUNICODE_STRING    Description
);