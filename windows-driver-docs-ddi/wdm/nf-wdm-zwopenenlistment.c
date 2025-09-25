NTSYSCALLAPI NTSTATUS ZwOpenEnlistment(
  [out]          PHANDLE            EnlistmentHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in]           HANDLE             RmHandle,
  [in]           LPGUID             EnlistmentGuid,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);