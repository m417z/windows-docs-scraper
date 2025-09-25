# COMBOBOXINFO structure

## Description

Contains combo box status information.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the structure. The calling application must set this to sizeof(COMBOBOXINFO).

### `rcItem`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the coordinates of the edit box.

### `rcButton`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the coordinates of the button that contains the drop-down arrow.

### `stateButton`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The combo box button state. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The button exists and is not pressed. |
| **STATE_SYSTEM_INVISIBLE** | There is no button. |
| **STATE_SYSTEM_PRESSED** | The button is pressed. |

### `hwndCombo`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the combo box.

### `hwndItem`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit box.

### `hwndList`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the drop-down list.

## Remarks

The following example code retrieves information about the combo box specified by the window handle.

```
COMBOBOXINFO info = { sizeof(COMBOBOXINFO) };
GetComboBoxInfo(hwnd, &info);

```

## See also

[GetComboBoxInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcomboboxinfo)