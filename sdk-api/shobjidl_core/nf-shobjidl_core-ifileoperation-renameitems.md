# IFileOperation::RenameItems

## Description

Declares a set of items that are to be given a new display name. All items are given the same name.

## Parameters

### `pUnkItems` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray), [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), or [IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems) object which represents the group of items to be renamed. You can also point to an [IPersistIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistidlist) object to represent a single item, effectively accomplishing the same function as [IFileOperation::RenameItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-renameitem).

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to the new display name of the items. This is a null-terminated, Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If more than one of the items in the collection at *pUnkItems* is in the same folder, the renamed files are appended with a number in parentheses to differentiate them, for instance newfile(1).txt, newfile(2).txt, and newfile(3).txt.

This method does not rename the items, it merely declares the items to be renamed. To rename a group of objects, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::RenameItems** to declare the source files or folders and the new name.
2. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to begin the rename operation.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::RenameItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-renameitem)