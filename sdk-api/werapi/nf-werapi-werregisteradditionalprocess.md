# WerRegisterAdditionalProcess function

## Description

Registers a process to be included in the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report along with the main application process. Optionally specifies a thread within that registered process to get additional data from.

## Parameters

### `processId`

The Id of the process to register.

### `captureExtraInfoForThreadId` [optional]

The Id of a thread within the registered process from which more information is requested.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**E_INVALIDARG**|The value of *processId* is 0.|
|**E_OUTOFMEMORY**|WER could not allocate a large enough heap for the data.|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|Number of WER registered entries (memory blocks, metadata, files) exceeds max (**WER_MAX_REGISTERED_ENTRIES**) or number of processes exceeds max (**WER_MAX_REGISTERED_DUMPCOLLECTION**)|
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|

## Remarks

This API is for applications that have multiple processes interacting with each other. An application's main process would register the Id of another process. When the registering process crashes, WER will add an additional triage dump of the registered process to the resulting diagnostics. Optionally, the registering process can provide a thread Id as well to get more data for that specific thread.

## See also

[WerUnregisterAdditionalProcess](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregisteradditionalprocess), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)