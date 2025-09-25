# ldap_rename_extW function

## Description

The **ldap_rename_ext** function starts an asynchronous operation that changes the distinguished name of an entry in the directory. This function is available effective with LDAP 3.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a wide, null-terminated string that contains the distinguished name of the entry to be renamed.

### `NewRDN` [in]

A pointer to a wide, null-terminated string that contains the new relative distinguished name for the entry.

### `NewParent` [in]

A pointer to a wide, null-terminated string that contains the distinguished name of the new parent for this entry. This parameter enables you to move the entry to a new parent container.

### `DeleteOldRdn` [in]

**TRUE** if the old relative distinguished name should be deleted; **FALSE** if the old relative distinguished name should be retained.

### `ServerControls` [in]

List of LDAP server controls.

### `ClientControls` [in]

List of client controls.

### `MessageNumber` [out]

Pointer to a variable that receives the message identifier for this asynchronous operation. Use this identifier with the
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) function to retrieve the results of the operation.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

This function provides extended renaming operations. For example, you can pass controls that separate the parent from the relative distinguished name, for clarity.

Multithreading: Calls to **ldap_rename_ext** are thread-safe.

> [!NOTE]
> The winldap.h header defines ldap_rename_ext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)