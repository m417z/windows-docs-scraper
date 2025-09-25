# Edit_SetCueBannerTextFocused macro

## Syntax

```cpp
BOOL Edit_SetCueBannerTextFocused(
   HWND    hwnd,
   LPCWSTR lpcwText,
   BOOL    fDrawFocused
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

### `fDrawFocused`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Sets whether the cue text is drawn when the control has keyboard focus.

## Remarks

An edit control that is used to begin a search may display "Enter search here" in gray text as a textual cue. *fDrawFocused* controls when the cue text disappears. If *fDrawFocused* is **FALSE**, then the cue text disappears when the edit control receives focus. If *fDrawFocused* is **TRUE**, then the cue text disappears when the user enters text into the edit control.

## See also

**Conceptual**

[EM_SETCUEBANNER](https://learn.microsoft.com/windows/desktop/Controls/em-setcuebanner)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

[Edit_SetCueBannerText](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-edit_setcuebannertext)

**Reference**