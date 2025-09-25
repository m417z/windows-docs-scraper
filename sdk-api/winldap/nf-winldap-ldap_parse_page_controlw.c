WINLDAPAPI ULONG LDAPAPI ldap_parse_page_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlW *ServerControls,
  [out] ULONG         *TotalCount,
  [out] berval        **Cookie
);