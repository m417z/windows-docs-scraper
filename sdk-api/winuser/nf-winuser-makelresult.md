# MAKELRESULT macro

## Syntax

```cpp
LRESULT MAKELRESULT(
    WORD l,
    WORD h
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is an **LRESULT** value.

## Description

Creates a value for use as a return value from a window procedure. The macro concatenates the specified values.

## Parameters

### `l`

The low-order word of the new value.

### `h`

The high-order word of the new value.

## See also

**Conceptual**

[MAKELONG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632660(v=vs.85))

[MAKELPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makelparam)

[MAKEWPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makewparam)

**Reference**

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)