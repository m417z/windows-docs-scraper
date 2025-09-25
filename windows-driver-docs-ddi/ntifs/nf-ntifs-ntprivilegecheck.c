__kernel_entry NTSYSCALLAPI NTSTATUS NtPrivilegeCheck(
  [in]      HANDLE         ClientToken,
  [in, out] PPRIVILEGE_SET RequiredPrivileges,
  [out]     PBOOLEAN       Result
);