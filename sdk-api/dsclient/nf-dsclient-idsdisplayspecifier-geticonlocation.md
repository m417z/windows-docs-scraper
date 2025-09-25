# IDsDisplaySpecifier::GetIconLocation

## Description

The **IDsDisplaySpecifier::GetIconLocation** method obtains the icon location for a given object class. The icon location includes the filename and resource identifier.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class for which to obtain the icon location. Examples of the object class name are "user" and "container".

### `dwFlags` [in]

Contains a set of flags that indicate the type of icon to retrieve. This can be a combination of one or more of the following.

#### DSGIF_ISNORMAL

Obtains the normal icon for the object class.

#### DSGIF_ISOPEN

Obtains the open icon, such as an open folder, for the object class. If the object class does not have an open icon, this method attempts to obtain the normal icon for the object class.

#### DSGIF_ISDISABLED

Obtains the disabled icon, such as a disabled user, for the object class. If the object class does not have a disabled icon, this method attempts to obtain the normal icon for the object class.

#### DSGIF_GETDEFAULTICON

If no icon can be found for the object class, this method returns a default icon. If this flag is not specified and no icon can be found for the object class, this method returns **NULL**.

#### DSGIF_DEFAULTISCONTAINER

If no icon can be found for the object class, this method returns the container icon as the default icon. If this flag is not specified and no icon can be found for the object class, this method returns **NULL**.

### `pszBuffer` [in, out]

Pointer to a wide character buffer that receives the path and file name of the file that contains the icon. This buffer must be at least *cchBuffer* wide characters in length.

### `cchBuffer` [in]

Contains the size of the *pszBuffer* buffer, in wide characters, including the terminating **NULL** character. If the file name exceeds this number of characters, the file name is truncated.

### `presid` [in, out]

Pointer to an **INT** value that receives the resource identifier or index of the icon. If this value is positive, the value is the index of the icon in the file. If this value is negative, the absolute value of this value is the resource identifier of the icon in the file.

## Return value

Returns a standard **HRESULT** value including the following.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)

[IDsDisplaySpecifier::GetIcon](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-geticon)