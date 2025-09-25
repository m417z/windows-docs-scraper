# WerReportSetUIOption function

## Description

Sets the user interface options for the specified [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report.

## Parameters

### `hReportHandle` [in]

A handle to the report. This handle is returned by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

### `repUITypeID` [in]

The user interface element to be customized. This parameter can be one of the following values from the **WER_REPORT_UI** enumeration type.

|Value|Meaning|
|--- |--- |
|**WerUIAdditionalDataDlgHeader**|The instructions for the additional data dialog box.|
|**WerUICloseDlgBody**|The contents of the close dialog box.|
|**WerUICloseDlgButtonText**|The text for the button in the close dialog box.|
|**WerUICloseDlgHeader**|The main instructions for the close dialog box.|
|**WerUICloseText**|The text for the link to just terminate the application.|
|**WerUIConsentDlgBody**|The contents of the consent dialog box.|
|**WerUIConsentDlgHeader**|The main instructions for the consent dialog box.|
|**WerUIIconFilePath**|The icon to be displayed in the consent dialog box.|
|**WerUIOfflineSolutionCheckText**|The text for the link to check for a solution when offline.|
|**WerUIOnlineSolutionCheckText**|The text for the link to check for a solution when online.|

### `pwzValue` [in]

A pointer to a Unicode string that specifies the custom text. For more information, see the description of *repUITypeID*.

## Return value

This function returns **S_OK** on success or an error code on failure.

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)