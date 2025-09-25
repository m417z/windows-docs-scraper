# CURSORSHAPE structure

## Description

Contains information about a cursor.

## Members

### `xHotSpot`

Type: **int**

The horizontal position of the hot spot, relative to the upper-left corner of the cursor bitmap.

### `yHotSpot`

Type: **int**

The vertical position of the hot spot, relative to the upper-left corner of the cursor bitmap.

### `cx`

Type: **int**

The width, in pixels, of the cursor.

### `cy`

Type: **int**

The height, in pixels, of the cursor.

### `cbWidth`

Type: **int**

The width, in bytes, of the cursor bitmap.

### `Planes`

Type: **BYTE**

The number of color planes.

### `BitsPixel`

Type: **BYTE**

The number of bits used to indicate the color of a single pixel in the cursor.

## Remarks

When an application passes a cursor handle to the [LockResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-lockresource) function, the function returns a pointer to a buffer containing information about the cursor. An application can use the **CURSORSHAPE** structure to access the information.

## See also

**Conceptual**

[LockResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-lockresource)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)