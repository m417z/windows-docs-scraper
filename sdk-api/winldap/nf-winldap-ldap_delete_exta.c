WINLDAPAPI ULONG LDAPAPI ldap_delete_extA(
  [in]  LDAP          *ld,
  [in]  const PSTR    dn,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);