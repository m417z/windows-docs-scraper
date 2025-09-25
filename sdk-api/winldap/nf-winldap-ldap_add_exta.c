WINLDAPAPI ULONG LDAPAPI ldap_add_extA(
  [in]  LDAP          *ld,
  [in]  const PSTR    dn,
  [in]  LDAPModA * [] attrs,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);