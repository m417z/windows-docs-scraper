# IVssDifferentialSoftwareSnapshotMgmt3::GetVolumeProtectLevel

## Description

Gets the shadow copy protection level and status for the specified volume.

## Parameters

### `pwszVolumeName` [in]

The name of the volume.
This parameter is required and cannot be **NULL**.

The name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path in the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `protectionLevel` [out]

The address of a caller-allocated buffer that receives a [VSS_VOLUME_PROTECTION_INFO](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_protection_info) structure containing information about the volume's shadow copy protection level.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy protection level was queried successfully. |
| **E_ACCESSDENIED**<br><br>0x80070005L | The caller is not an administrator. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_NOTIMPL**<br><br>0x80000001L | The provider for the volume does not support shadow copy protection. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An expected provider error has occurred. The error code is logged in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The specified volume was not found. |

## Remarks

The **GetVolumeProtectLevel** method gets information about the volume's current protection level. If the volume is in a faulted state, the **m_protectionFault** member of the [VSS_VOLUME_PROTECTION_INFO](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_protection_info) structure contains the current protection fault, and the **m_failureStatus** member contains the reason why the volume is in a faulted state. If the volume is not in a faulted state, the **m_protectionFault** and **m_failureStatus** members will be zero.

If the value of the *protectionLevel* parameter is **VSS_PROTECTION_LEVEL_SNAPSHOT**, requesters must set shadow copy storage area (diff area) associations using the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea) method.

## See also

[IVssDifferentialSoftwareSnapshotMgmt3](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3)

[IVssDifferentialSoftwareSnapshotMgmt3::SetVolumeProtectLevel](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-setvolumeprotectlevel)