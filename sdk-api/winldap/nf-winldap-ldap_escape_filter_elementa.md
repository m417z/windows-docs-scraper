# ldap_escape_filter_elementA function

## Description

The **ldap_escape_filter_element** function converts a filter element to a null-terminated character string that can be passed safely in a search filter.

## Parameters

### `sourceFilterElement` [in]

A pointer to a null-terminated string that contains the filter element to convert.

### `sourceLength` [in]

The length, in bytes, of the source filter element.

### `destFilterElement` [out]

A pointer to a null-terminated character string.

### `destLength` [in]

The length, in bytes, of the *destFilterElement* buffer.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_escape_filter_element** function allows you to use raw binary data in search filters. For example, you can use this function to specify a certificate or a JPEG image as the attribute to match.

Call **ldap_escape_filter_element** with the *sourceFilterElement* parameter pointing to raw data and *sourceLength* set appropriately to the length of data. If the *destFilterElement* parameter is **NULL**, then the return value is the length required for the output buffer. If *destFilterElement* is not **NULL**, then the function copies the source into the destination buffer and ensures that it is of a safe format. Then insert the destination buffer into your search filter after the "attributetype=" filter element.

**Note** Do not call **ldap_escape_filter_element** for attribute values that are strings, as the run time does not perform any conversion from UTF-8 format. Use this function only for attribute elements that are raw binary data.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)