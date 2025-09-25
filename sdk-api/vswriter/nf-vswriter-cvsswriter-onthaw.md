# CVssWriter::OnThaw

## Description

The
**OnThaw** method is called by a writer following a [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t) event.

**OnThaw** is a pure virtual method. It is not implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, and must be implemented by derived classes.

## Return value

The implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

This method is called at the end of a shadow copy freeze when writers can begin to modify data on disk again.

**OnThaw** is used to return the writer to normal operation, typically reversing actions taken during
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot) and
[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze).

Final updates by the writer to the backup components metadata and cleanup (such as removing temporary files) are typically reserved for
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)