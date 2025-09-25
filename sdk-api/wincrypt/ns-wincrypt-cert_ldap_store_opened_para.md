# CERT_LDAP_STORE_OPENED_PARA structure

## Description

The **CERT_LDAP_STORE_OPENED_PARA** structure is used with the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function when the **CERT_STORE_PROV_LDAP** provider is specified by using the **CERT_LDAP_STORE_OPENED_FLAG** flag to specify both the existing LDAP session to use to perform the query as well as the LDAP query string.

## Members

### `pvLdapSessionHandle`

The handle of the existing LDAP session. This is the handle that is returned by the [ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init) function.

### `pwszLdapUrl`

The address of a null-terminated Unicode string that contains the LDAP query string. For more information about LDAP query strings, see [LDAP Dialect](https://learn.microsoft.com/windows/desktop/ADSI/ldap-dialect).

## See also

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)