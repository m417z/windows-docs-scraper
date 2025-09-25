WINLDAPAPI ULONG LDAPAPI ldap_delete_extW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   dn,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] ULONG         *MessageNumber
);