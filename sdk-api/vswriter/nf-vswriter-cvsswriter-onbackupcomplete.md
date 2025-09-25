# CVssWriter::OnBackupComplete

## Description

The **OnBackupComplete** method is called by a
writer following a [BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event.
It is used to perform operations considered necessary following a backup. These operations cannot, however, modify
the Backup Components Document.

**OnBackupComplete** is a virtual method. It is
implemented by the [CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, but can be overridden
by derived classes.

## Parameters

### `pComponent` [in]

A pointer to an [IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents) object
passed in by VSS to provide the method with access to the writer's component information. The value of this
parameter may be **NULL** if the requester does not support components (if
[CVssWriter::AreComponentsSelected](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-arecomponentsselected) returns
**false**).

## Return value

As implemented by the base class,
**OnBackupComplete** always returns **true**.

Any other implementation of this method should return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The default implementation of this method by
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without
performing any other operation.

If special operations are to be performed by the writer at the end of a backup,
the default implementation can be overridden.

With the generation of a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event, a
requester's Backup Components Document becomes a read-only document. Therefore, attempts to modify the
document through the interface (for instance, calling
[IVssComponent::SetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupmetadata)) will
fail in user implementations of
**OnBackupComplete**.

A successful backup application will generate a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event when all data
has been saved to backup media.

However, there is no guarantee of the writer receiving a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event notification,
because these require the backup application to either successfully complete the backup or fail gracefully.

A [BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event could fail to
be generated should the backup application be terminated by the system or manually prior to the completion of the
backup (for instance, if the backup operation hung and had to be shut down).

A writer should maintain state information so that it can track whether a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event was sent for a
given shadow copy set.

This information can be used by a writer's
[BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) event handler
([CVssWriter::OnBackupShutdown](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupshutdown)),
which will be called when a backup application actually terminates and its
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) is released, to perform
cleanup operations should there be no call to
**OnBackupComplete**.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)