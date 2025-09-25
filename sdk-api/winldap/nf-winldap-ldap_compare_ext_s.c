WINLDAPAPI ULONG LDAPAPI ldap_compare_ext_s(
  [in] LDAP          *ld,
  [in] const PSTR    dn,
  [in] const PSTR    Attr,
  [in] const PSTR    Value,
  [in] berval        *Data,
  [in] PLDAPControlA *ServerControls,
  [in] PLDAPControlA *ClientControls
);