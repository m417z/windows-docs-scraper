WINLDAPAPI ULONG LDAPAPI ldap_search_sA(
  [in]  LDAP        *ld,
  [in]  const PSTR  base,
  [in]  ULONG       scope,
  [in]  const PSTR  filter,
  [in]  PZPSTR      attrs,
  [in]  ULONG       attrsonly,
  [out] LDAPMessage **res
);