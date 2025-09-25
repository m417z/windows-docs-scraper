# IFileOperationProgressSink::PreDeleteItem

## Description

Performs caller-implemented actions before the delete process for each item begins.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that control the operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the item to be deleted.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, the delete operation and all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.