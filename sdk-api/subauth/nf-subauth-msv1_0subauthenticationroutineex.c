NTSTATUS Msv1_0SubAuthenticationRoutineEx(
  [in]      NETLOGON_LOGON_INFO_CLASS LogonLevel,
  [in]      PVOID                     LogonInformation,
  [in]      ULONG                     Flags,
  [in]      PUSER_ALL_INFORMATION     UserAll,
  [in]      SAM_HANDLE                UserHandle,
  [in, out] PMSV1_0_VALIDATION_INFO   ValidationInfo,
  [out]     PULONG                    ActionsPerformed
);