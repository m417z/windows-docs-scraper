# CVssWriterEx2::SetWriterFailureEx

## Description

Sets extended error information to indicate that the writer has encountered a problem with participating in a VSS
operation.

## Parameters

### `hrWriter` [in]

The error code to be returned to the requester.

The following are the error codes that this method can set.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer was successful. |
| **VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT** | The shadow copy contains only a subset of the volumes needed by the writer to correctly back up the application component. |
| **VSS_E_WRITERERROR_OUTOFRESOURCES** | The writer ran out of memory or other system resources. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_TIMEOUT** | The writer operation failed because of a time-out between the Freeze and Thaw events. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_RETRYABLE** | The writer failed due to an error that would likely not occur if the entire backup, restore, or shadow copy creation process was restarted. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_NONRETRYABLE** | The writer operation failed because of an error that might recur if another shadow copy is created. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_WRITERERROR_PARTIAL_FAILURE** | The writer is reporting one or more component-level errors. To report the errors, the writer must use the [IVssComponentEx2::SetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-setfailure) method. |

### `hrApplication` [in]

An additional error code to be returned to the requester. This parameter is optional.

### `wszApplicationMessage` [in]

A string containing an error message for the requester to display to the end user. The writer is responsible for localizing this string if necessary before using it in this method. This parameter is optional and can be **NULL** or an empty string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method cannot be called from [CVssWriter::OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify) or [CVssWriterEx::OnIdentifyEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex-onidentifyex).

To report component-level errors, writers should use the [IVssComponentEx2::SetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-setfailure) method.

If a writer's event handler (such as [CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)) calls this method, it must do so in the same thread that called the event handler. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[CVssWriterEx2](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex2)

[IVssBackupComponentsEx3::GetWriterStatusEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex3-getwriterstatusex)