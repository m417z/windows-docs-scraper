# Edit_FmtLines macro

## Description

Sets a flag that determines whether text retrieved from a multiline edit control includes soft line-break characters. A soft line break consists of two carriage returns and a line feed and is inserted at the end of a line that is broken because of word wrapping. You can use this macro or send the [EM_FMTLINES](https://learn.microsoft.com/windows/desktop/Controls/em-fmtlines) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fAddEOL`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to insert line breaks; otherwise **FALSE**.

## Remarks

For more information, see [EM_FMTLINES](https://learn.microsoft.com/windows/desktop/Controls/em-fmtlines).