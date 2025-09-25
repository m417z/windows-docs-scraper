# CVssWriter::OnFreeze

## Description

The
**OnFreeze** method is called by a writer on receipt of a [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) event at the start of a shadow copy freeze. A writer uses this method to perform operations needed to participate in the freeze or to veto the freeze.

**OnFreeze** is a pure virtual method. It is not implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, and must be implemented by derived classes.

## Return value

The implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

In this method, the writer application should put itself into a well-defined state that is compatible with the VSS operation.

In this method, the writer should complete final preparations to support the creation of a shadow copy. Once the shadow copy is created, the writer will receive the [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t) event and can continue normal operations.

By default, the time-out window between Freeze and Thaw events is 60 seconds. That is, if a Thaw event is not received with the time-out window, an Abort event will be generated. Writers can change the time-out window at initialization time by setting the *dwTimeoutFreeze* argument to
[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).

How a writer prepares for a shadow copy is highly dependent on the application that hosts it. Some applications can afford to hold all writes and keep the data in an absolute consistent state for this period. Other applications, like many databases, cannot stop work during this period but can take actions, such as checkpointing their state, which may reduce the recovery time for a shadow copy created during this window.

If the writer cannot put itself into a well-defined state for the Freeze, the following happens:

1. **OnFreeze** should return **false**, vetoing the shadow copy.
2. The writer calls
   [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) to provide a description of the failure.
3. An Abort event will be generated upon **OnFreeze** return of **false**

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

The time-out window for handling the Freeze event is typically relatively short as compared to that for handling the [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event. Therefore, developers should avoid lengthy operations in this method. A typical use might be to suspend logging by the writer.

It is recommended that all time-consuming operations be handled by
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot).

Either
[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw) or
[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort) will be called after this method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnAbort](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onabort)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)