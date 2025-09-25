# MAKELPARAM macro

## Syntax

```cpp
LPARAM MAKELPARAM(
    WORD l,
    WORD h
);
```

## Return value

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is an **LPARAM** value.

## Description

Creates a value for use as an
*lParam* parameter in a message. The macro concatenates the specified values.

## Parameters

### `l`

The low-order word of the new value.

### `h`

The high-order word of the new value.

## See also

**Conceptual**

[MAKELONG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632660(v=vs.85))

[MAKELRESULT](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makelresult)

[MAKEWPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makewparam)

**Reference**

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)