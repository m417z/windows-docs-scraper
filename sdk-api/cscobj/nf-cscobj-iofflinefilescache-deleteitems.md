# IOfflineFilesCache::DeleteItems

## Description

Deletes files and directories from the local cache. Deleting a container item implies deletion of all its contained items, recursively.

## Parameters

### `rgpszPaths` [in]

Array of pointers, each to a fully qualified UNC path of a file or directory to be deleted.

### `cPaths` [in]

Number of paths in the *rgpszPaths* array.

### `dwFlags` [in]

Flags controlling the behavior of the delete operation. This parameter can be one or more of the following values.

#### OFFLINEFILES_DELETE_FLAG_NOAUTOCACHED (0x00000001)

Do not delete automatically cached items. The default behavior is to delete automatically cached items.

#### OFFLINEFILES_DELETE_FLAG_NOPINNED (0x00000002)

Do not delete pinned items. The default behavior is to delete pinned items.

#### OFFLINEFILES_DELETE_FLAG_DELMODIFIED (0x00000004)

Delete even if locally modified in the cache. The default behavior is to not delete files with unsynchronized local changes.

#### OFFLINEFILES_DELETE_FLAG_ADMIN (0x80000000)

Allows administrators to enumerate and delete all files regardless of access rights. If this flag is set and the caller is not an administrator, the function fails.

### `bAsync` [in]

Indicates if the operation is to be performed asynchronously. If this parameter is **TRUE**, the operation is scheduled for asynchronous operation and the function returns immediately. If this parameter is **FALSE**, the function returns when the operation is complete.

### `pIProgress` [in]

Interface to an event sink that will receive progress events during the operation. If events are not desired, this parameter may be **NULL**. Providing an event sink is highly recommended for asynchronous operation. A progress implementation is the only way to be notified when the asynchronous operation completes.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_CANCELLED)` if the operation is canceled.
Returns HRESULT_FROM_WIN32(ERROR_MORE_DATA) if errors occurred during the operation. Use the [IOfflineFilesSimpleProgress::ItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itemresult) callback method to detect errors as they occur.

## Remarks

The caller must have sufficient access to the files and directories to be deleted.

If a delete operation is canceled while in progress, changes to files processed to that point are not rolled back.

If a delete operation on a directory cannot remove all of its contained files or directories (for example, if access is denied), the specified directory entry is not removed. Any files and directories deleted up to that point remain deleted.

Files are deleted only from the local cache. Associated files on the network server are not affected.

Files deleted are not recoverable through the Recycle Bin. Files deleted must be re-cached to be available offline.

If only one path is provided in the *rgpszPaths* parameter and that path is to a single file, the return value indicates the result of that single delete operation. Otherwise, the caller must implement the progress callback methods in the following list and monitor the [IOfflineFilesSimpleProgress::ItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itemresult) method to obtain the result for each processed file and directory.

| Progress Events Interface | Method | Description |
| --- | --- | --- |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [Begin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-begin) | Called at the start of the operation. |
| [IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress) | [ItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itembegin) | Called at the start of processing for each file. |
| [IOfflineFilesSimpleProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessimpleprogress) | [ItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itemresult) | Called after each file is deleted. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [QueryAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-queryabort) | Called periodically during the sync operation to detect a request for cancellation. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [End](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-end) | Called at the end of the operation. |

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)