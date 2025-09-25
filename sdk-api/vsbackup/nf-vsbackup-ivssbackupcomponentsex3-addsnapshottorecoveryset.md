# IVssBackupComponentsEx3::AddSnapshotToRecoverySet

## Description

Specifies the volumes to be included in a LUN resynchronization operation. This method is supported only on Windows server operating systems.

## Parameters

### `snapshotId` [in]

The identifier of the shadow copy that was returned by the [IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset) method during backup. This parameter is required and cannot be GUID_NULL.

### `dwFlags` [in]

This parameter is reserved and must be zero.

### `pwszDestinationVolume` [in, optional]

This parameter is optional and can be **NULL**. A value of **NULL** means that the contents of the shadow copy volume are to be copied back to the original volume. VSS identifies the original volume by the VDS_LUN_INFO information in the Backup Components Document.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **VSS_E_BAD_STATE**<br><br>0x80042301L | Either there is no hardware provider that supports the operation, or the requester did not successfully add any volumes to the recovery set. |
| **VSS_E_LEGACY_PROVIDER**<br><br>0x800423F7L | This version of the hardware provider does not support this operation. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *snapshotId* parameter specifies a shadow copy that the hardware provider does not own. |
| **VSS_E_RESYNC_IN_PROGRESS**<br><br>0x800423FFL | Another LUN resynchronization operation is already in progress. |
| **VSS_E_SNAPSHOT_NOT_IN_SET**<br><br>0x8004232BL | The *snapshotId* parameter specifies a shadow copy that does not exist in the Backup Components Document. |
| **VSS_E_VOLUME_NOT_SUPPORTED**<br><br>0x8004230CL | LUN resynchronization is not supported on this volume, because it is a dynamic volume, because the destination disk does not have a unique page 83 storage identifier, because the specified volume does not reside on a LUN managed by a VSS hardware provider, or because the destination disk is a cluster quorum disk. |

## See also

[IVssBackupComponentsEx3](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex3)