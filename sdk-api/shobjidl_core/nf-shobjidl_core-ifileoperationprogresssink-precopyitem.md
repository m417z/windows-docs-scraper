# IFileOperationProgressSink::PreCopyItem

## Description

Performs caller-implemented actions before the copy process for each item begins.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that control the operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the source item.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder to contain the copy of the item.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to a new name for the item after it has been copied. This is a null-terminated Unicode string and can be **NULL**. If **NULL**, the name of the destination item is the same as the source.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, the copy operation and all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.