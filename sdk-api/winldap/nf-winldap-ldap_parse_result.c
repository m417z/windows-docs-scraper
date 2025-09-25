WINLDAPAPI ULONG LDAPAPI ldap_parse_result(
  [in]            LDAP          *Connection,
  [in]            LDAPMessage   *ResultMessage,
  [out, optional] ULONG         *ReturnCode,
  [out, optional] PSTR          *MatchedDNs,
  [out, optional] PSTR          *ErrorMessage,
  [out, optional] PSTR          **Referrals,
  [out, optional] PLDAPControlA **ServerControls,
  [in]            BOOLEAN       Freeit
);