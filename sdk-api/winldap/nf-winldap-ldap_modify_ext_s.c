WINLDAPAPI ULONG LDAPAPI ldap_modify_ext_s(
  [in] LDAP          *ld,
  [in] const PSTR    dn,
  [in] LDAPModA * [] mods,
  [in] PLDAPControlA *ServerControls,
  [in] PLDAPControlA *ClientControls
);