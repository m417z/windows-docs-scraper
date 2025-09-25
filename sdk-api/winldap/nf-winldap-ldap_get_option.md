# ldap_get_option function

## Description

The **ldap_get_option** function retrieves the current values of session-wide parameters.

## Parameters

### `ld` [in]

The session handle.

### `option` [in]

The name of the option accessed. For more information and a list of allowable options and their values, see the following Remarks section.

### `outvalue` [out]

The address of the option value. The actual type of this parameter depends on the setting of the option parameter.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

For more information and a description of optional settings that apply to an LDAP session, see
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options). The *outvalue* value returns a pointer to an allocated block of memory of the type listed in the **Session Options** table; this memory should be freed using [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) when the data is no longer required, unless it is explicitly mentioned in the **Session Options** table not to free the returned memory.

**Note** [LDAP_OPT_ERROR_STRING](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) returns a pointer to an internal static string table, and [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) should not be called when using this session option.

Multithreading: The **ldap_get_option** function is thread-safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Getting and Setting Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/getting-and-setting-session-options)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)