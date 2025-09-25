# HAS_POINTER_CONFIDENCE_WPARAM macro

## Syntax

```cpp
BOOL HAS_POINTER_CONFIDENCE_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

TRUE if the specified pointer is the primary action. Otherwise, FALSE.

## Description

Checks whether the specified pointer message is considered intentional rather than accidental.

## Parameters

### `wParam`

The value to be converted.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)