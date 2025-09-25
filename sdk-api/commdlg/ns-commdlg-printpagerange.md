# PRINTPAGERANGE structure

## Description

Represents a range of pages in a print job. A print job can have more than one page range. This information is supplied in the [PRINTDLGEX](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlgexa) structure when calling the [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) function.

## Members

### `nFromPage`

Type: **DWORD**

The first page of the range.

### `nToPage`

Type: **DWORD**

The last page of the range.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)