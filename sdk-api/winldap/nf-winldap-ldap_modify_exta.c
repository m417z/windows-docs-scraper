WINLDAPAPI ULONG LDAPAPI ldap_modify_extA(
  [in]  LDAP          *ld,
  [in]  const PSTR    dn,
  [in]  LDAPModA * [] mods,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);