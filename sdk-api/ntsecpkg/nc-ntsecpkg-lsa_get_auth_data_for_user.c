LSA_GET_AUTH_DATA_FOR_USER LsaGetAuthDataForUser;

NTSTATUS LsaGetAuthDataForUser(
  [in]  PSECURITY_STRING Name,
  [in]  SECPKG_NAME_TYPE NameType,
  [in]  PSECURITY_STRING Prefix,
  [out] PUCHAR *UserAuthData,
  [out] PULONG UserAuthDataSize,
  [out] PUNICODE_STRING UserFlatName
)
{...}