# WerUnregisterMemoryBlock function

## Description

Removes a memory block from the list of data to be collected during [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) for the application.

## Parameters

### `pvAddress` [in]

The starting address of the memory block. This memory block must have been registered using the [WerRegisterMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregistermemoryblock) function.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**WER_E_NOT_FOUND**|The list of registered memory blocks does not contain the specified memory block.|

## See also

[WerRegisterMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregistermemoryblock), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)