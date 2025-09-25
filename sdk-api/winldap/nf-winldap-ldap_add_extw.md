# ldap_add_extW function

## Description

The **ldap_add_ext** function initiates an asynchronous add operation to a tree. The parent of the entry added must exist, or the parent must be empty (equal to the distinguished name of the root) for an add operation to succeed.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to add.

### `attrs` [in]

An array of pointers to
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Each structure specifies a single attribute. For more information, see the Remarks section.

### `ServerControls` [in]

List of LDAP server controls.

### `ClientControls` [in]

List of client controls.

### `MessageNumber` [out]

The message ID for the request.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see [Error Handling](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions).

## Remarks

The parameters and effects of **ldap_add_ext** includes those of
[ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add). The extended routine includes additional parameters to support client and server controls and thread safety.

Before calling **ldap_add_ext**, create an entry by specifying its attributes in
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Set the **mod_op** field of each structure to **LDAP_MOD_ADD**, and set the **mod_type** and **mod_vals** fields as appropriate for your entry.

If the operation succeeds, **ldap_add_ext** passes the message ID to the caller as a parameter. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation.

To have the results returned directly, use the synchronous function
[ldap_add_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext_s).

Multithreaded: Calls to **ldap_add_ext** are thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations.

*ServerControls* and *ClientControls* are optional and should be set to **NULL** if not used.

> [!NOTE]
> The winldap.h header defines ldap_add_ext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Error Handling](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

Functions

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add)

[ldap_add_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext_s)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)