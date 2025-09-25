WINLDAPAPI ULONG LDAPAPI ldap_extended_operation(
  [in]  LDAP          *ld,
  [in]  const PSTR    Oid,
  [in]  berval        *Data,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] ULONG         *MessageNumber
);