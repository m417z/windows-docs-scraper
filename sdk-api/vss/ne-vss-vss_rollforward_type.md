# VSS_ROLLFORWARD_TYPE enumeration

## Description

The **VSS_ROLLFORWARD_TYPE** enumeration is used by a
requester to indicate the type of roll-forward operation it is about to perform.

## Constants

### `VSS_RF_UNDEFINED:0`

No roll-forward type is defined.

This indicates an error on the part of the requester.

### `VSS_RF_NONE`

The roll-forward operation should not roll forward through logs.

### `VSS_RF_ALL`

The roll-forward operation should roll forward through all logs.

### `VSS_RF_PARTIAL`

The roll-forward operation should roll forward through logs up to a specified restore point.

## Remarks

A requester sets the roll-forward operation type and specifies the restore point for partial roll-forward operations using
[IVssBackupComponentsEx2::SetRollForward](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrollforward).

## See also

[IVssBackupComponentsEx2::SetRollForward](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrollforward)