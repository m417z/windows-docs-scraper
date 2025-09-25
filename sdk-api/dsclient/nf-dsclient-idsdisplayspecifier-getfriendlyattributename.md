# IDsDisplaySpecifier::GetFriendlyAttributeName

## Description

The **IDsDisplaySpecifier::GetFriendlyAttributeName** method retrieves from the localized name of an attribute of a given object class.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to obtain the localized attribute name for. Examples of the object class name are "user" and "container".

### `pszAttributeName` [in]

Pointer to a null-terminated Unicode string that contains the name of the attribute to obtain the localized name for.

### `pszBuffer` [in]

Pointer to a wide character buffer that receives the name string. This buffer must be at least *cchBuffer* wide characters in length.

### `cchBuffer` [in]

Contains the size of the *pszBuffer* buffer, in wide characters, including the terminating **NULL** character. If the name exceeds this number of characters, the name is truncated.

## Return value

Returns a standard **HRESULT** value, including the following.

## Remarks

This method looks up the display specifier of the class to check the **attributeNames** property for an attribute name pair that matches the given attribute name. If no match is found, the input attribute name is returned.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)