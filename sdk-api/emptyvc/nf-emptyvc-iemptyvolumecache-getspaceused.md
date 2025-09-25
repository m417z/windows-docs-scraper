# IEmptyVolumeCache::GetSpaceUsed

## Description

Requests the amount of disk space that the disk cleanup handler can free.

## Parameters

### `pdwlSpaceUsed` [out]

Type: **DWORDLONG***

The amount of disk space, in bytes, that the handler can free. This value will be displayed in the disk cleanup manager's list, to the right of the handler's check box. To indicate that you do not know how much disk space can be freed, set this parameter to -1, and "???MB" will be displayed. If you set the **EVCF_DONTSHOWIFZERO** flag when [Initialize](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-initialize) was called, setting *pdwSpaceUsed* to zero will notify the disk cleanup manager to omit the handler from its list.

### `picb` [in]

Type: **IEmptyVolumeCacheCallback***

A pointer to the disk cleanup manager's [IEmptyVolumeCacheCallback](https://learn.microsoft.com/windows/desktop/api/emptyvc/nn-emptyvc-iemptyvolumecachecallback) interface. This pointer can be used to call that interface's [ScanProgress](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecachecallback-scanprogress) method to report on the progress of the operation.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | An error occurred when the handler tried to calculate the amount of disk space that could be freed. |
| **E_ABORT** | The scan operation was ended prematurely. This value is usually returned when a call to [ScanProgress](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecachecallback-scanprogress) returns E_ABORT. This return value indicates that the user canceled the operation by clicking the disk cleanup manager's **Cancel** button. |

## Remarks

When this method is called by the disk cleanup manager, the handler should start scanning its files to determine which of them can be deleted, and how much disk space will be freed. Handlers should call [IEmptyVolumeCache::ScanProgress](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecachecallback-scanprogress) periodically to keep the user informed of the progress of the scan, especially if it will take a long time. Calling this method frequently also allows the handler to determine whether the user has canceled the operation. If **ScanProgress** returns E_ABORT, the user has canceled the scan. The handler should immediately stop scanning and return E_ABORT.

You should only set the *pdwSpaceUsed* parameter to -1 as a last resort. The handler is of limited value to a user if they don't know how much space will be freed.