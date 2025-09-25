WINLDAPAPI ULONG LDAPAPI ldap_rename_extW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   dn,
  [in]  const PWSTR   NewRDN,
  [in]  const PWSTR   NewParent,
  [in]  INT           DeleteOldRdn,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] ULONG         *MessageNumber
);