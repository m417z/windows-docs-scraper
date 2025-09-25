# Button_SetNote macro

## Syntax

```cpp
BOOL Button_SetNote(
   HWND   hwnd,
   PCWSTR psz
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets the text of the note associated with a specified command link button. You can use this macro or send the [BCM_SETNOTE](https://learn.microsoft.com/windows/desktop/Controls/bcm-setnote) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `psz`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated **WCHAR** string that contains the note.

## Remarks

Beginning with comctl32 DLL version 6.01, command link buttons may have a note.

This macro works only with the [BS_COMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFCOMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) button styles.

## See also

[Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles)

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

**Conceptual**

**Reference**