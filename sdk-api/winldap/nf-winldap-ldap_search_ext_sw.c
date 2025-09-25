WINLDAPAPI ULONG LDAPAPI ldap_search_ext_sW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   base,
  [in]  ULONG         scope,
  [in]  const PWSTR   filter,
  [in]  PZPWSTR       attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [in]  l_timeval     *timeout,
  [in]  ULONG         SizeLimit,
  [out] PLDAPMessage  *res
);