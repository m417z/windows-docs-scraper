NTSTATUS LsaLogonUser(
  [in]           HANDLE              LsaHandle,
  [in]           PLSA_STRING         OriginName,
  [in]           SECURITY_LOGON_TYPE LogonType,
  [in]           ULONG               AuthenticationPackage,
  [in]           PVOID               AuthenticationInformation,
  [in]           ULONG               AuthenticationInformationLength,
  [in, optional] PTOKEN_GROUPS       LocalGroups,
  [in]           PTOKEN_SOURCE       SourceContext,
  [out]          PVOID               *ProfileBuffer,
  [out]          PULONG              ProfileBufferLength,
  [out]          PLUID               LogonId,
  [out]          PHANDLE             Token,
  [out]          PQUOTA_LIMITS       Quotas,
  [out]          PNTSTATUS           SubStatus
);