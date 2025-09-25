# DsGetIcon function

## Description

The **DsGetIcon** function obtains the icon for a given object class. This function is obsolete. New applications should use the [IDsDisplaySpecifier::GetIcon](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-geticon) method to perform this function.

## Parameters

### `dwFlags` [in]

Contains a set of flags that indicate the type of icon to retrieve. This can be a combination of one or more of the following values.

#### DSGIF_ISNORMAL

Obtains the normal icon for the object class.

#### DSGIF_ISOPEN

Obtains the open icon, such as an open folder, for the object class. If the object class does not have an open icon, this function attempts to obtain the normal icon for the object class.

#### DSGIF_ISDISABLED

Obtains the disabled icon, such as a disabled user, for the object class. If the object class does not have a disabled icon, this function attempts to obtain the normal icon for the object class.

#### DSGIF_GETDEFAULTICON

If no icon can be found for the object class, this function will return a default icon. If this flag is not specified and no icon can be found for the object class, this function returns **NULL**.

#### DSGIF_DEFAULTISCONTAINER

If no icon can be found for the object class, this function returns the container icon as the default icon. If this flag is not specified and no icon can be found for the object class, this function returns **NULL**.

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to retrieve the icon for. Examples of the object class name are "user" and "container".

### `cxImage` [in]

Contains the desired width, in pixels, of the icon. This function retrieves the icon that most closely matches this width.

### `cyImage` [in]

Contains the desired height, in pixels, of the icon. This function retrieves the icon that most closely matches this height.

## Return value

Returns a handle to the icon if successful or **NULL** otherwise. The caller must destroy this icon when it is no longer required by passing this handle to [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon).

## See also

[DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon)

[IDsDisplaySpecifier::GetIcon](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-geticon)