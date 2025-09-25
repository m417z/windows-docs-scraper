# IVssDifferentialSoftwareSnapshotMgmt2::ChangeDiffAreaMaximumSizeEx

## Description

Updates the shadow copy storage area maximum size for a certain volume. This may not
have an immediate effect. If the *bVolatile* parameter is **FALSE**, the change continues even if the computer is rebooted.

## Parameters

### `pwszVolumeName` [in]

The name of the volume that is the source of shadow copies. This volume is associated with a shadow copy storage area
on the *pwszDiffAreaVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `pwszDiffAreaVolumeName` [in]

The name of the volume that contains the shadow copy storage area that is associated with the
*pwszVolumeName* volume.

The name of the volume must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder
* A drive letter with, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `llMaximumDiffSpace` [in]

Specifies the maximum size, in bytes, for the shadow copy storage area to use for the volume. If this value is zero,
the shadow copy storage area will be deleted. If this value is –1, the maximum size is unlimited.

### `bVolatile` [in]

TRUE to indicate that the effect of calling the **ChangeDiffAreaMaximumSizeEx** method should not continue if the computer is rebooted; otherwise, **FALSE**.

The default value is **FALSE**.

If the *llMaximumDiffSpace* parameter is zero, the *bVolatile* parameter must be **FALSE**.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy storage area maximum size was successfully changed. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INSUFFICIENT_STORAGE** | The *pwszDiffAreaVolumeName* volume does not have sufficient free space. |
| **VSS_E_OBJECT_NOT_FOUND** | The association between the *pwszVolumeName* and *pwszDiffAreaVolumeName* volumes was not found. |
| **VSS_E_PROVIDER_VETO** | An expected provider error has occurred. The error code is logged in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_VOLUME_IN_USE** | A shadow copy is currently using the shadow copy storage area. |

## Remarks

The **ChangeDiffAreaMaximumSizeEx** method is identical to the [IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize) method except for the *bVolatile* parameter.

Calling the **ChangeDiffAreaMaximumSizeEx** method with the *bVolatile* parameter set to **FALSE** is the same as calling the [ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize) method.

**ChangeDiffAreaMaximumSizeEx** makes the shadow copy storage area explicit, which means that it is not deleted automatically when all shadow copies are deleted.

If the shadow copy storage area does not exist, this method creates it.

**Windows Server 2008, Windows Vista and Windows Server 2003:** If the shadow copy storage area does not exist, this method does not create it.

To create a shadow copy storage area, use the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea) method.

## See also

[IVssDifferentialSoftwareSnapshotMgmt2](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt2)

[IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize)