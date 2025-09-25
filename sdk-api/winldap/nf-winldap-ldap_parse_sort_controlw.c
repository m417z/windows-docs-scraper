WINLDAPAPI ULONG LDAPAPI ldap_parse_sort_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlW *Control,
  [out] ULONG         *Result,
  [out] PWCHAR        *Attribute
);