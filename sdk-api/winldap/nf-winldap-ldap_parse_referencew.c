WINLDAPAPI ULONG LDAPAPI ldap_parse_referenceW(
  [in]  LDAP        *Connection,
  [in]  LDAPMessage *ResultMessage,
  [out] PWCHAR      **Referrals
);