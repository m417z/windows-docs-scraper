WINLDAPAPI ULONG LDAPAPI ldap_get_next_page(
  [in]  PLDAP       ExternalHandle,
  [in]  PLDAPSearch SearchHandle,
  [in]  ULONG       PageSize,
  [out] ULONG       *MessageNumber
);