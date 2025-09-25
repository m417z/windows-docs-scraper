# ldap_free_controlsA function

## Description

This function is not supported.

The **ldap_free_controls** function is an
obsolete function which frees an array of
[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures.

**Note** Obsolete. Use the [ldap_controls_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_controls_free)
function.

## Parameters

### `Controls` [in]

The array of [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures to free.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).