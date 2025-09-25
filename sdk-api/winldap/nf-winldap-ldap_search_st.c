WINLDAPAPI ULONG LDAPAPI ldap_search_st(
  [in]  LDAP         *ld,
  [in]  PSTR         base,
  [in]  ULONG        scope,
  [in]  PSTR         filter,
  [in]  PZPSTR       attrs,
  [in]  ULONG        attrsonly,
  [in]  l_timeval    *timeout,
  [out] PLDAPMessage *res
);