# VSS_SUBSCRIBE_MASK enumeration

## Description

The **VSS_SUBSCRIBE_MASK** enumeration is used by a
writer when subscribing to the VSS service. It indicates the events that the writer is willing to
receive.

## Constants

### `VSS_SM_POST_SNAPSHOT_FLAG:0x00000001`

This enumeration value is reserved for future use.

Specifies that the writer expects to be notified after the shadow copy it is participating in has completed.
It will then call
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

### `VSS_SM_BACKUP_EVENTS_FLAG:0x00000002`

Currently, **VSS_SM_BACKUP_EVENTS_FLAG** can be used as an argument only when
combined through a bitwise OR with **VSS_SM_RESTORE_EVENTS_FLAG**.

Specifies that the writer can expect to receive the following events:

* A PrepareForSnapshot event when the writer will call
  [CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot).
* A PrepareForBackup event when the writer will call
  [CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup).
* A Freeze event when the writer will call
  [CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze).
* A BackupComplete event when the writer will call
  [CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete).
* A Thaw event when the writer will call
  [CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw).
* A PostSnapshot event when the writer will call
  [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

### `VSS_SM_RESTORE_EVENTS_FLAG:0x00000004`

Currently, **VSS_SM_RESTORE_EVENTS_FLAG** can be used as an argument only when
combined through a bitwise OR with **VSS_SM_BACKUP_EVENTS_FLAG**.

Specifies that the writer can expect to receive the following events:

* A PreRestore event when the writer will call
  [CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore).
* A PostRestore event when the writer will call
  [CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore).

### `VSS_SM_IO_THROTTLING_FLAG:0x00000008`

This enumeration value is reserved for future use.

### `VSS_SM_ALL_FLAGS:0xffffffff`

This enumeration value is reserved for future use.

Specifies that the writer expects to be notified for all events.

## Remarks

A bit mask (or bitwise OR) of **VSS_SUBSCRIBE_MASK**
values is used as an argument only to
[CVssWriter::Subscribe](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-subscribe).

Currently, the only supported **VSS_SUBSCRIBE_MASK**
bit mask is ( **VSS_SM_BACKUP_EVENTS_FLAG** |
**VSS_SM_RESTORE_EVENTS_FLAG**).

## See also

[CVssWriter::OnBackOffIOOnVolume](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackoffioonvolume)

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[CVssWriter::OnContinueIOOnVolume](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-oncontinueioonvolume)

[CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[CVssWriter::Subscribe](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-subscribe)