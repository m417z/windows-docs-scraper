# ldap_unbind_s function

## Description

The **ldap_unbind_s** function synchronously frees resources associated with an LDAP session.

## Parameters

### `ld` [in]

The session handle.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_unbind_s** to unbind from the directory, close the connection, and dispose of the session handle. Call this function when the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) connection structure is no longer required, even if you have not called
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) when opening the connection. Ensure that you do not inadvertently call this function more than once on a session handle because doing so can free resources that you did not intend to release.

Both
[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) and **ldap_unbind_s** work synchronously. There is no server response to an unbind operation.

Multithreading: Calls to **ldap_unbind_s** are safe except that you cannot use the session handle to the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) structure after it has been freed.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)