# IFileOperationProgressSink::PostDeleteItem

## Description

Performs caller-implemented actions after the delete process for each item is complete.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that were used during the delete operation. Some values can be set or changed during the delete operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the item that was deleted.

### `hrDelete` [in]

Type: **HRESULT**

The return value of the delete operation. Note that this is not the HRESULT returned by [DeleteItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-deleteitem), which simply queues the delete operation. Instead, this is the result of the actual deletion.

### `psiNewlyCreated` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the deleted item, now in the Recycle Bin. If the item was fully deleted, this value is **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.