WINLDAPAPI ULONG LDAPAPI ldap_modrdn2W(
  [in] LDAP        *ExternalHandle,
  [in] const PWSTR DistinguishedName,
  [in] const PWSTR NewDistinguishedName,
  [in] INT         DeleteOldRdn
);