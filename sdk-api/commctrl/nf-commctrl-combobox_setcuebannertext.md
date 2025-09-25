# ComboBox_SetCueBannerText macro

## Syntax

```cpp
BOOL ComboBox_SetCueBannerText(
   HWND    hwnd,
   LPCWSTR lpcwText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or an error value otherwise.

## Description

Sets the cue banner text that is displayed for the edit control of a combo box.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the combo box.

### `lpcwText`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated Unicode string buffer that contains the text.

## Remarks

The cue banner is text that is displayed in the edit control of a combo box when there is no selection.

## See also

[Combo Box Features](https://learn.microsoft.com/windows/desktop/Controls/combo-box-features)