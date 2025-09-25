# LPDSENUMATTRIBUTES callback function

## Description

The **DSEnumAttributesCallback** function is an application-defined callback function that is called once for each attribute enumerated by the [IDsDisplaySpecifier::EnumClassAttributes](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-enumclassattributes) method. A pointer to this function is supplied as the *pcbEnum* parameter in **IDsDisplaySpecifier::EnumClassAttributes**. **DSEnumAttributesCallback** is a placeholder for the application-defined function name.

## Parameters

### `lParam`

Contains an application-defined parameter passed as the *lParam* parameter to the [IDsDisplaySpecifier::EnumClassAttributes](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-enumclassattributes) method.

### `pszAttributeName`

Pointer to a null-terminated Unicode string that contains the LDAP name of the attribute.

### `pszDisplayName`

Pointer to a null-terminated Unicode string that contains the localized name of the attribute.

### `dwFlags`

Contains a set of flags that define the behavior or state of the attribute. This can be zero or the following value:

#### DSECAF_NOTLISTED

The attribute is hidden in the user interface.

## Return value

Returns **S_OK** to continue the enumeration or any failure code, such as **E_FAIL**, to terminate the enumeration.

## See also

[IDsDisplaySpecifier::EnumClassAttributes](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-enumclassattributes)