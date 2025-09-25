WINLDAPAPI PLDAPSearch LDAPAPI ldap_search_init_pageW(
  [in] PLDAP         ExternalHandle,
  [in] const PWSTR   DistinguishedName,
  [in] ULONG         ScopeOfSearch,
  [in] const PWSTR   SearchFilter,
  [in] PZPWSTR       AttributeList,
  [in] ULONG         AttributesOnly,
  [in] PLDAPControlW *ServerControls,
  [in] PLDAPControlW *ClientControls,
  [in] ULONG         PageTimeLimit,
  [in] ULONG         TotalSizeLimit,
  [in] PLDAPSortKeyW *SortKeys
);