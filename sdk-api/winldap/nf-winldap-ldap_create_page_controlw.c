WINLDAPAPI ULONG LDAPAPI ldap_create_page_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  ULONG         PageSize,
  [in]  berval        *Cookie,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlW *Control
);