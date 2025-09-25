WINLDAPAPI ULONG LDAPAPI ldap_parse_reference(
  [in]  LDAP        *Connection,
  [in]  LDAPMessage *ResultMessage,
  [out] PCHAR       **Referrals
);