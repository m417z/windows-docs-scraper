# ldap_compare_extW function

## Description

Use the **ldap_compare_ext** function to determine if an attribute, for a given entry, holds a known value.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to compare.

### `Attr` [in]

A pointer to a null-terminated string that contains the attribute to compare.

### `Value` [in]

A pointer to a null-terminated string that contains the string attribute value to be compared to the attribute value.

### `Data` [in]

The
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) attribute value to be compared to the attribute value.

### `ServerControls` [in]

Optional. A list of LDAP server controls. This parameter should be set to **NULL** if not used.

### `ClientControls` [in]

Optional. A list of client controls. This parameter should be set to **NULL** if not used.

### `MessageNumber` [out]

The message ID for the compare operation.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_compare_ext** function initiates an asynchronous compare operation, comparing the value of an attribute to a known value. The parameters and effects of **ldap_compare_ext** subsume those of
[ldap_compare](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare). The extended routine includes additional parameters to support client and server controls, comparison of binary values, and thread safety.

Use the *Value* parameter for comparing string values or use the *Data* parameter for comparing raw binary data. Set the unused parameter to **NULL**. If neither parameter is **NULL**, the compare operation will use the value in the *Data* parameter.

If successful, **ldap_compare_ext** passes back the message ID for the operation in the *MessageNumber* parameter. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to obtain the result of the compare. To have the function return the compare result directly, use the synchronous extended compare function
[ldap_compare_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext_s).

Multithreading: Calls to **ldap_compare_ext** are thread-safe.

> [!NOTE]
> The winldap.h header defines ldap_compare_ext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_compare](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare)

[ldap_compare_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)