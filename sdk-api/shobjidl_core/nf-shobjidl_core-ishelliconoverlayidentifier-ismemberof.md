# IShellIconOverlayIdentifier::IsMemberOf

## Description

Specifies whether an icon overlay should be added to a Shell object's icon.

## Parameters

### `pwszPath` [in]

Type: **PCWSTR**

A Unicode string that contains the fully qualified path of the Shell object.

### `dwAttrib`

Type: **DWORD**

The object's attributes. For a complete list of file attributes and their associated flags, see [File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

## Return value

Type: **HRESULT**

This method returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The icon overlay should be displayed. |
| **S_FALSE** | The icon overlay should not be displayed. |
| **E_FAIL** | The operation failed. |

## Remarks

The Shell calls this method to determine whether it should display a handler's icon overlay for a particular object. Icon overlay handlers are usually intended to work with a particular group of files. A typical example is a [file type](https://learn.microsoft.com/windows/desktop/shell/fa-file-types), identified by a specific file name extension. An icon overlay handler might request an icon overlay for all members of the file type. Some handlers request an icon overlay only if a member of the file type is in a particular state. However, icon overlay handlers are free to request their icon overlay for any object that they want.

## See also

[IShellIconOverlayIdentifier](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelliconoverlayidentifier)