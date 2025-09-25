WINLDAPAPI ULONG LDAPAPI ldap_add_extW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   dn,
  [in]  LDAPModW * [] attrs,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] ULONG         *MessageNumber
);