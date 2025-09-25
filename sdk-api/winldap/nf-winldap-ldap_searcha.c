WINLDAPAPI ULONG LDAPAPI ldap_searchA(
  [in] LDAP       *ld,
  [in] const PSTR base,
  [in] ULONG      scope,
  [in] const PSTR filter,
  [in] PZPSTR     attrs,
  [in] ULONG      attrsonly
);