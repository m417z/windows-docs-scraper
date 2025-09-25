# WerRegisterMemoryBlock function

## Description

Registers a memory block to be collected when [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) creates an error report.

## Parameters

### `pvAddress` [in]

The starting address of the memory block.

### `dwSize` [in]

The size of the memory block, in bytes. The maximum value for this parameter is WER_MAX_MEM_BLOCK_SIZE bytes.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|The number of registered memory blocks and files exceeds the limit.|

## Remarks

Memory registered with this function is only added to heap or larger dump files. This memory is never added to mini dumps or smaller dump files.

For crashes and no response, the operating system automatically provides error reporting (you do not need to provide any error reporting code in your application). If you use this function to register a memory block, the operating system will add the memory block information to the dump file at the time of the crash or non-response. The memory block is added to the dump file for the report only when additional data is requested by the server.

For generic event reporting, the application has to call the WER generic event reporting functions directly. To add the memory block to a generic report, call the [WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump) function and then call the [WerReportSubmit](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportsubmit) function and specify the WER_SUBMIT_ADD_REGISTERED_DATA flag.

To remove the block from this list, call the [WerUnregisterMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregistermemoryblock) function.

## See also

[WerUnregisterMemoryBlock](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregistermemoryblock), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)