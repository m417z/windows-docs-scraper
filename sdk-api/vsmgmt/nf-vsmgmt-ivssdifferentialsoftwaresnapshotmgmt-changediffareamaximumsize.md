# IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize

## Description

The
**ChangeDiffAreaMaximumSize**
method updates the shadow copy storage area maximum size for a certain volume. This may not
have an immediate effect.

## Parameters

### `pwszVolumeName` [in]

Name of the volume that is the source of shadow copies. This volume is associated with a shadow copy storage area
on the *pwszDiffAreaVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `pwszDiffAreaVolumeName` [in]

Name of the volume that contains the shadow copy storage area associated with the
*pwszVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `llMaximumDiffSpace` [in]

Specifies the maximum size, in bytes, for the shadow copy storage area to use for the volume. If this value is zero,
the shadow copy storage area will be deleted. If this value is –1, the maximum size is unlimited.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully changed the shadow copy storage area maximum size. |
| **E_ACCESSDENIED** | Caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INSUFFICIENT_STORAGE** | The *pwszDiffAreaVolumeName* volume does not have sufficient free space. |
| **VSS_E_OBJECT_NOT_FOUND** | The association between the *pwszVolumeName* and *pwszDiffAreaVolumeName* volumes was not found. |
| **VSS_E_PROVIDER_VETO** | Provider error - the provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_VOLUME_IN_USE** | A shadow copy is currently using the shadow copy storage area. |

## Remarks

The **ChangeDiffAreaMaximumSize** method makes the shadow copy storage area explicit, which means that it is not deleted automatically when all shadow copies are deleted.

If the shadow copy storage area does not exist, this method creates it.

**Windows Server 2008, Windows Vista and Windows Server 2003:** If the shadow copy storage area does not exist, this method does not create it.

To create a shadow copy storage area, use the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea) method.

## See also

[IVssDifferentialSoftwareSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt)