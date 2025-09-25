WINLDAPAPI ULONG LDAPAPI ldap_create_page_control(
  [in]  PLDAP         ExternalHandle,
  [in]  ULONG         PageSize,
  [in]  berval        *Cookie,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlA *Control
);