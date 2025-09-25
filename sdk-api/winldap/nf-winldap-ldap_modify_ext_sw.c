WINLDAPAPI ULONG LDAPAPI ldap_modify_ext_sW(
  [in] LDAP          *ld,
  [in] const PWSTR   dn,
  [in] LDAPModW * [] mods,
  [in] PLDAPControlW *ServerControls,
  [in] PLDAPControlW *ClientControls
);