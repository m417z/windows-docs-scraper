WINLDAPAPI ULONG LDAPAPI ldap_search_ext_sA(
  [in]  LDAP          *ld,
  [in]  const PSTR    base,
  [in]  ULONG         scope,
  [in]  const PSTR    filter,
  [in]  PZPSTR        attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [in]  l_timeval     *timeout,
  [in]  ULONG         SizeLimit,
  [out] PLDAPMessage  *res
);