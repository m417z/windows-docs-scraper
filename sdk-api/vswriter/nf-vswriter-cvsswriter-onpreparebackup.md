# CVssWriter::OnPrepareBackup

## Description

The
**OnPrepareBackup** method is called by a writer following a
[PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup) event. This method is used to configure a writer's state and its components in preparation for a backup operation.

**OnPrepareBackup** is a virtual method. It is implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, but can be overridden by derived classes.

## Parameters

### `pComponent` [in]

Pointer to an instantiation of an
[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents) object containing the contents of the Writer Metadata Document. The value of this parameter may be **NULL** if the requester does not support components (if
[CVssWriter::AreComponentsSelected](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-arecomponentsselected) returns **false**).

## Return value

As implemented by the base class,
**OnPrepareBackup** always returns **true**.

Any other implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The default implementation of this method by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without performing any other operation.

**OnPrepareBackup** provides a writer an opportunity to more finely select what will be backed up.

Handling the [PrepareForBackup](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event is the last opportunity for a writer to get access to metadata contained in the Backup Components Document prior to the shadow copy's creation.

Therefore,
**OnPrepareBackup** provides an opportunity for the writer to make any final additions or updates to stored component information (using the
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) interface). In particular, writer-specific metadata can be updated by
[IVssComponent::SetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupmetadata) or
[IVssComponent::SetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoremetadata).

In addition, while handling the [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event provides another opportunity in the life cycle of a VSS backup operation to perform time-consuming operations (such as synchronizing data across multiple sites),
**OnPrepareBackup** provides a chance for the writer to start such an operation asynchronously. Tasks like these must be completed prior to the return of
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot).

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

A requester generates a
[PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup) event, triggering a call to
**OnPrepareBackup**, by calling
**IVssBackupComponents::PrepareForBackup**.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)