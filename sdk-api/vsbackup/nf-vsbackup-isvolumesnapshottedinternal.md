# IsVolumeSnapshottedInternal function

## Description

The **IsVolumeSnapshotted** function determines
whether any shadow copies exist for the specified volume.

**Note** This function is exported as **IsVolumeSnapshottedInternal**, but you should call **IsVolumeSnapshotted**, not **IsVolumeSnapshottedInternal**.

## Parameters

### `pwszVolumeName` [in]

Name of the volume. The name of the volume to be checked must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `pbSnapshotsPresent` [out]

The value of this parameter is **TRUE** if the volume has a shadow copy, and
**FALSE** if the volume does not have a shadow copy.

### `plSnapshotCapability` [out]

A bit mask (or bitwise OR) of
[VSS_SNAPSHOT_COMPATIBILITY](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_compatibility) values that
indicates whether certain volume control or file I/O operations are disabled for the given volume if a shadow
copy of it exists.

## Return value

The return values listed here are in addition to the normal COM **HRESULT**s that may be returned at any time
from the function.

| Value | Meaning |
| --- | --- |
| **S_OK** | The function completed successfully. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | Out of memory or other system resources. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume was not found. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. **E_UNEXPECTED** is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | Unexpected provider error. The error code is logged in the event log file. For additional information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

Before calling this function, the caller must have initialized COM by calling the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) function.

If no volume control or file I/O operations are disabled for the selected volume, then the shadow copy
capability of the selected volume returned by *plSnapshotCapability* will be zero.

## See also

[VSS_SNAPSHOT_COMPATIBILITY](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_compatibility)