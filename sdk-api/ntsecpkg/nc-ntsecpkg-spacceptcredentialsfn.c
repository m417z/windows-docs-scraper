SpAcceptCredentialsFn Spacceptcredentialsfn;

NTSTATUS Spacceptcredentialsfn(
  [in] SECURITY_LOGON_TYPE LogonType,
  [in] PUNICODE_STRING AccountName,
  [in] PSECPKG_PRIMARY_CRED PrimaryCredentials,
  [in] PSECPKG_SUPPLEMENTAL_CRED SupplementalCredentials
)
{...}