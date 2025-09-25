WINLDAPAPI ULONG LDAPAPI ldap_bind(
  [in] LDAP        *ld,
  [in] const PSTR  dn,
  [in] const PCHAR cred,
  [in] ULONG       method
);