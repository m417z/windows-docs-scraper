# IVssDifferentialSoftwareSnapshotMgmt3::SetVolumeProtectLevel

## Description

Sets the shadow copy protection level for an original volume or a shadow copy storage area volume.

## Parameters

### `pwszVolumeName` [in]

The name of the volume.
This parameter is required and cannot be **NULL**.

The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path in the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `protectionLevel` [in]

A value from the [VSS_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_protection_level) enumeration that specifies the shadow copy protection level.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy protection level was set successfully. |
| **E_ACCESSDENIED**<br><br>0x80070005L | The caller is not an administrator. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_NOTIMPL**<br><br>0x80000001L | The provider for the volume does not support shadow copy protection. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An expected provider error has occurred. The error code is logged in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The specified volume was not found. |

## Remarks

The **SetVolumeProtectLevel** method checks the current shadow copy protection level of the volume. If the volume is in a faulted state and VSS_PROTECTION_LEVEL_ORIGINAL_VOLUME is specified for the *protectionLevel* parameter, **SetVolumeProtectLevel** dismounts the volume before setting the protection level.

If the current protection level of the volume is the same as the value of the *protectionLevel* parameter, **SetVolumeProtectLevel** does nothing.

If the value of the *protectionLevel* parameter is **VSS_PROTECTION_LEVEL_SNAPSHOT**, requesters must set shadow copy storage area (diff area) associations using the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea) method.

## See also

[IVssDifferentialSoftwareSnapshotMgmt3](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3)

[IVssDifferentialSoftwareSnapshotMgmt3::GetVolumeProtectLevel](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-getvolumeprotectlevel)