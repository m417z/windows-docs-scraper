# CVssWriter::OnPreRestore

## Description

The
**OnPreRestore** method is called by a writer following a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event. This method is used to put the writer in a state to support the restore—for instance, taking database services offline—and to make modifications in the Backup Components Document of the requester that is restoring files (such as setting the restore target to override the original restore method).

**OnPreRestore** is a virtual method. It is implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, but can be overridden by derived classes.

## Parameters

### `pComponent` [in]

Pointer to an instantiation of an
[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents) object containing those components associated with the current writer in the requester's Backup Components Document.

## Return value

As implemented by the base class,
**OnPreRestore** always returns **true**.

Any other implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event occurs before backed-up data is actually being restored. This is an opportunity for the writer to determine what is being restored.

The default implementation of this method by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without performing any other operation.

This method enables the writer to determine what is being restored, to retrieve stored private metadata in the stored Backup Components Document, and to update that data.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)