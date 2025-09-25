__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcess(
  [out]          PHANDLE            ProcessHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] PCLIENT_ID         ClientId
);