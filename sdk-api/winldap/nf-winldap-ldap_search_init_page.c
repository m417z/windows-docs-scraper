WINLDAPAPI PLDAPSearch LDAPAPI ldap_search_init_page(
  [in] PLDAP        ExternalHandle,
  [in] const PSTR   DistinguishedName,
  [in] ULONG        ScopeOfSearch,
  [in] const PSTR   SearchFilter,
  [in] PZPSTR       AttributeList,
  [in] ULONG        AttributesOnly,
  [in] PLDAPControl *ServerControls,
  [in] PLDAPControl *ClientControls,
  [in] ULONG        PageTimeLimit,
  [in] ULONG        TotalSizeLimit,
  [in] PLDAPSortKey *SortKeys
);