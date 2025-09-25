WINLDAPAPI ULONG LDAPAPI ldap_parse_resultW(
  [in]            LDAP          *Connection,
  [in]            LDAPMessage   *ResultMessage,
  [out, optional] ULONG         *ReturnCode,
  [out, optional] PWSTR         *MatchedDNs,
  [out, optional] PWSTR         *ErrorMessage,
  [out, optional] PZPWSTR       *Referrals,
  [out, optional] PLDAPControlW **ServerControls,
  [in]            BOOLEAN       Freeit
);