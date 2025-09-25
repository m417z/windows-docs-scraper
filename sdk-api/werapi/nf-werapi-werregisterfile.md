# WerRegisterFile function

## Description

Registers a file to be collected when [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) creates an error report.

## Parameters

### `pwzFile` [in]

The full path to the file. The maximum length of this path is MAX_PATH characters.

### `regFileType` [in]

The file type. This parameter can be one of the following values from the **WER_REGISTER_FILE_TYPE** enumeration type.

|Value|Meaning|
|--- |--- |
|**WerRegFileTypeMax**
3|The maximum value for the **WER_REGISTER_FILE_TYPE** enumeration type.|
|**WerRegFileTypeOther**
2|Any other type of file.|
|**WerRegFileTypeUserDocument**
1|The document in use by the application at the time of the event. This document is only collected if the Watson server asks for it.|

### `dwFlags` [in]

This parameter can be one or more of the following values.

|Value|Meaning|
|--- |--- |
|**WER_FILE_ANONYMOUS_DATA**|The file does not contain personal information that could be used to identify or contact the user.|
|**WER_FILE_DELETE_WHEN_DONE**|Automatically deletes the file after it is added to the report.|

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|The number of registered memory blocks and files exceeds the limit.|

## Remarks

The registered file is added to the report only when additional data is requested by the server.

For crashes and non-responses, the operating system automatically provides error reporting (you do not need to provide any error reporting code in your application). If you use this function to register a file, the operating system will add the file to the error report created at the time of a crash or non-response (this file is added in addition to the files the operating system already collects).

For generic event reporting, the application has to use the [WerReportAddFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportaddfile) function instead. Alternatively, calling the [WerReportSubmit](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportsubmit) function with the WER_SUBMIT_ADD_REGISTERED_DATA flag will include the files that the **WerRegisterFile** function added.

To remove the file from the list, call the [WerUnregisterFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregisterfile) function.

## See also

[WerUnregisterFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregisterfile), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)