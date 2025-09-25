# IDsDisplaySpecifier::EnumClassAttributes

## Description

The **IDsDisplaySpecifier::EnumClassAttributes** method enumerates the attributes for a given object class. The enumeration provides both the LDAP and localized names of each attribute.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to enumerate the attributes for. Examples of the object class name are "user" and "container".

### `pcbEnum` [in]

Pointer to an application-supplied [DSEnumAttributesCallback](https://learn.microsoft.com/windows/desktop/api/dsclient/nc-dsclient-lpdsenumattributes) function that is called once for each enumerated attribute.

### `lParam` [in]

Contains an application-defined parameter passed as the *lParam* parameter in the [DSEnumAttributesCallback](https://learn.microsoft.com/windows/desktop/api/dsclient/nc-dsclient-lpdsenumattributes) function.

## Return value

Returns a standard **HRESULT** value including the following.

## See also

[DSEnumAttributesCallback](https://learn.microsoft.com/windows/desktop/api/dsclient/nc-dsclient-lpdsenumattributes)

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)