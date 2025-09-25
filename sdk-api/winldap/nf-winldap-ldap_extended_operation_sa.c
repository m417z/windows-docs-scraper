WINLDAPAPI ULONG LDAPAPI ldap_extended_operation_sA(
  [in]  LDAP          *ExternalHandle,
  [in]  PSTR          Oid,
  [in]  berval        *Data,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls,
  [out] PCHAR         *ReturnedOid,
  [out] berval        **ReturnedData
);