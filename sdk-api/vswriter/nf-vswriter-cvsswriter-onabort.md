# CVssWriter::OnAbort

## Description

The
**OnAbort** method is called by a writer following an [Abort](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a) event issued by VSS indicating that a shadow copy operation has terminated prematurely. The writer uses this method to clean up from its attempt to participate in that operation.

**OnAbort** is a pure virtual method. It is not implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class, and must be implemented by derived classes.

## Return value

The implementation of this method should return **true** except in the case of a fatal error. If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

In this method, the writer should free all temporary system resources it created when preparing to participate with a VSS operation.

The writer will not receive further event notifications related to the VSS operation it was participating in after
**CVssWriter::OnAbort** has been executed.

This method will not be called if the writer has called
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) (that is, received notification of the end of a shadow copy).

An Abort event is generated when:

* A writer's [Freeze](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-f) and [Thaw](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-t) event handlers ([CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze) and
  [CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)) return **false**, or cannot complete in the time window specified in
  [CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).
* A requester explicitly generates an Abort event by calling
  [IVssBackupComponents::AbortBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-abortbackup).
* There is any failure of the provider or VSS during the creation of a shadow copy following the [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)