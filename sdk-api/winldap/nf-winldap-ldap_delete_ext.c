WINLDAPAPI ULONG LDAPAPI ldap_delete_ext(
  [in]  LDAP          *ld,
  [in]  const PSTR    dn,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);