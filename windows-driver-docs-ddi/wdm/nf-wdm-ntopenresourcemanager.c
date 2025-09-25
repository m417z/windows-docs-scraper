__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenResourceManager(
  [out]          PHANDLE            ResourceManagerHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             TmHandle,
  [in]           LPGUID             ResourceManagerGuid,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);