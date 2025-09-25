WINLDAPAPI ULONG LDAPAPI ldap_search_ext(
  [in]  LDAP          *ld,
  [in]  PSTR          base,
  [in]  ULONG         scope,
  [in]  PSTR          filter,
  [in]  PZPSTR        attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [in]  ULONG         TimeLimit,
  [in]  ULONG         SizeLimit,
  [out] ULONG         *MessageNumber
);