WINLDAPAPI ULONG LDAPAPI ldap_search_stW(
  [in]  LDAP         *ld,
  [in]  const PWSTR  base,
  [in]  ULONG        scope,
  [in]  const PWSTR  filter,
  [in]  PZPWSTR      attrs,
  [in]  ULONG        attrsonly,
  [in]  l_timeval    *timeout,
  [out] PLDAPMessage *res
);