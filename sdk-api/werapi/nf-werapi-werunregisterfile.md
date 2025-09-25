# WerUnregisterFile function

## Description

Removes a file from the list of files to be added to [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) reports generated for the current process.

## Parameters

### `pwzFilePath` [in]

The full path to the file. This file must have been registered using the [WerRegisterFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterfile) function.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**WER_E_NOT_FOUND**|The list of registered files does not contain the specified file.|

## See also

[WerRegisterFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterfile), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)