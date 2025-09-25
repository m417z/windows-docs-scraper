# IVssBackupComponents::IsVolumeSupported

## Description

The
**IsVolumeSupported** method determines whether the specified provider supports shadow copies on the specified volume or remote file share.

## Parameters

### `ProviderId` [in]

Provider identifier. If the value is GUID_NULL,
**IsVolumeSupported** checks whether any provider supports the volume or remote file share.

### `pwszVolumeName` [in]

Volume name or UNC path of remote file share. The name or UNC path must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example, D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)
* A UNC path that specifies a remote file share, for example, \\Clusterx\Share1\

### `pbSupportedByThisProvider` [out]

Address of a caller-allocated variable that receives **TRUE** if shadow copies are supported on the specified volume or remote file share, or **FALSE** otherwise.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the provider support information. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **VSS_E_NESTED_VOLUME_LIMIT** | The specified volume is nested too deeply to participate in the VSS operation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume or remote file share was not found or was not available. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

**IsVolumeSupported** will return **TRUE** if it is possible to create shadow copies on the given volume, even if the current configuration does not allow the creation of shadow copies on that volume at the present time.

For example, if the maximum number of shadow copies has been reached on a given volume (and therefore no more shadow copies can be created on that volume), the method will still indicate that the volume can be shadow copied.

**Note** For more information about the maximum number of shadow copies that can be created on a volume, see the entry for **MaxShadowCopies** in [Registry Keys and Values for Backup and Restore](https://learn.microsoft.com/windows/desktop/Backup/registry-keys-for-backup-and-restore).

This method cannot be called for a virtual hard disk (VHD) that is nested inside another VHD.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** VHDs are not supported.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset)