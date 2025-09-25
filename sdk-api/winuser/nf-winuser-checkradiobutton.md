# CheckRadioButton function

## Description

Adds a check mark to (checks) a specified radio button in a group and removes a check mark from (clears) all other radio buttons in the group.

## Parameters

### `hDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the radio button.

### `nIDFirstButton` [in]

Type: **int**

The identifier of the first radio button in the group.

### `nIDLastButton` [in]

Type: **int**

The identifier of the last radio button in the group.

### `nIDCheckButton` [in]

Type: **int**

The identifier of the radio button to select.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CheckRadioButton** function sends a [BM_SETCHECK](https://learn.microsoft.com/windows/desktop/Controls/bm-setcheck) message to each of the radio buttons in the indicated group.

The *nIDFirstButton* and *nIDLastButton* parameters specify a range of button identifiers (normally the resource IDs of the buttons). The position of buttons in the tab order is irrelevant; if a button forms part of a group, but has an ID outside the specified range, it is not affected by this call.

## See also

[CheckDlgButton](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-checkdlgbutton)

[IsDlgButtonChecked](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isdlgbuttonchecked)

**Reference**