# MAKEWPARAM macro

## Syntax

```cpp
WPARAM MAKEWPARAM(
    WORD l,
    WORD h
);
```

## Return value

Type: **WPARAM**

The return value is a **WPARAM** value.

## Description

Creates a value for use as a *wParam* parameter in a message. The macro concatenates the specified values.

## Parameters

### `l`

The low-order word of the new value.

### `h`

The high-order word of the new value.

## See also

**Conceptual**

[MAKELONG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632660(v=vs.85))

[MAKELPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makelparam)

[MAKELRESULT](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makelresult)

**Reference**

[Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)