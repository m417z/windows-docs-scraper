WINLDAPAPI ULONG LDAPAPI ldap_parse_page_control(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlA *ServerControls,
  [out] ULONG         *TotalCount,
  [out] berval        **Cookie
);