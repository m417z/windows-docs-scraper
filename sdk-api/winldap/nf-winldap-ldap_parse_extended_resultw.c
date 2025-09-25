WINLDAPAPI ULONG LDAPAPI ldap_parse_extended_resultW(
  [in]  LDAP        *Connection,
  [in]  LDAPMessage *ResultMessage,
  [out] PWSTR       *ResultOID,
  [out] berval      **ResultData,
  [in]  BOOLEAN     Freeit
);