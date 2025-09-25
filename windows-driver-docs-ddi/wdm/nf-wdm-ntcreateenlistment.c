__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateEnlistment(
  [out]          PHANDLE            EnlistmentHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             ResourceManagerHandle,
  [in]           HANDLE             TransactionHandle,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] ULONG              CreateOptions,
  [in]           NOTIFICATION_MASK  NotificationMask,
  [in, optional] PVOID              EnlistmentKey
);