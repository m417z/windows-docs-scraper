# IVssBackupComponentsEx3::GetWriterStatusEx

## Description

Returns extended status information for the specified writer.

## Parameters

### `iWriter` [in]

The index of the writer whose metadata is to be retrieved. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of
writers on the current system. The value of *n* is returned by
the [IVssBackupComponents::GetWriterStatusCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatuscount) method.

### `pidInstance` [out]

The address of a caller-allocated variable that receives the instance identifier of the writer. This parameter is required and cannot be **NULL**.

### `pidWriter` [out]

The address of a caller-allocated variable that receives the identifier for the writer class. This parameter is required and cannot be **NULL**.

### `pbstrWriter` [out]

The address of a caller-allocated variable that receives a string containing the name of the specified writer. This parameter is required and cannot be **NULL**.

### `pnStatus` [out]

The address of a caller-allocated variable that receives a [VSS_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_writer_state) enumeration value. This parameter is required and cannot be **NULL**.

### `phrFailureWriter` [out]

The address of a caller-allocated variable that receives the HRESULT failure code that the writer returned for the *hrWriter* parameter of the [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method.

The following are the supported values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer was successful. |
| **VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT** | The shadow copy contains only a subset of the volumes needed by the writer to correctly back up the application component. |
| **VSS_E_WRITERERROR_OUTOFRESOURCES** | The writer ran out of memory or other system resources. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_TIMEOUT** | The writer operation failed because of a time-out between the Freeze and Thaw events. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_RETRYABLE** | The writer failed due to an error that would likely not occur if the entire backup, restore, or shadow copy creation process was restarted. The recommended way to handle this error code is to wait ten minutes and then repeat the operation, up to three times. |
| **VSS_E_WRITERERROR_NONRETRYABLE** | The writer operation failed because of an error that might recur if another shadow copy is created. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_WRITER_NOT_RESPONDING** | The writer is not responding. |
| **VSS_E_WRITER_STATUS_NOT_AVAILABLE** | The writer status is not available for one or more writers. A writer may have reached the maximum number of available backup and restore sessions. |
| **VSS_E_WRITERERROR_PARTIAL_FAILURE** | The writer is reporting one or more component-level errors. To retrieve the errors, the requester must use the [IVssComponentEx2::GetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-getfailure) method. |

### `phrApplication` [out, optional]

The address of a caller-allocated variable that receives the return code that the writer passed for the *hrApplication* parameter of the [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method. This parameter is optional and can be **NULL**.

### `pbstrApplicationMessage` [out, optional]

The address of a variable that receives the application failure message that the writer passed for the *wszApplicationMessage* parameter of the [SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method. This parameter is optional and can be **NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | Successfully returned the status of the specified writer. Note that the value of the *phrFailureWriter* parameter must be checked to verify that the writer was successful. The writer failure codes can be among those listed in VsWriter.h and in [Writer Errors and Vetoes](https://learn.microsoft.com/windows/desktop/VSS/writer-errors-and-vetoes). |
| **E_INVALIDARG**<br><br>0x80070057L | The *pnStatus*, *pidWriter*, *pbstrWriter*, or *pidInstance* parameter is **NULL**. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE**<br><br>0x80042301L | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *iWriter* parameter specifies a writer that does not exist. |

## Remarks

A requester must call the asynchronous operation
[IVssBackupComponents::GatherWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwriterstatus)
and wait for it to complete before calling
**IVssBackupComponentsEx3::GetWriterStatusEx**.

If this method returns VSS_E_WRITERERROR_PARTIAL_FAILURE, the requester should use the [IVssComponentEx2::GetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-getfailure) method to retrieve the component-level errors.

When the caller has finished accessing the status information returned by this method, it should call
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory held by the
*pbstrWriter* and *pbstrApplicationMessage* parameters.

## See also

[CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex)

[IVssBackupComponents::GetWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatus)

[IVssBackupComponentsEx3](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex3)