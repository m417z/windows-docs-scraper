# CVssWriter::OnPrepareSnapshot

## Description

The
**OnPrepareSnapshot** method is called by a writer to handle a [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event. It is used to perform operations needed to prepare a writer to participate in the shadow copy or to veto a shadow copy.

**OnPrepareSnapshot** is a pure virtual method. It is not implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, and must be implemented by derived classes.

## Return value

The implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The
**OnPrepareSnapshot** method performs operations that are required prior to any shadow copy freeze.

The time-out window for handling a [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event is typically longer than that for handling a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event. Therefore, developers can use
**OnPrepareSnapshot** to handle more time-consuming operations. A typical use might be for the writer to explicitly checkpoint its data.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)