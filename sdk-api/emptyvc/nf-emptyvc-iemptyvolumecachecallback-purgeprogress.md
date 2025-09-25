# IEmptyVolumeCacheCallBack::PurgeProgress

## Description

Called periodically by a disk cleanup handler to update the disk cleanup manager on the progress of a purge of deletable files.

## Parameters

### `dwlSpaceFreed` [in]

Type: **DWORDLONG**

The amount of disk space, in bytes, that has been freed at this point in the purge. The disk cleanup manager uses this value to update its progress bar.

### `dwlSpaceToFree` [in]

Type: **DWORDLONG**

The amount of disk space, in bytes, that remains to be freed at this point in the purge.

### `dwFlags` [in]

Type: **DWORD**

A flag that can be sent to the disk cleanup manager. It can have the following value:

#### EVCCBF_LASTNOTIFICATION

This flag should be set if the handler will not call this method again. It is typically set when the purge is near completion.

### `pcwszStatus` [in]

Type: **LPCWSTR**

Reserved.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The handler should continue purging deletable files. |
| **E_ABORT** | This value is returned when the user clicks the **Cancel** button on the disk cleanup manager's dialog box while a scan is in progress. The handler should stop purging files and shut down. |

## Remarks

This method is typically called by the handler's [Purge](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-purge) method while the handler is purging deletable files. Handlers should call **PurgeProgress** periodically to keep the user informed of progress, especially if the purge will take a long time. Calling this method frequently also allows the handler to shut down promptly if a user cancels a purge.