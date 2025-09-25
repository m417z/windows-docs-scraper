LSA_UPDATE_PRIMARY_CREDENTIALS LsaUpdatePrimaryCredentials;

NTSTATUS LsaUpdatePrimaryCredentials(
  [in]           PSECPKG_PRIMARY_CRED PrimaryCredentials,
  [in, optional] PSECPKG_SUPPLEMENTAL_CRED_ARRAY Credentials
)
{...}