# WER_REPORT_INFORMATION_V3 function

## Description

Contains [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) information used by the [WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate) function.

## Members

### `dwSize`

The size of this structure, in bytes.

### `hProcess`

A handle to the process for which the report is being generated. If this member is **NULL**, this is the calling process.

### `wzConsentKey[64]`

### `wzFriendlyEventName[128]`

### `wzApplicationName[128]`

### `wzApplicationPath[MAX_PATH]`

### `wzDescription[512]`

### `hwndParent`

A handle to the parent window.

### `wzNamespacePartner[64]`

### `wzNamespaceGroup[64]`

## Remarks

## See also

[WerReportCreate](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportcreate), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/)