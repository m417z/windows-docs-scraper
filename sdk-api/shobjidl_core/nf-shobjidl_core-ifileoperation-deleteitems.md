# IFileOperation::DeleteItems

## Description

Declares a set of items that are to be deleted.

## Parameters

### `punkItems` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray), [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), or [IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems) object which represents the group of items to be deleted. You can also point to an [IPersistIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistidlist) object to represent a single item, effectively accomplishing the same function as [IFileOperation::DeleteItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-deleteitem).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not delete the items, it merely declares the items to be deleted. To delete a group of items, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::DeleteItems** to declare the files or folders to be deleted.
2. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to begin the delete operation.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::DeleteItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-deleteitem)