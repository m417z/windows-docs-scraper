NTSTATUS SEC_ENTRY GetSecurityUserInfo(
  [in, optional] PLUID             LogonId,
  [in]           ULONG             Flags,
  [out]          PSecurityUserData *UserInformation
);