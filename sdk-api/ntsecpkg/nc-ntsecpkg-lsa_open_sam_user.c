LSA_OPEN_SAM_USER LsaOpenSamUser;

NTSTATUS LsaOpenSamUser(
  [in]  PSECURITY_STRING Name,
  [in]  SECPKG_NAME_TYPE NameType,
  [in]  PSECURITY_STRING Prefix,
  [in]  BOOLEAN AllowGuest,
  [in]  ULONG Reserved,
  [out] PVOID *UserHandle
)
{...}