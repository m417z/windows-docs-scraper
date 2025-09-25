WINLDAPAPI ULONG LDAPAPI ldap_get_next_page_s(
  [in]  PLDAP       ExternalHandle,
  [in]  PLDAPSearch SearchHandle,
  [in]  l_timeval   *timeout,
  [in]  ULONG       PageSize,
  [out] ULONG       *TotalCount,
  [out] LDAPMessage **Results
);