WINLDAPAPI ULONG LDAPAPI ldap_extended_operation_sW(
  [in]  LDAP          *ExternalHandle,
  [in]  PWSTR         Oid,
  [in]  berval        *Data,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls,
  [out] PWCHAR        *ReturnedOid,
  [out] berval        **ReturnedData
);