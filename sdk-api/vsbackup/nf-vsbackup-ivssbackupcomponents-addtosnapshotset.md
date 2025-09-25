# IVssBackupComponents::AddToSnapshotSet

## Description

The **AddToSnapshotSet** method adds
an original volume or original remote file share to the shadow copy set.

## Parameters

### `pwszVolumeName` [in]

Null-terminated wide character string containing the name of the volume or the UNC path of the remote file share to be shadow copied. The name or UNC path must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)
* A UNC path that specifies a remote file share, for example, \\Clusterx\Share1\

### `ProviderId` [in]

The provider to be used. GUID_NULL can be used, in which case the default provider will be used.

### `pidSnapshot` [out]

Returned identifier of the added shadow copy.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | Successfully added the volume or remote file share to the shadow copy set. |
| **E_ACCESSDENIED**<br><br>0x80070005L | Caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE**<br><br>0x80042301L | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED**<br><br>0x80042312L | The maximum number of volumes or remote file shares have been added to the shadow copy set. The specified volume or remote file share was not added to the shadow copy set. |
| **VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED**<br><br>0x80042317L | The volume or remote file share has been added to the maximum number of shadow copy sets. The specified volume or remote file share was not added to the shadow copy set. |
| **VSS_E_NESTED_VOLUME_LIMIT**<br><br>0x8004232CL | The specified volume is nested too deeply to participate in the VSS operation. Possible reasons for this error include the following:<br><br>* Trying to create a shadow copy of a volume that resides on a VHD that is contained in another VHD.<br>* Trying to create a shadow copy of a VHD volume when the volume that contains the VHD is also in the same shadow copy set.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | *pwszVolumeName* does not correspond to an existing volume or remote file share. |
| **VSS_E_PROVIDER_NOT_REGISTERED**<br><br>0x80042304L | *ProviderId* does not correspond to a registered provider. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_SNAPSHOT_SET_IN_PROGRESS**<br><br>0x80042316L | Another shadow copy creation is already in progress. Occurs when adding a CSV volume to a snapshot set from multiple nodes at the same time, or while adding a scale out share to the snapshot set from multiple SMB client nodes at the same time. |
| **VSS_E_VOLUME_NOT_SUPPORTED**<br><br>0x8004230CL | The value of the *ProviderId* parameter is GUID_NULL and no VSS provider indicates that it supports the specified volume or remote file share. |
| **VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER**<br><br>0x8004230EL | The volume or remote file share is not supported by the specified provider. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR**<br><br>0x8004230FL | The provider returned an unexpected error code. This error code is only returned via the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) method on the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface returned in the *ppAsync* parameter. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

If *pwszVolumeName* is a UNC share path, the server name portion must be in hostname or fully qualified domain name format. UNC share names with IP addresses must be normalized by calling the [IVssBackupComponentsEx4::GetRootAndLogicalPrefixPaths](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex4-getrootandlogicalprefixpaths) method before they are passed to **AddToSnapshotSet**.

The maximum number of shadow copied volumes in a single shadow copy set is 64.

If *ProviderId* is GUID_NULL, the default provider is selected according to the
following algorithm:

1. If any hardware provider supports the given volume or remote file share, that provider is selected.
2. If there is no hardware provider available, if any software provider supports the given volume, it
   is selected.
3. If there is no hardware provider or software provider available, the system provider is selected.
   (There is only one preinstalled system provider, which must support all nonremovable local volumes.)

This method cannot be called for a virtual hard disk (VHD) that is nested inside another VHD.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** VHDs are not supported.

The shadow copy identifier that is returned in the *pidSnapshot* parameter is stored in the Backup Components Document. However, there is no method for querying this information, and the caller may need to store it so that it can be used during restore.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponentsEx4::GetRootAndLogicalPrefixPaths](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex4-getrootandlogicalprefixpaths)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)