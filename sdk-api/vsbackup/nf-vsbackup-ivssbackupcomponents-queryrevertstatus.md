# IVssBackupComponents::QueryRevertStatus

## Description

The **QueryRevertStatus** method
returns an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface pointer that can be used
to determine the status of the revert operation.

## Parameters

### `pwszVolume` [in]

Null-terminated wide character string containing the name of the volume. The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `ppAsync` [out]

Pointer to a location that will receive an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)
interface pointer that can be used to retrieve the status of the revert process. When the operation is complete, the caller must release the interface pointer by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_ACCESSDENIED** | The calling process has insufficient privileges. |
| **E_FAIL** | There is an internal error. |
| **E_INVALIDARG** | One of the parameters passed is not valid. |
| **E_NOTIMPL** | The provider for the volume does not support revert operations. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **E_POINTER** | One of the required pointer parameters is **NULL**. |
| **VSS_E_OBJECT_NOT_FOUND** | The *pwszVolume* parameter is not a valid volume. |
| **VSS_E_VOLUME_NOT_SUPPORTED** | Revert is not supported on this volume. |

## Remarks

The revert operation will continue even if the computer is rebooted, and cannot be canceled or undone, except
by restoring a backup created using another method. The
[QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the returned
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface cannot return
**VSS_S_ASYNC_CANCELLED** as the revert operation cannot be canceled after it has
started.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::RevertToSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-reverttosnapshot)