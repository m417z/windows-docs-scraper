# WerUnregisterAdditionalProcess function

## Description

Removes a process from the list of additional processes to be included in the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error report.

## Parameters

### `processId`

The Id of the process to remove. It must have been previously registered with [WerRegisterAdditionalProcess](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisteradditionalprocess).

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in [application recovery mode](https://learn.microsoft.com/windows/desktop/wsw/portal).|
|**WER_E_NOT_FOUND**|The list of registered processes does not contain the specified process.|

## See also

[WerRegisterAdditionalProcess](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisteradditionalprocess), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)