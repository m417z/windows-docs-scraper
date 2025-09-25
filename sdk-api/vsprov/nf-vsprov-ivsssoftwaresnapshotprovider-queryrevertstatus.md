# IVssSoftwareSnapshotProvider::QueryRevertStatus

## Description

Returns an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used to determine the status of the revert operation.

## Parameters

### `pwszVolume` [in]

Null-terminated wide character string containing the volume name. The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `ppAsync` [out]

Pointer to a location that will receive an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used to retrieve the status of the revert operation. When the operation is complete, the caller must release the interface pointer by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The status of the revert operation was successfully queried. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| ****VSS_E_OBJECT_NOT_FOUND**** | The *pwszVolume* parameter does not specify a valid volume. |
| ****VSS_E_VOLUME_NOT_SUPPORTED**** | The revert operation is not supported on this volume. |

## Remarks

The revert operation will continue even if the computer is rebooted, and cannot be canceled or undone, except by restoring a backup that was created using another method. The [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method cannot return VSS_S_ASYNC_CANCELLED, because the revert operation cannot be canceled after it has started.

## See also

[IVssSoftwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsssoftwaresnapshotprovider)