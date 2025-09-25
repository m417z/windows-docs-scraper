# Edit_ReplaceSel macro

## Syntax

```cpp
void Edit_ReplaceSel(
   HWND    hwndCtl,
   LPCTSTR lpszReplace
);
```

## Description

Replaces the selected text in an edit control or a rich edit control with the specified text. You can use this macro or send the [EM_REPLACESEL](https://learn.microsoft.com/windows/desktop/Controls/em-replacesel) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `lpszReplace`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string containing the replacement text.

## Remarks

For more information, see [EM_REPLACESEL](https://learn.microsoft.com/windows/desktop/Controls/em-replacesel).