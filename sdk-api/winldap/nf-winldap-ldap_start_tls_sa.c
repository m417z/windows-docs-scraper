WINLDAPAPI ULONG LDAPAPI ldap_start_tls_sA(
  [in]  PLDAP         ExternalHandle,
  [out] PULONG        ServerReturnValue,
  [out] LDAPMessage   **result,
  [in]  PLDAPControlA *ServerControls,
  [in]  PLDAPControlA *ClientControls
);