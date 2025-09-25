# WER_REPORT_INFORMATION structure

## Description

Contains [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) information used by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

## Members

### `dwSize`

The size of this structure, in bytes.

### `hProcess`

A handle to the process for which the report is being generated. If this member is **NULL**, this is the calling process.

### `wzConsentKey`

The name used to look up consent settings. If this member is empty, the default is the name specified by the *pwzEventType* parameter of [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate).

### `wzFriendlyEventName`

The display name. If this member is empty, the default is the name specified by *pwzEventType* parameter of [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate).

### `wzApplicationName`

The name of the application. If this parameter is empty, the default is the base name of the image file.

### `wzApplicationPath`

The full path to the application.

### `wzDescription`

A description of the problem. This description is displayed in **Problem Reports and Solutions** on Windows Vista or the problem reports pane of the **Action Center** on Windows 7.

### `hwndParent`

A handle to the parent window.

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/)