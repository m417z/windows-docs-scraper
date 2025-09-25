# GetBoundsRect function

## Description

The **GetBoundsRect** function obtains the current accumulated bounding rectangle for a specified device context.

The system maintains an accumulated bounding rectangle for each application. An application can retrieve and set this rectangle.

## Parameters

### `hdc` [in]

A handle to the device context whose bounding rectangle the function will return.

### `lprect` [out]

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that will receive the current bounding rectangle. The application's rectangle is returned in logical coordinates, and the bounding rectangle is returned in screen coordinates.

### `flags` [in]

Specifies how the **GetBoundsRect** function will behave. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **DCB_RESET** | Clears the bounding rectangle after returning it. If this flag is not set, the bounding rectangle will not be cleared. |

## Return value

The return value specifies the state of the accumulated bounding rectangle; it can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | An error occurred. The specified device context handle is invalid. |
| DCB_DISABLE | Boundary accumulation is off. |
| DCB_ENABLE | Boundary accumulation is on. |
| DCB_RESET | The bounding rectangle is empty. |
| DCB_SET | The bounding rectangle is not empty. |

## Remarks

The DCB_SET value is a combination of the bit values DCB_ACCUMULATE and DCB_RESET. Applications that check the DCB_RESET bit to determine whether the bounding rectangle is empty must also check the DCB_ACCUMULATE bit. The bounding rectangle is empty only if the DCB_RESET bit is 1 and the DCB_ACCUMULATE bit is 0.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetBoundsRect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setboundsrect)