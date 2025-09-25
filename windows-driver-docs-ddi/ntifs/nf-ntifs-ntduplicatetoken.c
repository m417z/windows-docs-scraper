__kernel_entry NTSYSCALLAPI NTSTATUS NtDuplicateToken(
  [in]  HANDLE             ExistingTokenHandle,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in]  BOOLEAN            EffectiveOnly,
  [in]  TOKEN_TYPE         TokenType,
  [out] PHANDLE            NewTokenHandle
);