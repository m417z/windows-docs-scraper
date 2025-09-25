WINLDAPAPI ULONG LDAPAPI ldap_parse_sort_control(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlA *Control,
  [out] ULONG         *Result,
  [out] PCHAR         *Attribute
);