WINLDAPAPI ULONG LDAPAPI ldap_create_sort_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPSortKeyW *SortKeys,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlW *Control
);