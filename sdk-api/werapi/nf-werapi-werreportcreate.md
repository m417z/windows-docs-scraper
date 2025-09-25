# WerReportCreate function

## Description

Creates a [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report that describes an application event.

## Parameters

### `pwzEventType` [in]

A pointer to a Unicode string that specifies the name of the event.

### `repType` [in]

The type of report. This parameter can be one of the following values from the **WER_REPORT_TYPE** enumeration type.

|Value|Meaning|
|--- |--- |
|**WerReportApplicationCrash**<br>2|An error that has caused the application to stop running has occurred.|
|**WerReportApplicationHang**<br>3|An error that has caused the application to stop responding has occurred.|
|**WerReportInvalid**<br>5|An error that has called out a return that is not valid has occurred.|
|**WerReportKernel**<br>4|An error in the kernel has occurred.|
|**WerReportCritical**<br>1|A critical error, such as a crash or non-response, has occurred. By default, processes that experience a critical error are terminated or restarted.|
|**WerReportNonCritical**<br>0|An error that is not critical has occurred. This type of report shows no UI; the report is silently queued. It may then be sent silently to the server in the background if adequate user consent is available.|

### `pReportInformation` [in, optional]

A pointer to a [WER_REPORT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_report_information) structure that specifies information for the report.

### `phReportHandle` [out]

A handle to the report. If the function fails, this handle is **NULL**.

## Return value

This function returns **S_OK** on success or an error code on failure.

## Remarks

Use the following functions to specify additional information to be submitted:

- [WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump)
- [WerReportAddFile](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportaddfile)
- [WerReportSetParameter](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportsetparameter)

To submit the information, call the [WerReportSubmit](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportsubmit) function. When you have finished with the report handle, call the [WerReportCloseHandle](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportclosehandle) function.

Applications can also indicate that they would like the opportunity to recover data or restart on failure. For more information, see [Application Recovery and Restart](https://learn.microsoft.com/windows/desktop/wsw/portal).

To view the reports submitted by your application, go to Windows Quality Online Services.

## See also

[Application Recovery and Restart](https://learn.microsoft.com/windows/desktop/wsw/portal), [WER_REPORT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/werapi/ns-werapi-wer_report_information), [WerReportCloseHandle](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportclosehandle), [WerReportSubmit](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportsubmit), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)