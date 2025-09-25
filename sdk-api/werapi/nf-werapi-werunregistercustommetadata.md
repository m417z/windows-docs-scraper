# WerUnregisterCustomMetadata function

## Description

Removes an item of app-specific metadata being collected during [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) for the application.

## Parameters

### `key`

The "key" string for the metadata element being removed. It must have been previously registered with the [WerRegisterCustomMetadata](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregistercustommetadata) function.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**WER_E_NOT_FOUND**|WER could not find the metadata item to remove.|

## See also

[WerRegisterCustomMetadata](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregistercustommetadata), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)