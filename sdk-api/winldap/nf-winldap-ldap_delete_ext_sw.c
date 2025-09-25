WINLDAPAPI ULONG LDAPAPI ldap_delete_ext_sW(
  [in] LDAP          *ld,
  [in] const PWSTR   dn,
  [in] PLDAPControlW *ServerControls,
  [in] PLDAPControlW *ClientControls
);