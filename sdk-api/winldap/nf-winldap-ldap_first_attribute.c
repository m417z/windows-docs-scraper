WINLDAPAPI PCHAR LDAPAPI ldap_first_attribute(
  [in]  LDAP        *ld,
  [in]  LDAPMessage *entry,
  [out] BerElement  **ptr
);