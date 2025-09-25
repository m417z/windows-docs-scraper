# GET_POINTERID_WPARAM macro

## Syntax

```cpp
BOOL GET_POINTERID_WPARAM(
    WPARAM wParam
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is the low-order **int** of the specified value.

## Description

Retrieves the pointer ID using the specified value.

## Parameters

### `wParam`

The value to be converted.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)