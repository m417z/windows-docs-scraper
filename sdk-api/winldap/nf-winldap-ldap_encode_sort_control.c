WINLDAPAPI ULONG LDAPAPI ldap_encode_sort_control(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPSortKeyA *SortKeys,
  [out] PLDAPControlA Control,
  [in]  BOOLEAN       Criticality
);