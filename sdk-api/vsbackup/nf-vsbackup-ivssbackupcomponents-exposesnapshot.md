# IVssBackupComponents::ExposeSnapshot

## Description

The **ExposeSnapshot** method exposes a
shadow copy as a drive letter, mounted folder, or file share.

## Parameters

### `SnapshotId` [in]

Shadow copy identifier.

### `wszPathFromRoot` [in]

The path to the portion of the volume made available when exposing a shadow copy as a file share. The value of
this parameter must be **NULL** when exposing a shadow copy locally; that is, exposing it as a drive letter or mounted folder.

The path cannot contain environment variables (for example, %MyEnv%) or wildcard characters.

There is no requirement that the path end with a backslash ("\"). It is up to applications that
retrieve this information to check.

### `lAttributes` [in]

Attributes of the exposed shadow copy indicating whether it is exposed locally or remotely. The value must be
either the **VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY** or the
**VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY** value of
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes).

### `wszExpose` [in]

When a shadow copy is exposed as a file share, the value of this parameter is the share name. If a shadow copy
is exposed by mounting it as a device, the parameter value is a drive letter followed by a colon—for
example, "X:" or a mounted folder path (for example, "Y:\MountX"). If the value of this parameter is **NULL**, then VSS
determines the share name or drive letter if the *lAttributes* parameter is
**VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY**.

### `pwszExposed` [out]

The exposed name of the shadow copy. This is either a share name, a drive letter followed by a colon,
or a mounted folder. The value is **NULL** if
**ExposeSnapshot** failed.
VSS allocates the memory for this string.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copies were successfully exposed. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | Unexpected provider error. The error code is logged in the error log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

The caller is responsible for freeing the string that the *pwszExposed* parameter points to by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

When exposing a persistent shadow copy, it remains exposed through subsequent boots.

When exposing a shadow copy of a volume, the shadow copy may be treated either as a mountable device or as a file
system available for file sharing.

When it is exposed as a device—as with other mountable devices—the shadow copy of a volume is exposed
at its mount point (drive letter or mounted folder) starting with its root.

When exposed as a file share, subsets (indicated by *wszPathFromRoot*) of the volume can
be shared.

For more information on how to expose shadow copies, see
[Exposing and Surfacing Shadow Copied
Volumes](https://learn.microsoft.com/windows/desktop/VSS/exposing-and-surfacing-shadow-copied-volumes).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::ImportSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-importsnapshots)

[IVssBackupComponentsEx2::UnexposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-unexposesnapshot)

[VSS_PWSZ](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)