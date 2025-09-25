# IS_POINTER_FLAG_SET_WPARAM macro

## Syntax

```cpp
BOOL IS_POINTER_FLAG_SET_WPARAM(
    WPARAM wParam,
    UINT32 flag
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the specified pointer sets the specified flag. Otherwise, **FALSE**.

## Description

Checks whether a pointer macro sets the specified flag.

## Parameters

### `wParam`

The value to be converted.

### `flag`

The flag to be set. The value is one of the [Pointer_Flags](https://learn.microsoft.com/windows/win32/inputmsg/pointer-flags-contants) constants.

## See also

[Macros](https://learn.microsoft.com/windows/win32/inputmsg/macros)