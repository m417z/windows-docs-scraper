# Edit_SetEndOfLine macro

## Syntax

```cpp
void Edit_SetEndOfLine(
    HWND hwndCtl,
    EC_ENDOFLINE eolType
);
```

## Description

Sets the end of line character used for the content of the edit control. You can use this macro or send the [EM_SETENDOFLINE](https://learn.microsoft.com/windows/desktop/controls/em-setendofline) message explicitly.

## Parameters

### `hwndCtl`

A handle to the edit control.

### `eolType`

The end of line character to use.