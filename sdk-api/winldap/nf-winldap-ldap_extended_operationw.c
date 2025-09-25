WINLDAPAPI ULONG LDAPAPI ldap_extended_operationW(
  [in]  LDAP          *ld,
  [in]  const PWSTR   Oid,
  [in]  berval        *Data,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] ULONG         *MessageNumber
);