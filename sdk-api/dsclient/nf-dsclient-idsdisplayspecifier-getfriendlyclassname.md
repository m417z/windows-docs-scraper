# IDsDisplaySpecifier::GetFriendlyClassName

## Description

The **IDsDisplaySpecifier::GetFriendlyClassName** method retrieves the localized name for an object class.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to obtain the name of. Examples of the object class name are "user" and "container".

### `pszBuffer` [in, out]

Pointer to a wide character buffer that receives the name string. This buffer must be at least *cchBuffer* wide characters in length.

### `cchBuffer` [in]

Contains the size of the *pszBuffer* buffer, in wide characters, including the terminating **NULL** character. If the name exceeds this number of characters, the name is truncated.

## Return value

Returns a standard **HRESULT** value, including the following.

## Remarks

If no friendly name is set in the display specifiers for the object class, this method returns the name passed in *pszObjectClass*.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)