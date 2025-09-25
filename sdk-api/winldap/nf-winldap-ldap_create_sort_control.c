WINLDAPAPI ULONG LDAPAPI ldap_create_sort_control(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPSortKeyA *SortKeys,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlA *Control
);