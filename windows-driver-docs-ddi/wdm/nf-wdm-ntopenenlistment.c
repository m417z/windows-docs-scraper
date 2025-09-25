__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenEnlistment(
  [out]          PHANDLE            EnlistmentHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             ResourceManagerHandle,
  [in]           LPGUID             EnlistmentGuid,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);