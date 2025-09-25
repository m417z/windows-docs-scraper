# SHSetDefaultProperties function

## Description

Applies the default set of properties on a Shell item.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the item's parent window, which receives error notifications. This value can be **NULL**.

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the item.

### `dwFileOpFlags`

Type: **DWORD**

Flags that customize the operation. See [IFileOperation::SetOperationFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-setoperationflags) for flag values.

### `pfops` [in, optional]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

A pointer to an [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) object used to follow the progress of the operation. See [IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise) for details. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The list of properties to set a default value comes from the **SetDefaultsFor** registry entry under the ProgID for the file association of the item. The list is prefixed by "`prop:`" and contains the canonical names of the properties to set the default value, for example, "`prop:System.Author;System.Document.DateCreated`". The possible properties for this list are [System.Author](https://learn.microsoft.com/windows/desktop/properties/props-system-author), [System.Document.DateCreated](https://learn.microsoft.com/windows/desktop/properties/props-system-document-datecreated), and [System.Photo.DateTaken](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-datetaken). If the **SetDefaultsFor** entry does not exist on the ProgID, this function uses the default found on the **SetDefaultsFor** entry of **HKEY_CLASSES_ROOT**\*****.