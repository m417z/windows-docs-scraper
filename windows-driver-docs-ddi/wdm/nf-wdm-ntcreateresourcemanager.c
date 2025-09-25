__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateResourceManager(
  [out]          PHANDLE            ResourceManagerHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             TmHandle,
  [in]           LPGUID             RmGuid,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] ULONG              CreateOptions,
  [in, optional] PUNICODE_STRING    Description
);