WINLDAPAPI INT LDAPAPI ldap_sasl_bindW(
  [in]  LDAP          *ExternalHandle,
  [in]  const PWSTR   DistName,
  [in]  const PWSTR   AuthMechanism,
  [in]  const BERVAL  *cred,
  [in]  PLDAPControlW *ServerCtrls,
  [in]  PLDAPControlW *ClientCtrls,
  [out] int           *MessageNumber
);