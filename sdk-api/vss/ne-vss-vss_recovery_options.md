# VSS_RECOVERY_OPTIONS enumeration

## Description

Used by a requester to specify how a resynchronization operation is to be performed.

## Constants

### `VSS_RECOVERY_REVERT_IDENTITY_ALL:0x100`

 After the resynchronization operation is complete, the signature of each target LUN should be identical to that of the original LUN that was used to create the shadow copy.

### `VSS_RECOVERY_NO_VOLUME_CHECK:0x200`

Volume safety checks should not be performed.

## See also

[IVssBackupComponentsEx3::RecoverSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex3-recoverset)