WINLDAPAPI ULONG LDAPAPI ldap_search(
  [in] LDAP   *ld,
  [in] PSTR   base,
  [in] ULONG  scope,
  [in] PSTR   filter,
  [in] PZPSTR attrs,
  [in] ULONG  attrsonly
);