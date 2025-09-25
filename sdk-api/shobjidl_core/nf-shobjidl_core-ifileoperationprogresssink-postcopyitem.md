# IFileOperationProgressSink::PostCopyItem

## Description

Performs caller-implemented actions after the copy process for each item is complete.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

bitwise value that contains flags that were used during the copy operation. Some values can be set or changed during the copy operation. See [TRANSFER_SOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_transfer_source_flags) for flag descriptions.

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the source item.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder to which the item was copied.

### `pszNewName` [in]

Type: **LPCWSTR**

Pointer to the new name that was given to the item after it was copied. This is a null-terminated Unicode string. Note that this might not be the name that you asked for, given collisions and other naming rules.

### `hrCopy` [in]

Type: **HRESULT**

The return value of the copy operation. Note that this is not the HRESULT returned by [CopyItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-copyitem), which simply queues the copy operation. Instead, this is the result of the actual copy.

### `psiNewlyCreated` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the new copy of the item.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. In the case of an error value, all subsequent operations pending from the call to [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) are canceled.

## See also

[CopyItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-copyitem)

[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)

[IFileOperationProgressSink::PreCopyItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-precopyitem)