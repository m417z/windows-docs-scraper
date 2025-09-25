# GetComboBoxInfo function

## Description

Retrieves information about the specified combo box.

## Parameters

### `hwndCombo` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the combo box.

### `pcbi` [out]

Type: **PCOMBOBOXINFO**

A pointer to a [COMBOBOXINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-comboboxinfo) structure that receives the information. You must set **COMBOBOXINFO.cbSize** before calling this function.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [CB_GETCOMBOBOXINFO](https://learn.microsoft.com/windows/desktop/Controls/cb-getcomboboxinfo) message is equivalent to this function.

#### Examples

The following example code retrieves information about the combo box specified by the window handle.

```cpp
COMBOBOXINFO info = { sizeof(COMBOBOXINFO) };
GetComboBoxInfo(hwnd, &info);

```

## See also

[CB_GETCOMBOBOXINFO](https://learn.microsoft.com/windows/desktop/Controls/cb-getcomboboxinfo)

[COMBOBOXINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-comboboxinfo)

[GetListBoxInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getlistboxinfo)

**Reference**