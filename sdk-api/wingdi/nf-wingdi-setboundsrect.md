# SetBoundsRect function

## Description

The **SetBoundsRect** function controls the accumulation of bounding rectangle information for the specified device context. The system can maintain a bounding rectangle for all drawing operations. An application can examine and set this rectangle. The drawing boundaries are useful for invalidating bitmap caches.

## Parameters

### `hdc` [in]

A handle to the device context for which to accumulate bounding rectangles.

### `lprect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure used to set the bounding rectangle. Rectangle dimensions are in logical coordinates. This parameter can be **NULL**.

### `flags` [in]

Specifies how the new rectangle will be combined with the accumulated rectangle. This parameter can be one of more of the following values.

| Value | Meaning |
| --- | --- |
| **DCB_ACCUMULATE** | Adds the rectangle specified by the *lprcBounds* parameter to the bounding rectangle (using a rectangle union operation). Using both DCB_RESET and DCB_ACCUMULATE sets the bounding rectangle to the rectangle specified by the *lprcBounds* parameter. |
| **DCB_DISABLE** | Turns off boundary accumulation. |
| **DCB_ENABLE** | Turns on boundary accumulation, which is disabled by default. |
| **DCB_RESET** | Clears the bounding rectangle. |

## Return value

If the function succeeds, the return value specifies the previous state of the bounding rectangle. This state can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| DCB_DISABLE | Boundary accumulation is off. |
| DCB_ENABLE | Boundary accumulation is on. DCB_ENABLE and DCB_DISABLE are mutually exclusive. |
| DCB_RESET | Bounding rectangle is empty. |
| DCB_SET | Bounding rectangle is not empty. DCB_SET and DCB_RESET are mutually exclusive. |

If the function fails, the return value is zero.

## Remarks

The DCB_SET value is a combination of the bit values DCB_ACCUMULATE and DCB_RESET. Applications that check the DCB_RESET bit to determine whether the bounding rectangle is empty must also check the DCB_ACCUMULATE bit. The bounding rectangle is empty only if the DCB_RESET bit is 1 and the DCB_ACCUMULATE bit is 0.

## See also

[GetBoundsRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getboundsrect)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)