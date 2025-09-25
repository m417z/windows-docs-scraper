WINLDAPAPI ULONG LDAPAPI ldap_encode_sort_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPSortKeyW *SortKeys,
  [out] PLDAPControlW Control,
  [in]  BOOLEAN       Criticality
);