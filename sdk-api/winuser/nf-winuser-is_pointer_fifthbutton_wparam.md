# IS_POINTER_FIFTHBUTTON_WPARAM macro

## Syntax

```cpp
BOOL IS_POINTER_SECONDBUTTON_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the specified pointer took fifth action. Otherwise, **FALSE**.

## Description

Checks whether the specified pointer took fifth action.

## Parameters

### `wParam`

The value to be converted.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)