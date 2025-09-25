# Edit_SetCueBannerText macro

## Syntax

```cpp
BOOL Edit_SetCueBannerText(
   HWND    hwnd,
   LPCWSTR lpcwText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Sets the text that is displayed as the textual cue, or tip, for an edit control. You can use this macro or send the [EM_SETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/em-setcuebanner) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

### `lpcwText`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a Unicode string that contains the text to set as the textual cue.

## Remarks

An edit control that is used to begin a search may display "Enter search here" in gray text as a textual cue. When the user clicks the text, the text goes away and the user can type.

You cannot set a cue banner on a multiline edit control.

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

**Conceptual**

[EM_SETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/em-setcuebanner)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

**Reference**