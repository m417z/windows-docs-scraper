# NEXTRAWINPUTBLOCK macro

## Syntax

```cpp
PRAWINPUT NEXTRAWINPUTBLOCK(
    PRAWINPUT ptr
);
```

## Return value

Type: **PRAWINPUT**

The return value is a pointer to the next structure in the array of [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structures.

## Description

Retrieves the location of the next structure in an array of [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structures.

## Parameters

### `ptr`

A pointer to a structure in an array of [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structures.

## Remarks

This macro is called repeatedly to traverse an array of [RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput) structures.

## See also

**Conceptual**

[RAWINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-rawinput)

[Raw Input](https://learn.microsoft.com/windows/desktop/inputdev/raw-input)

**Reference**