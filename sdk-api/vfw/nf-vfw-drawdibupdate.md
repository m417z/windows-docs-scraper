# DrawDibUpdate macro

## Syntax

```cpp
BOOL DrawDibUpdate(
    HDRAWDIB hdd,
    HDC hdc,
    int x,
    int y
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **DrawDibUpdate** macro draws the last frame in the DrawDib off-screen buffer.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `hdc`

Handle of the DC.

### `x`

The x-coordinate, in MM_TEXT client coordinates, of the upper left corner of the destination rectangle.

### `y`

The y-coordinate, in MM_TEXT client coordinates, of the upper left corner of the destination rectangle.

## Remarks

The **DrawDibUpdate** macro is defined as follows:

```cpp

#define DrawDibUpdate( hdd, hdc, x, y) \
    DrawDibDraw( hdd, hdc, x, y, 0, 0, NULL, NULL, 0, 0, \
    0, 0, DDF_UPDATE)

```

This macro can be used to refresh an image or a portion of an image displayed by your application.

## See also

[DrawDib Macros](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-macros)