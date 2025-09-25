# IProgressDialog::SetLine

## Description

Displays a message in the progress dialog.

## Parameters

### `dwLineNum`

Type: **DWORD**

The line number on which the text is to be displayed. Currently there are three lines—1, 2, and 3. If the **PROGDLG_AUTOTIME** flag was included in the *dwFlags* parameter when [IProgressDialog::StartProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-startprogressdialog) was called, only lines 1 and 2 can be used. The estimated time will be displayed on line 3.

### `pwzString` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the text.

### `fCompactPath`

Type: **BOOL**

**TRUE** to have path strings compacted if they are too large to fit on a line. The paths are compacted with [PathCompactPath](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcompactpatha).

### `pvResevered`

Type: **LPCVOID**

Reserved. Set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is typically used to display a message such as "Item XXX is now being processed." typically, messages are displayed on lines 1 and 2, with line 3 reserved for the estimated time.

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)