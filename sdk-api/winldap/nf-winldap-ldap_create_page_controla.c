WINLDAPAPI ULONG LDAPAPI ldap_create_page_controlA(
  [in]  PLDAP         ExternalHandle,
  [in]  ULONG         PageSize,
  [in]  berval        *Cookie,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlA *Control
);