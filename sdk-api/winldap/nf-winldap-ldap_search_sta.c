WINLDAPAPI ULONG LDAPAPI ldap_search_stA(
  [in]  LDAP         *ld,
  [in]  const PSTR   base,
  [in]  ULONG        scope,
  [in]  const PSTR   filter,
  [in]  PZPSTR       attrs,
  [in]  ULONG        attrsonly,
  [in]  l_timeval    *timeout,
  [out] PLDAPMessage *res
);