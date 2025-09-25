# CVssWriter::SetWriterFailure

## Description

The
**SetWriterFailure** method indicates that this writer has encountered an error condition and sets an error condition.

**SetWriterFailure** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Parameters

### `hr` [in]

Error code to be set. The following are the error codes that this method can set.

| Value | Meaning |
| --- | --- |
| **VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT** | The shadow copy contains only a subset of the volumes needed to correctly back up an application component. |
| **VSS_E_WRITERERROR_NONRETRYABLE** | The writer failed due to an error that would likely occur if another shadow copy is created. |
| **VSS_E_WRITERERROR_OUTOFRESOURCES** | The writer failed due to a resource allocation error. |
| **VSS_E_WRITERERROR_RETRYABLE** | The writer failed due to an error that would likely not occur if the entire backup, restore, or shadow copy creation process was restarted. |
| **VSS_E_WRITERERROR_TIMEOUT** | The writer could not complete the shadow copy creation because the time between freeze and thaw states exceeded the time-out value (*dwTimeoutFreeze*) set in [CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize). |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method cannot be called from [CVssWriter::OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify) or [CVssWriterEx::OnIdentifyEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex-onidentifyex).

If a writer's event handler (such as [CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)) calls this method, it must do so in the same thread that called the event handler. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[IVssBackupComponents::GetWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatus)