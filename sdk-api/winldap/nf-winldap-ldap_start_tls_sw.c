WINLDAPAPI ULONG LDAPAPI ldap_start_tls_sW(
  [in]  PLDAP         ExternalHandle,
  [out] PULONG        ServerReturnValue,
  [out] LDAPMessage   **result,
  [in]  PLDAPControlW *ServerControls,
  [in]  PLDAPControlW *ClientControls
);