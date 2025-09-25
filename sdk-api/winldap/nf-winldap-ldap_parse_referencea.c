WINLDAPAPI ULONG LDAPAPI ldap_parse_referenceA(
  [in]  LDAP        *Connection,
  [in]  LDAPMessage *ResultMessage,
  [out] PCHAR       **Referrals
);