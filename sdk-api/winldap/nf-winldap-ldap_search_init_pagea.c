WINLDAPAPI PLDAPSearch LDAPAPI ldap_search_init_pageA(
  [in] PLDAP         ExternalHandle,
  [in] const PSTR    DistinguishedName,
  [in] ULONG         ScopeOfSearch,
  [in] const PSTR    SearchFilter,
  [in] PZPSTR        AttributeList,
  [in] ULONG         AttributesOnly,
  [in] PLDAPControlA *ServerControls,
  [in] PLDAPControlA *ClientControls,
  [in] ULONG         PageTimeLimit,
  [in] ULONG         TotalSizeLimit,
  [in] PLDAPSortKeyA *SortKeys
);