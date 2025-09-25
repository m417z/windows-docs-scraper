# CVssWriter::OnPostRestore

## Description

The
**OnPostRestore** method is called by a writer following a
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event. It is used to perform operations considered necessary after files are restored to disk by a requester. These operations cannot, however, modify the Backup Components Document.

**OnPostRestore** is a virtual method. It is implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, but can be overridden by derived classes.

## Parameters

### `pComponent` [in]

A pointer to an
[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents) object passed in by VSS to provide the method with access to the writer's component information. The value of this parameter may be **NULL** if the requester does not support components (if
[CVssWriter::AreComponentsSelected](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-arecomponentsselected) returns **false**).

## Return value

As implemented by the base class,
**OnPostRestore** always returns **true**.

Any other implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The default implementation of this method by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without performing any other operation.

If necessary, a writer should remove any temporary files and release any system resources that it needed for its participation in the restore.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

With the generation of a
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event, a requester's Backup Components Document becomes a read-only document. Therefore, attempts to modify the document through the interface (for instance, calling
[IVssComponent::SetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoremetadata)) will fail in user implementations of
**OnPostRestore**.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)