# IFileOperationProgressSink::PostRenameItem

## Description

Performs caller-implemented actions after the rename process for each item is complete.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that were used during the rename operation. Some values can be set or changed during the rename operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the item before it was renamed.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to the new [display name](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-getdisplayname) of the item. This is a null-terminated, Unicode string. Note that this might not be the name that you asked for, given collisions and other naming rules.

### `hrRename` [in]

Type: **HRESULT**

The return value of the rename operation. Note that this is not the HRESULT returned by [RenameItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-renameitem), which simply queues the rename operation. Instead, this is the result of the actual rename operation.

### `psiNewlyCreated` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the item with its new name.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.