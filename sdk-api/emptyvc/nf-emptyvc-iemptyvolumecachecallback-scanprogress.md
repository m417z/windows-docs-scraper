# IEmptyVolumeCacheCallBack::ScanProgress

## Description

Called by a disk cleanup handler to update the disk cleanup manager on the progress of a scan for deletable files.

## Parameters

### `dwlSpaceUsed` [in]

Type: **DWORDLONG**

The amount of disk space that the handler can free at this point in the scan.

### `dwFlags` [in]

Type: **DWORD**

A flag that can be sent to the disk cleanup manager. This flag can have the following value.

#### EVCCBF_LASTNOTIFICATION

This flag should be set if the handler will not call this method again. It is typically set when the scan is near completion.

### `pcwszStatus` [in]

Type: **LPCWSTR**

Reserved.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The handler should continue scanning for deletable files. |
| **E_ABORT** | This value is returned when the user clicks the **Cancel** button on the disk cleanup manager's dialog box while a scan is in progress. The handler should stop scanning and shut down. |

## Remarks

This method is typically called by the handler's [GetSpaceUsed](https://learn.microsoft.com/windows/desktop/api/emptyvc/nf-emptyvc-iemptyvolumecache-getspaceused) method while the handler is scanning for deletable files.