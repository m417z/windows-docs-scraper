WINLDAPAPI INT LDAPAPI ldap_sasl_bindA(
  [in]  LDAP          *ExternalHandle,
  [in]  const PSTR    DistName,
  [in]  const PSTR    AuthMechanism,
  [in]  const BERVAL  *cred,
  [in]  PLDAPControlA *ServerCtrls,
  [in]  PLDAPControlA *ClientCtrls,
  [out] int           *MessageNumber
);