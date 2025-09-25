# WerUnregisterExcludedMemoryBlock function

## Description

Removes a memory block that was previously marked as excluded, which will again be included in [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error reports.

## Parameters

### `address`

The starting address of the memory block. This memory block must have been registered using the [WerRegisterExcludedMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterexcludedmemoryblock) function.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|

## See also

[WerRegisterExcludedMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterexcludedmemoryblock), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)