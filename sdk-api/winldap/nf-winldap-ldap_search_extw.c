WINLDAPAPI ULONG LDAPAPI ldap_search_extW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   base,
  [in]  ULONG         scope,
  [in]  const PWSTR   filter,
  [in]  PZPWSTR       attrs,
  [in]  ULONG         attrsonly,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [in]  ULONG         TimeLimit,
  [in]  ULONG         SizeLimit,
  [out] ULONG         *MessageNumber
);