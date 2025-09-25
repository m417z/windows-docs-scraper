WINLDAPAPI ULONG LDAPAPI ldap_modify_extW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   dn,
  [in]  LDAPModW * [] mods,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] ULONG         *MessageNumber
);