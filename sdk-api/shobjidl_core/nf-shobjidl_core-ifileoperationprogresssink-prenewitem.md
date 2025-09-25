# IFileOperationProgressSink::PreNewItem

## Description

Performs caller-implemented actions before the process to create a new item begins.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that control the operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder that will contain the new item.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to the file name of the new item, for instance **Newfile.txt**. This is a null-terminated, Unicode string.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, this operation and all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.