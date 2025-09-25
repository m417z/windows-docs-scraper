# Button_GetNote macro

## Syntax

```cpp
BOOL Button_GetNote(
   HWND    hwnd,
   LPCWSTR psz,
   int     pcc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

## Description

Gets the text of the note associated with a command link button. You can use this macro or send the [BCM_GETNOTE](https://learn.microsoft.com/windows/desktop/Controls/bcm-getnote) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `psz`

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated, Unicode string that contains the note.

### `pcc`

Type: **int**

A pointer to the length of the note, in characters.

## Remarks

This macro works only with the [BS_COMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) and [BS_DEFCOMMANDLINK](https://learn.microsoft.com/windows/desktop/Controls/button-styles) button styles.

## See also

[Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles)

[Button Types](https://learn.microsoft.com/windows/desktop/Controls/button-types-and-styles)

**Conceptual**

**Reference**