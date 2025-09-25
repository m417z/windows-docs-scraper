NTSTATUS Msv1_0SubAuthenticationRoutine(
  [in]  NETLOGON_LOGON_INFO_CLASS LogonLevel,
  [in]  PVOID                     LogonInformation,
  [in]  ULONG                     Flags,
  [in]  PUSER_ALL_INFORMATION     UserAll,
  [out] PULONG                    WhichFields,
  [out] PULONG                    UserFlags,
  [out] PBOOLEAN                  Authoritative,
  [out] PLARGE_INTEGER            LogoffTime,
  [out] PLARGE_INTEGER            KickoffTime
);