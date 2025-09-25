WINLDAPAPI ULONG LDAPAPI ldap_search_sW(
  [in]  LDAP        *ld,
  [in]  const PWSTR base,
  [in]  ULONG       scope,
  [in]  const PWSTR filter,
  [in]  PZPWSTR     attrs,
  [in]  ULONG       attrsonly,
  [out] LDAPMessage **res
);