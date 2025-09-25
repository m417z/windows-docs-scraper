# IVssComponentEx2::GetFailure

## Description

VSS requesters call this method to retrieve component-level errors reported by writers.

## Parameters

### `phr` [out]

The address of a caller-allocated variable that receives the HRESULT failure code that the writer passed for the *hr* parameter of the [IVssComponentEx2::SetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-setfailure) method. This parameter is required and cannot be **NULL**.

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

### `phrApplication` [out]

The address of a caller-allocated variable that receives the return code that the writer passed for the *hrApplication* parameter of the [SetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-setfailure) method. This parameter is required and cannot be **NULL**.

### `pbstrApplicationMessage` [out]

The address of a caller-allocated variable that receives the application failure message that the writer passed for the *wszApplicationMessage* parameter of the [SetFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex2-setfailure) method. This parameter is required and cannot be **NULL**.

### `pdwReserved` [out]

The address of a caller-allocated DWORD variable. This parameter is reserved for future use, but it is required and cannot be **NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | Successfully returned the status of the specified writer. Note that the value of the *phrFailureWriter* parameter must be checked to verify that the writer was successful. The writer failure codes can be among those listed in VsWriter.h and in [Writer Errors and Vetoes](https://learn.microsoft.com/windows/desktop/VSS/writer-errors-and-vetoes). |
| **E_INVALIDARG**<br><br>0x80070057L | The *phr*, *phrApplication*, *pbstrApplicationMessage*, or *pdwReserved* parameter is **NULL**. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE**<br><br>0x80042301L | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |

## Remarks

When the caller has finished accessing the status information returned by this method, it should call
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory held by the *pbstrApplicationMessage* parameter.

## See also

[IVssComponentEx2](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex2)