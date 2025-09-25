WINLDAPAPI ULONG LDAPAPI ldap_get_paged_count(
  [in]  PLDAP        ExternalHandle,
  [in]  PLDAPSearch  SearchBlock,
  [out] ULONG        *TotalCount,
  [out] PLDAPMessage Results
);