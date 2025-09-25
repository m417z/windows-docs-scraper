WINLDAPAPI ULONG LDAPAPI ldap_search_s(
  [in]  LDAP         *ld,
  [in]  PSTR         base,
  [in]  ULONG        scope,
  [in]  PSTR         filter,
  [in]  PZPSTR       attrs,
  [in]  ULONG        attrsonly,
  [out] PLDAPMessage *res
);