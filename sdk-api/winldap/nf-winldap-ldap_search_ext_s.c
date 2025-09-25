WINLDAPAPI ULONG LDAPAPI ldap_search_ext_s(
  [in]  LDAP          *ld,
  [in]  PSTR          base,
  [in]  ULONG         scope,
  [in]  PSTR          filter,
  [in]  PZPSTR        attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [in]  l_timeval     *timeout,
  [in]  ULONG         SizeLimit,
  [out] PLDAPMessage  *res
);