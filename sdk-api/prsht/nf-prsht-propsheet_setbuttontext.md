# PropSheet_SetButtonText macro

## Syntax

```cpp
VOID PropSheet_SetButtonText(
   HWND    hDlg,
   DWORD   dwButton,
   LPCTSTR lpszText
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Sets the text of a button in an Aero wizard. You can use this macro or send the [PSM_SETBUTTONTEXT](https://learn.microsoft.com/windows/desktop/Controls/psm-setbuttontext) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard.

### `dwButton`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following values specifying the button whose text is set.

| Value | Meaning |
| --- | --- |
| **PSWIZB_BACK** | 0x0001. The **Back** button. |
| **PSWIZB_NEXT** | 0x0002. The **Next** button. |
| **PSWIZB_FINISH** | 0x0004. The **Finish** button. |
| **PSWIZB_CANCEL** | 0x0010. The **Cancel** button. |

### `lpszText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The text to set.