# Button_GetNoteLength macro

## Syntax

```cpp
LRESULT Button_GetNoteLength(
  [in] HWND hwnd
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the length of the note text in **WCHAR**s, not including any terminating **NULL**, or zero if there is no note text.

## Description

Gets the length of the note text that may be displayed in the description for a command link. Use this macro or send the [BCM_GETNOTELENGTH](https://learn.microsoft.com/windows/desktop/Controls/bcm-getnotelength) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

## Remarks

Beginning with comctl32 DLL version 6.01, command link buttons may have a note. For information on DLL versions, see [Common Control Versions](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions).

The **Button_GetNoteLength** macro works only with the [BS_COMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFCOMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) button styles.

## See also

[Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles)

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

**Conceptual**

**Reference**