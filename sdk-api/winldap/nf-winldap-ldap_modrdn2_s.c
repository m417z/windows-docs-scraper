WINLDAPAPI ULONG LDAPAPI ldap_modrdn2_s(
  [in] LDAP       *ExternalHandle,
  [in] const PSTR DistinguishedName,
  [in] const PSTR NewDistinguishedName,
  [in] INT        DeleteOldRdn
);