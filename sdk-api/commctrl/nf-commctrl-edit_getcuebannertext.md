# Edit_GetCueBannerText macro

## Syntax

```cpp
BOOL Edit_GetCueBannerText(
   HWND    hwnd,
   LPCWSTR lpwText,
   LONG    cchText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Gets the text that is displayed as a textual cue, or tip, in an edit control. You can use this macro or send the [EM_GETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/em-getcuebanner) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

### `lpwText`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a Unicode string that receives the text that is set as the cue banner.

### `cchText`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **LONG** that specifies the number of **WCHAR**s in the string referenced by *lpwText*.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

**Conceptual**

[EM_GETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/em-getcuebanner)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

**Reference**