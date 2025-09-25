WINLDAPAPI ULONG LDAPAPI ldap_parse_extended_resultA(
  [in]  LDAP        *Connection,
  [in]  LDAPMessage *ResultMessage,
  [out] PSTR        *ResultOID,
  [out] berval      **ResultData,
  [in]  BOOLEAN     Freeit
);