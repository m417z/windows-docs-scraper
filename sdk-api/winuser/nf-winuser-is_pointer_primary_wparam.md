# IS_POINTER_PRIMARY_WPARAM macro

## Syntax

```cpp
BOOL IS_POINTER_PRIMARYBUTTON_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the specified pointer is the primary pointer. Otherwise, **FALSE**.

## Description

Checks whether the specified pointer took primary action.

## Parameters

### `wParam`

The value to be converted.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)