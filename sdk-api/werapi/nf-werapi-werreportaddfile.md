# WerReportAddFile function

## Description

Adds a file to the specified [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report.

## Parameters

### `hReportHandle` [in]

A handle to the report. This handle is returned by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

### `pwzPath` [in]

A pointer to a Unicode string that contains the full path to the file to be added. This path can use environment variables. The maximum length of this path is MAX_PATH characters.

### `repFileType` [in]

The type of file. This parameter can be one of the following values from the **WER_FILE_TYPE** enumeration type.

|Value|Meaning|
|--- |--- |
|**WerFileTypeHeapdump**|An extended minidump that contains additional data such as the process memory.|
|**WerFileTypeMicrodump**|A limited minidump that contains only a stack trace.|
|**WerFileTypeMinidump**|A minidump file.|
|**WerFileTypeOther**|Any other type of file. This file will always get added to the cab (but only if the server asks for a cab).|
|**WerFileTypeUserDocument**|The document in use by the application at the time of the event. The document is added only if the server is asks for this type of document.|

### `dwFileFlags` [in]

This parameter can be one or more of the following values.

|Value|Meaning|
|--- |--- |
|**WER_FILE_ANONYMOUS_DATA**|The file does not contain personal information that could be used to identify or contact the user.|
|**WER_FILE_DELETE_WHEN_DONE**|Automatically delete the file after the report is submitted.|

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**|The specified file does not exist.|
|**HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)**|The specified file is a user-document and is stored on an encrypted file-system; this combination is not supported.|

## Remarks

Although this function can also be used to add memory dumps (using specific flags) to the error report, the preferred function to use for adding memory dumps is [WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump). You should use this function only if you want to collect the dump yourself and then add it to the report.

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)