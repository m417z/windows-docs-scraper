# CVssWriter::GetContext

## Description

The
**GetContext** information returns the current context for any ongoing or possible shadow copies.

**GetContext** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns the context for any shadow copies involving the writer as a bit mask (or bitwise OR) of
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) and
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) values.

## Remarks

The default context for a shadow copy is VSS_CTX_BACKUP.

A requester can set the context for a shadow copy by calling
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext) at any time prior to creating a shadow copy with
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset).

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) generates a number of events ([PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p), [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f), [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t), [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p)), the first of which is *PrepareForSnapshot*.

Therefore, if a writer is participating in a shadow copy operation, a definitive value of that shadow copy's context cannot be found when
**GetContext** is called prior to
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)

[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)