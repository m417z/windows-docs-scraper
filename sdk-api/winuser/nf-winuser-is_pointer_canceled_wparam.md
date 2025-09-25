# IS_POINTER_CANCELED_WPARAM macro

## Syntax

```cpp
BOOL IS_POINTER_CANCELED_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the specified pointer has been canceled. Otherwise, **FALSE**.

## Description

Checks whether the specified pointer input ended abruptly, or was invalid, indicating the interaction was not completed.

## Parameters

### `wParam`

The value to be converted.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)