WINLDAPAPI ULONG LDAPAPI ldap_add_ext_sW(
  [in] LDAP          *ld,
  [in] const PWSTR   dn,
  [in] LDAPModW * [] attrs,
  [in] PLDAPControlW *ServerControls,
  [in] PLDAPControlW *ClientControls
);