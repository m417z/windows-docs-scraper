WINLDAPAPI ULONG LDAPAPI ldap_modrdn2_sW(
  [in] LDAP        *ExternalHandle,
  [in] const PWSTR DistinguishedName,
  [in] const PWSTR NewDistinguishedName,
  [in] INT         DeleteOldRdn
);