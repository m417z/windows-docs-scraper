WINLDAPAPI ULONG LDAPAPI ldap_delete_ext_s(
  [in] LDAP          *ld,
  [in] const PSTR    dn,
  [in] PLDAPControlA *ServerControls,
  [in] PLDAPControlA *ClientControls
);