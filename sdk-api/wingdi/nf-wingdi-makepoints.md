# MAKEPOINTS macro

## Syntax

```cpp
POINTS MAKEPOINTS(
    DWORD l
);
```

## Return value

Type: **POINTS**

The return value is a pointer to a [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure.

## Description

The **MAKEPOINTS** macro converts a value that contains the x- and y-coordinates of a point into a [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structure.

## Parameters

### `l`

The coordinates of a point. The x-coordinate is in the low-order word, and the y-coordinate is in the high-order word.

## See also

[GetMessagePos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessagepos)

[Rectangle Macros](https://learn.microsoft.com/windows/desktop/gdi/rectangle-macros)

[Rectangles Overview](https://learn.microsoft.com/windows/desktop/gdi/rectangles)