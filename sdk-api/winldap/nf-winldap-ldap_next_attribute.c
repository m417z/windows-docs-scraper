WINLDAPAPI PCHAR LDAPAPI ldap_next_attribute(
  [in]      LDAP        *ld,
  [in]      LDAPMessage *entry,
  [in, out] BerElement  *ptr
);