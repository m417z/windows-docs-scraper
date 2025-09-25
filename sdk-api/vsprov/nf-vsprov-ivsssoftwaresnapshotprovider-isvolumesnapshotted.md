# IVssSoftwareSnapshotProvider::IsVolumeSnapshotted

## Description

Determines whether any shadow copies exist for the specified volume.

## Parameters

### `pwszVolumeName` [in]

Null-terminated wide character string containing the volume name. The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where GUID identifies the volume)

### `pbSnapshotsPresent` [out]

This parameter receives **TRUE** if the volume has a shadow copy, or **FALSE** if the volume does not have a shadow copy.

### `plSnapshotCompatibility` [out]

A bitmask of [VSS_SNAPSHOT_COMPATIBILITY](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_compatibility) values that indicate whether certain volume control or file I/O operations are disabled for the given volume, if the volume has a shadow copy.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The requested information was successfully returned. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume was not found. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

If no volume control or file I/O operations are disabled for the selected volume, then the shadow copy capability of the selected volume returned by *plSnapshotCapability* will be zero.

## See also

[IVssSoftwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsssoftwaresnapshotprovider)