WINLDAPAPI ULONG LDAPAPI ldap_search_extA(
  [in]  LDAP          *ld,
  [in]  const PSTR    base,
  [in]  ULONG         scope,
  [in]  const PSTR    filter,
  [in]  PZPSTR        attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [in]  ULONG         TimeLimit,
  [in]  ULONG         SizeLimit,
  [out] ULONG         *MessageNumber
);