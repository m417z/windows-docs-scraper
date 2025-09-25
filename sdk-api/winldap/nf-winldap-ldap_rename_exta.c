WINLDAPAPI ULONG LDAPAPI ldap_rename_extA(
  [in]  LDAP          *ld,
  [in]  const PSTR    dn,
  [in]  const PSTR    NewRDN,
  [in]  const PSTR    NewParent,
  [in]  INT           DeleteOldRdn,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);