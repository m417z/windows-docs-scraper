# WerRegisterExcludedMemoryBlock function

## Description

Marks a memory block (that is normally included by default in error reports) to be excluded from the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error report.

## Parameters

### `address`

The starting address of the memory block.

### `size`

The size of the memory block, in bytes.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**E_INVALIDARG**|*address* is **NULL** or *size* is 0.|
|**E_OUTOFMEMORY**|WER could not allocate a large enough heap for the data|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|The number of registered entries exceeds the limit (**WER_MAX_REGISTERED_ENTRIES**).|
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|

## Remarks

This mechanism is intended for applications that hold large amounts of data in memory that aren't useful for root cause debugging and increase the size of the dump file unnecessarily. For example, some games hold large amounts of texture data in memory that is included in error dumps by default.

## See also

[WerUnregisterExcludedMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregisterexcludedmemoryblock), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)