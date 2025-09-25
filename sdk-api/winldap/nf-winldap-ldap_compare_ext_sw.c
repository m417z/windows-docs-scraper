WINLDAPAPI ULONG LDAPAPI ldap_compare_ext_sW(
  [in] LDAP          *ld,
  [in] const PWSTR   dn,
  [in] const PWSTR   Attr,
  [in] const PWSTR   Value,
  [in] berval        *Data,
  [in] PLDAPControlW *ServerControls,
  [in] PLDAPControlW *ClientControls
);