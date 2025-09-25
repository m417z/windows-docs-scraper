WINLDAPAPI ULONG LDAPAPI ldap_add_ext_s(
  [in] LDAP          *ld,
  [in] const PSTR    dn,
  [in] LDAPModA * [] attrs,
  [in] PLDAPControlA *ServerControls,
  [in] PLDAPControlA *ClientControls
);