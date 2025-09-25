# CVssWriter::OnBackupShutdown

## Description

The
**OnBackupShutdown** method is called by a writer following a [BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) event. It is used to perform operations considered necessary when a backup application shuts down, particularly in the case of a crash of the backup application.

**OnBackupShutdown** is a virtual method. It is implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, but can be overridden by derived classes.

## Parameters

### `SnapshotSetId` [in]

Identifier for the shadow copy set involved in the backup operation.

## Return value

As implemented by the base class,
**OnBackupShutdown** always returns **true**

Any other implementation of this method should return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The default implementation of this method by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without performing any other operation.

If special operations are to be performed by the writer when a backup application shuts down, the default implementation can be overridden.

If no shadow copy has been successfully performed, the value of the shadow copy set identifier (*SnapshotSetId*) will be **NULL**.

A BackupShutdown event will be generated whenever a backup application actually terminates and its
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) is released.

The
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event requires the backup application to either successfully complete the backup or fail gracefully; this may not be the case if the backup application is terminated by the system or terminated manually prior to the completion of the backup (for instance, if the backup operation hung and had to be shut down).

Because of this, a BackupShutdown event is a more robust signal of the end of a backup application than the
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event.

A writer should maintain state information so that it can track whether a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event was sent for a given shadow copy set.

Any writer-specific implementation of
**OnBackupShutdown** should check whether a
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) event was handled. It should ensure that all necessary writer cleanup operations following a backup (successful or otherwise) are preformed.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[IVssBackupComponents::BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete)