# ComboBox_GetCueBannerText macro

## Syntax

```cpp
BOOL ComboBox_GetCueBannerText(
   HWND   hwnd,
   LPWSTR lpwText,
   int    cchText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or an error value otherwise.

## Description

Gets the cue banner text displayed in the edit control of a combo box. Use this macro or send the [CB_GETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/cb-getcuebanner) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the combo box.

### `lpwText`

Type: **[LPWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a Unicode string buffer that receives the cue banner text. The calling application is responsible for allocating the memory for the buffer. The buffer size must be equal to the length of the cue banner string in **WCHAR****s**, plus 1—for the terminating **NULL** **WCHAR**.

### `cchText`

Type: **int**

The size of the buffer pointed to by *lpwText* in **WCHAR****s**.

## See also

[Combo Box Features](https://learn.microsoft.com/windows/desktop/Controls/combo-box-features)