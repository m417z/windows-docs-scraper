WINLDAPAPI ULONG LDAPAPI ldap_encode_sort_controlA(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPSortKeyA *SortKeys,
  [out] PLDAPControlA Control,
  [in]  BOOLEAN       Criticality
);