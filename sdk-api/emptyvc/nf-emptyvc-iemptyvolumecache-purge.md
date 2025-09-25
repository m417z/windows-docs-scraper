# IEmptyVolumeCache::Purge

## Description

Notifies the handler to start deleting its unneeded files.

## Parameters

### `dwlSpaceToFree` [in]

Type: **DWORDLONG**

The amount of disk space that the handler should free. If this parameter is set to -1, the handler should delete all its files.

### `picb` [in]

Type: **IEmptyVolumeCacheCallback***

A pointer to the disk cleanup manager's [IEmptyVolumeCacheCallBack](https://learn.microsoft.com/windows/desktop/api/emptyvc/nn-emptyvc-iemptyvolumecachecallback) interface. This pointer can be used to call the interface's [PurgeProgress](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecachecallback-purgeprogress) method to report on the progress of the operation.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_ABORT** | The operation was ended prematurely. This value is usually returned when [PurgeProgress](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecachecallback-purgeprogress) returns E_ABORT. This typically happens when the user cancels the operation by clicking the disk cleanup manager's **Cancel** button. |

## Remarks

For Windows 98, the *dwSpaceToFree* parameter is always set to the value specified by the handler when [IEmptyVolumeCache::GetSpaceUsed](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-getspaceused) was called.

In general, handlers should be kept simple and delete all of their files when this function is called. If there are significant performance advantages to only deleting a portion of the files, the handler should implement the [ShowProperties](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-showproperties) method. When called, this method displays a UI that allows the user to select the files to be deleted.