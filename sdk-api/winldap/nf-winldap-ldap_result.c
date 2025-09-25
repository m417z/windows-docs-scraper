WINLDAPAPI ULONG LDAPAPI ldap_result(
  [in]  LDAP          *ld,
  [in]  ULONG         msgid,
  [in]  ULONG         all,
  [in]  PLDAP_TIMEVAL timeout,
  [out] PLDAPMessage  *res
);