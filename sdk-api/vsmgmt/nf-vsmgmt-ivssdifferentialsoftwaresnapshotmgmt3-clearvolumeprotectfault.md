# IVssDifferentialSoftwareSnapshotMgmt3::ClearVolumeProtectFault

## Description

Clears the protection fault state for the specified volume.

## Parameters

### `pwszVolumeName` [in]

The name of the volume.
This parameter is required and cannot be **NULL**.

The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path in the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The protection fault state was cleared successfully. |
| **E_ACCESSDENIED**<br><br>0x80070005L | The caller is not an administrator. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_NOTIMPL**<br><br>0x80000001L | The provider for the volume does not support shadow copy protection. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An expected provider error has occurred. The error code is logged in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The specified volume was not found. |

## Remarks

The **ClearVolumeProtectFault** method dismounts the volume and resets the volume's protection fault member to **FALSE** to allow normal I/O to continue on the volume. If the volume is not in a faulted state, this method does nothing.

## See also

[IVssDifferentialSoftwareSnapshotMgmt3](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3)