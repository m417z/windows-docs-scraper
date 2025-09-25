# POINTSTOPOINT macro

## Syntax

```cpp
void POINTSTOPOINT(
    POINT pt,
    POINTS pts
);
```

## Description

The **POINTSTOPOINT** macro copies the contents of a [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure into a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure.

## Parameters

### `pt`

The [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure to receive the contents of the [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure.

### `pts`

The [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure to copy.

## See also

[MAKEPOINTS](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-makepoints)

[POINTTOPOINTS](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-pointtopoints)

[Rectangle Macros](https://learn.microsoft.com/windows/desktop/gdi/rectangle-macros)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)