# CVssWriter::GetCurrentSnapshotSetId

## Description

The
**GetCurrentSnapshotSetId** method returns the unique identifier of the shadow copy set.

**GetCurrentSnapshotSetId** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns the
[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) value of the current shadow copy set.

The shadow copy set ID returned by **GetCurrentSnapshotSetId** is the shadow copy set ID of the backup operation a writer is currently participating in.

Note that a writer could be involved in more than one backup operation at a given time. Therefore, if this method is not called as part of a backup sequence—that is, not called from an event handler—which shadow copy set ID is returned is unpredictable.

If **GetCurrentSnapshotSetId** is called as part of a backup sequence—for example, from within
[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze), [CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw), or [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)—the VSS infrastructure guarantees that the [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) value returned is that of the shadow copy supporting the current backup operation.

However, this cannot be said for calls to **GetCurrentSnapshotSetId** from within the
[BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) event handler
[CVssWriter::OnBackupShutdown](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupshutdown). If a *BackupShutdown* event is called because of an abrupt shutdown of a requester, the [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) returned could be that of another backup operation the writer was participating in.

**GetCurrentSnapshotSetId** cannot be called after [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) returns.

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)

[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)