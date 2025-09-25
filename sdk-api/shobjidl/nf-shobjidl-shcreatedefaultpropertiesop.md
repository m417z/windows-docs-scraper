# SHCreateDefaultPropertiesOp function

## Description

Creates a file operation that sets the default properties on the Shell item that have not already been set.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the source shell item. See [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `ppFileOp` [out]

Type: **[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)****

The address of the [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The list of properties to set a default value comes from the **SetDefaultsFor** registry entry under the ProgID for the file association of the item. The list is prefixed by `prop:` and contains the canonical names of the properties to set the default value, for example, `prop:System.Author;System.Document.DateCreated`. The possible properties for this list are [System.Author](https://learn.microsoft.com/windows/desktop/properties/props-system-author), [System.Document.DateCreated](https://learn.microsoft.com/windows/desktop/properties/props-system-document-datecreated), and [System.Photo.DateTaken](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-datetaken). If the **SetDefaultsFor** entry does not exist on the ProgID, this function uses the default found on the **SetDefaultsFor** entry of **HKEY_CLASSES_ROOT**\*****.