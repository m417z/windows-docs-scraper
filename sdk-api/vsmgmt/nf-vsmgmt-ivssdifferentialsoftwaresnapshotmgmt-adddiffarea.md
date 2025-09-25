# IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea

## Description

The **AddDiffArea**
method adds a shadow copy storage area association for the specified volume. If the
association is not supported, an error code will be returned.

## Parameters

### `pwszVolumeName` [in]

The name of the volume that will be the source of shadow copies. This volume is associated with a shadow copy
storage area on the *pwszDiffAreaVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `pwszDiffAreaVolumeName` [in]

The name of the volume that will contain the shadow copy storage area to be associated with the
*pwszVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `llMaximumDiffSpace` [in]

The maximum size, in bytes, of the shadow copy storage area on the volume. This value
must be at least 320 MB, up to the system-wide limit.
If this value is –1, the maximum size is unlimited.

**Windows Server 2003:** Prior to Windows Server 2003 with SP1, the shadow copy storage area size was fixed at 100 MB.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the shadow copy storage area association. |
| **E_ACCESSDENIED** | Caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED** | The maximum number of shadow copy storage areas has been added to the shadow copy source volume. The specified shadow copy storage volume was not associated with the specified shadow copy source volume. |
| **VSS_E_NESTED_VOLUME_LIMIT** | The specified volume is nested too deeply to participate in the VSS operation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| **VSS_E_OBJECT_ALREADY_EXISTS** | The association between the *pwszVolumeName* and *pwszDiffAreaVolumeName* volumes already exists. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_VOLUME_NOT_SUPPORTED** | The *pwszDiffAreaVolumeName* volume is not an NTFS volume or has insufficient free space. |

## Remarks

A shadow copy storage area association cannot be created if any shadow copies already exist for the
*pwszVolumeName* volume or if there is already a shadow copy storage area association for
that volume.

The shadow copy storage area for a virtual hard disk (VHD) source volume must reside on the same volume. Likewise, a shadow copy storage area can only be created on a VHD volume if the source volume is the same for both volumes.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** VHDs are not supported.

To change the size of a shadow copy storage area, use the [IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize) or [IVssDifferentialSoftwareSnapshotMgmt2::ChangeDiffAreaMaximumSizeEx](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt2-changediffareamaximumsizeex) method. You can delete a shadow copy storage area by changing its size to zero.

## See also

[IVssDifferentialSoftwareSnapshotMgmt](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt)